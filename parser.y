%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <inttypes.h>
    #include <math.h>

    #include <string.h>
    
    #include "hashing.h"
    #include "error.h"

    void yyerror(const char*);
    int check_for_required_attributes(const char* elem, uint16_t attr, uint16_t req);

    extern FILE* yyin;
    extern FILE* yyout;
    extern char* yytext;

    extern int yylex();

    extern uint32_t line_number;
    extern int eof_comment;
    extern int bad_comment;
    
    enum error err_type = ERR_SYNTAX;

    enum attr
    {
        ATTR_WIDTH = 1,
        ATTR_HEIGHT = 1 << 1,
        ATTR_ID = 1 << 2,
        ATTR_ORIENT = 1 << 3,
        ATTR_TEXT = 1 << 4,
        ATTR_TEXTCOLOR = 1 << 5,
        ATTR_SRC = 1 << 6,
        ATTR_PADDING = 1 << 7,
        ATTR_CHECKED = 1 << 8,
        ATTR_MAX = 1 << 9,
        ATTR_PROGRESS = 1 << 10,
        ATTR_COUNT = 1 << 11
    };

    char* decode_attr[12] =
    {
        "layout_width", "layout_height", "id", "orientation", "text", "textColor", "src",
        "padding", "checkedButton", "max", "progress", "count"
    };

    uint32_t duplicate_attr_mask = 0;
    int attr_val_max = -1;
    int attr_val_progress = -1;
    int attr_val_count = -1;

    //The value of attribute "checkedButton" inside the current RadioGroup body
    //Used along with found_id to check if one the embedded radio buttons has an id that's equal to this value
    //A value of NULL indicates a nonexistent checkedButton attribute, so no checks need to be performed
    //Needs to be reset after the final check (for the value of found_id) is performed
    char* attr_val_checked = NULL;
    int found_id = 0;

    int button_count = 0;

    List* hashTable = NULL;
%}

%union
{
    uint32_t uint_val;
    int int_val;
    char* str_val;
}

%token STR_LINEAR_LAYOUT "LinearLayout"
%token STR_RELATIVE_LAYOUT "RelativeLayout"
%token STR_TEXT_VIEW "TextView"
%token STR_IMAGE_VIEW "ImageView"
%token STR_BUTTON "Button"
%token STR_RADIO_BUTTON "RadioButton"
%token STR_RADIO_GROUP "RadioGroup"
%token STR_PROGRESS_BAR "ProgressBar"

%token STR_ANDROID "android"

%token STR_ATTR_WIDTH "layout_width"
%token STR_ATTR_HEIGHT "layout_height"
%token STR_ATTR_ID "id"
%token STR_ATTR_ORIENT "orientation"
%token STR_ATTR_TEXT "text"
%token STR_ATTR_TEXTCOLOR "textColor"
%token STR_ATTR_SRC "src"
%token STR_ATTR_PADDING "padding"
%token STR_ATTR_CHECKED "checkedButton"
%token STR_ATTR_MAX "max"
%token STR_ATTR_PROGRESS "progress"
%token STR_ATTR_COUNT "count"

%token <str_val> STRING 
%token <int_val> INTEGER

%type <uint_val> req_attr

%type <uint_val> linear_attr_list
%type <uint_val> linear_attr

%type <uint_val> relative_attr_list
%type <uint_val> relative_attr

%type <uint_val> text_view_attr_list
%type <uint_val> text_view_attr

%type <uint_val> image_view_attr_list
%type <uint_val> image_view_attr

%type <uint_val> button_attr_list
%type <uint_val> button_attr

%type <uint_val> radio_button_attr_list
%type <uint_val> radio_button_attr

%type <uint_val> radio_group_attr_list
%type <uint_val> radio_group_attr

%type <uint_val> progress_bar_attr_list
%type <uint_val> progress_bar_attr

%type <int_val> attr_max
%type <int_val> attr_progress
%type <int_val> attr_count
%type <str_val> attr_id
%type <str_val> attr_checked

%%
start: linear_layout | relative_layout

self_close: '/' '>'

//Attributes
//==============================================================================================================

attr_orient: "orientation" '=' '"' STRING '"' { free($4); /*for now*/ }

attr_id: "id" '=' '"' STRING '"'
{
    if (insert(hashTable, $4))
    {
        char str[256];
        sprintf(str, "Value \"%s\" already exists for ID", $4);
        err_type = ERR_OTHER;
        yyerror(str);
        YYABORT;
    }

    //BE CAREFUL NOT TO FREE THIS
    //OWNERSHIP IS NOT TRANSFERRED TO HASH TABLE
    //BUT THE HASH TABLE IS STILL RESPONSIBLE FOR FREEING IT AFTER EVERYTHING IS OVER
    $$ = $4;
}

attr_text: "text" '=' '"' STRING '"' { free($4); /*for now*/ }

attr_textcolor: "textColor" '=' '"' STRING '"' { free($4); /*for now*/ }

attr_src: "src" '=' '"' STRING '"' { free($4); /*for now*/ }

attr_padding: "padding" '=' '"' INTEGER '"'
{
    if ($4 <= 0)
    {
        err_type = ERR_OTHER;
        yyerror("Attribute \"padding\" must have a positive value");
        YYABORT;
    }
}

attr_checked: "checkedButton" '=' '"' STRING '"' { $$ = $4; }

attr_max: "max" '=' '"' INTEGER '"'
{
    if ($4 <= 0)
    {
        err_type = ERR_OTHER;
        yyerror("Attribute \"max\" must have a positive value");
        YYABORT;
    }

    $$ = $4;
}

attr_progress: "progress" '=' '"' INTEGER '"'
{
    if ($4 < 0)
    {
        err_type = ERR_OTHER;
        yyerror("Attribute \"progress\" cannot have a negative value");
        YYABORT;
    }

    $$ = $4;
}

attr_count: "count" '=' '"' INTEGER '"'
{
    if ($4 <= 0)
    {
        err_type = ERR_OTHER;
        char* str = "Attribute \"count\" must have a positive value";
        yyerror(str);
        YYABORT;
    }

    $$ = $4;
}

req_attr: attr_width { $$ = ATTR_WIDTH; }
        | attr_height { $$ = ATTR_HEIGHT; }

attr_width: "layout_width" '=' '"' attr_width_val '"'
attr_width_val: INTEGER
{
    if ($1 <= 0)
    {
        err_type = ERR_OTHER;
        char str[512];
        sprintf(str, "Attribute layout_width must have a positive value (got %d)", $1);
        yyerror(str);

        YYABORT;
    }
}
| STRING
{
    if ((strcmp($1, "match_parent") != 0)&&(strcmp($1, "wrap_content") != 0))
    {
        err_type = ERR_OTHER;
        char str[512];
        sprintf(str, "Incorrect value \"%s\" for attribute layout_width, should be \"wrap_content\", \"match_parent\" or a positive integer", $1);
        free($1);
        yyerror(str);

        YYABORT;
    }
}

attr_height: "layout_height" '=' '"' attr_height_val '"'
attr_height_val: INTEGER
{
    if ($1 <= 0)
    {
        err_type = ERR_OTHER;
        char str[512];
        sprintf(str, "Attribute layout_height must have a positive value (got %d)", $1);
        yyerror(str);

        YYABORT;
    }
}
| STRING
{
    if ((strcmp($1, "match_parent") != 0)&&(strcmp($1, "wrap_content") != 0))
    {
        err_type = ERR_OTHER;
        char str[512];
        sprintf(str, "Incorrect value \"%s\" for attribute layout_height, should be \"wrap_content\", \"match_parent\" or a positive integer", $1);
        free($1);
        yyerror(str);

        YYABORT;
    }
}

//LinearLayout
//==============================================================================================================

linear_layout: '<' "LinearLayout" linear_attr_top '>' linear_body '<' '/' "LinearLayout" '>'

linear_attr_top: linear_attr_list
{
    if (!check_for_required_attributes("LinearLayout", $1, ATTR_WIDTH | ATTR_HEIGHT))
        YYABORT;
}

linear_attr_list: linear_attr_list "android" ':' linear_attr
{
    duplicate_attr_mask = $1 & $4;

    if (duplicate_attr_mask)
    {
        err_type = ERR_DUPLICATE_ATTR;
        yyerror("Duplicate attributes");
        YYABORT;
    }
    else $$ = $1 | $4;
}
| %empty { $$ = 0; }

linear_attr:
req_attr { $$ = $1; }|
attr_id { $$ = ATTR_ID; }|
attr_orient { $$ = ATTR_ORIENT; }

linear_body: linear_body linear_body_options | linear_body_options

linear_body_options: linear_layout | relative_layout | text_view | image_view | button | radio_group | progress_bar

//RelativeLayout
//==============================================================================================================
relative_layout: '<' "RelativeLayout" relative_attr_top relative_close

relative_close: self_close | '>' relative_body '<' '/' "RelativeLayout" '>'

relative_attr_top: relative_attr_list
{
    if (!check_for_required_attributes("RelativeLayout", $1, ATTR_WIDTH | ATTR_HEIGHT))
        YYABORT;
}

relative_attr_list: relative_attr_list "android" ':' relative_attr
{
    duplicate_attr_mask = $1 & $4;

    if (duplicate_attr_mask)
    {
        err_type = ERR_DUPLICATE_ATTR;
        yyerror("Duplicate attributes");
        YYABORT;
    }
    else $$ = $1 | $4;
}
| %empty { $$ = 0; }

relative_attr:
req_attr { $$ = $1; }|
attr_id { $$ = ATTR_ID; }

relative_body: relative_body relative_body_options | %empty

relative_body_options: linear_layout | relative_layout | text_view | image_view | button | radio_group | progress_bar

//TextView
//==============================================================================================================
text_view: '<' "TextView" text_view_attr_top text_view_close

text_view_close: self_close | '>' '<' '/' "TextView" '>'

text_view_attr_top: text_view_attr_list
{
    if (!check_for_required_attributes("TextView", $1, ATTR_WIDTH | ATTR_HEIGHT | ATTR_TEXT))
        YYABORT;
}

text_view_attr_list: text_view_attr_list "android" ':' text_view_attr
{
    duplicate_attr_mask = $1 & $4;

    if (duplicate_attr_mask)
    {
        err_type = ERR_DUPLICATE_ATTR;
        yyerror("Duplicate attributes");
        YYABORT;
    }
    else $$ = $1 | $4;
}
| %empty { $$ = 0; }

text_view_attr:
req_attr { $$ = $1; }|
attr_id { $$ = ATTR_ID; }|
attr_text { $$ = ATTR_TEXT; }|
attr_textcolor { $$ = ATTR_TEXTCOLOR; }

//ImageView
//==============================================================================================================
image_view: '<' "ImageView" image_view_attr_top image_view_close

image_view_close: self_close | '>' '<' '/' "ImageView" '>'

image_view_attr_top: image_view_attr_list
{
    if (!check_for_required_attributes("ImageView", $1, ATTR_WIDTH | ATTR_HEIGHT | ATTR_SRC))
        YYABORT;
}

image_view_attr_list: image_view_attr_list "android" ':' image_view_attr
{
    duplicate_attr_mask = $1 & $4;

    if (duplicate_attr_mask)
    {
        err_type = ERR_DUPLICATE_ATTR;
        yyerror("Duplicate attributes");
        YYABORT;
    }
    else $$ = $1 | $4;
}
| %empty { $$ = 0; }

image_view_attr:
req_attr { $$ = $1; }|
attr_id { $$ = ATTR_ID; }|
attr_padding { $$ = ATTR_PADDING; }|
attr_src { $$ = ATTR_SRC; }

//Button
//==============================================================================================================
button: '<' "Button" button_attr_top button_close

button_close: self_close | '>' '<' '/' "Button" '>'

button_attr_top: button_attr_list
{
    if (!check_for_required_attributes("Button", $1, ATTR_WIDTH | ATTR_HEIGHT | ATTR_TEXT))
        YYABORT;
}

button_attr_list: button_attr_list "android" ':' button_attr
{
    duplicate_attr_mask = $1 & $4;

    if (duplicate_attr_mask)
    {
        err_type = ERR_DUPLICATE_ATTR;
        yyerror("Duplicate attributes");
        YYABORT;
    }
    else $$ = $1 | $4;
}
| %empty { $$ = 0; }

button_attr:
req_attr { $$ = $1; }|
attr_id { $$ = ATTR_ID; }|
attr_padding { $$ = ATTR_PADDING; }|
attr_text { $$ = ATTR_TEXT; }

//RadioButton
//==============================================================================================================
radio_button: '<' "RadioButton" radio_button_attr_top radio_button_close { button_count++; }

radio_button_close: self_close | '>' '<' '/' "RadioButton" '>'

radio_button_attr_top: radio_button_attr_list
{
    if (!check_for_required_attributes("RadioButton", $1, ATTR_WIDTH | ATTR_HEIGHT | ATTR_TEXT))
        YYABORT;
}

radio_button_attr_list: radio_button_attr_list "android" ':' radio_button_attr
{
    duplicate_attr_mask = $1 & $4;

    if (duplicate_attr_mask)
    {
        err_type = ERR_DUPLICATE_ATTR;
        yyerror("Duplicate attributes");
        YYABORT;
    }
    else $$ = $1 | $4;
}
| %empty { $$ = 0; }

radio_button_attr:
req_attr { $$ = $1; }|
attr_id
{
    $$ = ATTR_ID;

    if (attr_val_checked)
    {
        if (strcmp($1, attr_val_checked) == 0)
        {
            found_id = 1;
        }
    }
}|
attr_text { $$ = ATTR_TEXT; }

//RadioGroup
//==============================================================================================================
radio_group: '<' "RadioGroup" radio_group_attr_top '>' radio_group_body '<' '/' "RadioGroup" '>'
{
    //This is where we check if one of the radio buttons had the requested id

    if (attr_val_checked && !found_id)
    {
        err_type = ERR_OTHER;
        char str[256];
        snprintf(str, 256, "Value \"%s\" of checkedButton does not point to any of the contained RadioButton IDs", attr_val_checked);
        yyerror(str);
        YYABORT;
    }

    free(attr_val_checked);
    attr_val_checked = NULL;
    found_id = 0;

    //This is where we check for the number of buttons

    if (attr_val_count != button_count)
    {
        err_type = ERR_OTHER;
        char str[256];
        snprintf(str, 256, "Attribute \"count\" requests %d radio buttons, but there were %d", attr_val_count, button_count);
        yyerror(str);
        YYABORT;
    }

    button_count = 0;
    attr_val_count = -1; //Not necessary
}

radio_group_attr_top: radio_group_attr_list
{
    if (!check_for_required_attributes("RadioGroup", $1, ATTR_WIDTH | ATTR_HEIGHT | ATTR_COUNT))
        YYABORT;
}

radio_group_attr_list: radio_group_attr_list "android" ':' radio_group_attr
{
    duplicate_attr_mask = $1 & $4;

    if (duplicate_attr_mask)
    {
        err_type = ERR_DUPLICATE_ATTR;
        yyerror("Duplicate attributes");
        YYABORT;
    }
    else $$ = $1 | $4;
}
| %empty { $$ = 0; }

radio_group_attr:
req_attr { $$ = $1; }|
attr_id { $$ = ATTR_ID; }|
attr_checked { $$ = ATTR_CHECKED; attr_val_checked = $1; /*freed at radio_group*/ }|
attr_count { $$ = ATTR_COUNT; attr_val_count = $1; }

radio_group_body: radio_group_body radio_group_body_options | radio_group_body_options

radio_group_body_options: radio_button

//ProgressBar
//==============================================================================================================
progress_bar: '<' "ProgressBar" progress_bar_attr_top progress_bar_close

progress_bar_close: self_close | '>' '<' '/' "ProgressBar" '>'

progress_bar_attr_top: progress_bar_attr_list
{
    if (!check_for_required_attributes("ProgressBar", $1, ATTR_WIDTH | ATTR_HEIGHT))
        YYABORT;

    if (($1 & ATTR_PROGRESS) != 0)
    {
        if (($1 & ATTR_MAX) == 0 )
        {
            err_type = ERR_OTHER;
            yyerror("Cannot have attrbute \"progress\" without attribute \"max\"");
            YYABORT;
        }
        else if (attr_val_progress >  attr_val_max)
        {
            err_type = ERR_OTHER;
            char str[256];
            snprintf(str, 256, "Value of progress (%d) must be between 0 and max (%d)", attr_val_progress, attr_val_max);
            yyerror(str);
            YYABORT;
        }
    }   
}

progress_bar_attr_list: progress_bar_attr_list "android" ':' progress_bar_attr
{
    duplicate_attr_mask = $1 & $4;

    if (duplicate_attr_mask)
    {
        err_type = ERR_DUPLICATE_ATTR;
        yyerror("Duplicate attributes");
        YYABORT;
    }
    else $$ = $1 | $4;
}
| %empty { $$ = 0; }

progress_bar_attr:
req_attr { $$ = $1; }|
attr_id { $$ = ATTR_ID; }|
attr_max { $$ = ATTR_MAX; attr_val_max = $1; }|
attr_progress { $$ = ATTR_PROGRESS; attr_val_progress = $1; }

%%

int main(int argc, char** argv)
{
    hashTable = createHashTable();
    FILE *fi = NULL, *fo = NULL;

    if (argc == 1)
    {
        printf("Please insert an input file\n");
        exit(EXIT_FAILURE);
    }
    else if (argc == 2)
    {
        //printf("Please insert an output file\n");
        //exit(EXIT_FAILURE);

        fo = stdout;
    }
    
    else if (argc > 3)
    {
        printf("Too many arguments\n");
        exit(EXIT_FAILURE);
    }

    if ((fi = fopen(argv[1], "r")) == NULL)
    {
        perror("INPUT ERROR");
        exit(EXIT_FAILURE);
    }

    if (argc == 3)
    {
        if ((fo = fopen(argv[2], "w")) == NULL)
        {
            perror("OUTPUT ERROR");
            exit(EXIT_FAILURE);
        }
    }

    yyin = fi;
    yyout = fo;

    printf("\nParsing %s...\n=============================================================================================================================\n\n", argv[1]);
    
    if (yyparse() == 0)
    {
        printf("\n\n=============================================================================================================================\n");
        printf("\nNo errors were encountered during the parsing process.\n");
    }

    printf("\n");

    //printHashTable(hashTable);

    fclose(fi);
    fclose(fo);
    freeHashTable(&hashTable);

    exit(EXIT_SUCCESS);
}

void yyerror(const char* str)
{
    printf("\n\n");
    printf("=============================================================================================================================\n\n");
    printf("ERROR at Line %d: ", line_number);

    switch(err_type)
    {
        case ERR_SYNTAX:
        {
            printf("Unexpected token \"%s\"\n", yytext);
        }
        break;

        case ERR_OTHER:
        {
            printf("%s\n", str);
        }
        break;

        case ERR_EOF_COMMENT:
        {
            printf("Comment reached end of file!\n");
        }
        break;

        case ERR_BAD_COMMENT:
        {
            printf("The string \"--\" is not allowed inside a comment!\n");
        }
        break;

        case ERR_DUPLICATE_ATTR:
        {
            //printf("log: %f\n", log2(duplicate_attr_mask));

            //We only check for one duplicate attribute at a time, even though there can be multiple.
            //The attribute with the biggest value in the enum has priority
            //Any other attributes have 1s in less significant bits, so the mask is a decimal number between the prioritized attribute's value and the next power of two
            //log2 is not an integer, but gets floored into one and gives us the prioritized attribute
            printf("Duplicate attribute %s\n", decode_attr[(int)(log2(duplicate_attr_mask))]);
        }
        break;
    }
}

int check_for_required_attributes(const char* elem, uint16_t attr, uint16_t req)
{
    int missing_count = 0;
    char missing_attr_str[256] = "\n\n * "; 

    for (int i = 0; req != 0; i++)
    {    
        //Only if we require a certain atrribute and that doesn't exist in the list, we throw error
        if ( ((req & 1) == 1) && ((attr & 1) == 0) )
        {
            if (missing_count == 0)
            {
                strcat(missing_attr_str, decode_attr[i]);
            }
            else
            {
                strcat(missing_attr_str, "\n\n * ");
                strcat(missing_attr_str, decode_attr[i]);
            }

            missing_count++;
        }

        attr = attr >> 1;
        req = req >> 1;
    }

    if (missing_count > 0)
    {
        char str[300] = "";

        snprintf(str, 300, "Missing %d required attribute%s for element %s: %s", missing_count, (missing_count > 1)?("s"):(""), elem, missing_attr_str);

        err_type = ERR_OTHER;
        yyerror(str);
        return 0;
    }
    
    return 1;
}
