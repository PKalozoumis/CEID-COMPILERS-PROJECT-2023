%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <inttypes.h>
    #include "parser.tab.h"

    #include "error.h"

    uint32_t line_number = 1;
    int eof_comment = 0;
    int bad_comment = 0;

    extern enum error err_type;
%}

%x ST_STRING
%x ST_COMMENT

P_INTEGER [-+]?[0-9]+
P_STRING [A-Za-z0-9_]+

%%

"<!--" { BEGIN(ST_COMMENT); }

<ST_COMMENT>{
    \r\n|\n|\r {line_number++;}
    [^-\n\r]* {}
    "--"[^>] {err_type = ERR_BAD_COMMENT; return 0;}
    "-"[^-] {}
    "-->" { BEGIN(INITIAL); }
    <<EOF>> {err_type = ERR_EOF_COMMENT; BEGIN(INITIAL); }
}

"LinearLayout" { ECHO; return STR_LINEAR_LAYOUT; }
"RelativeLayout" { ECHO; return STR_RELATIVE_LAYOUT; }
"TextView" { ECHO; return STR_TEXT_VIEW; }
"ImageView" { ECHO; return STR_IMAGE_VIEW; }
"Button" { ECHO; return STR_BUTTON; }
"RadioButton" { ECHO; return STR_RADIO_BUTTON; }
"RadioGroup" { ECHO; return STR_RADIO_GROUP; }
"ProgressBar" { ECHO; return STR_PROGRESS_BAR; }

"android" { ECHO; return STR_ANDROID; }

"layout_width" { ECHO; return STR_ATTR_WIDTH; }
"layout_height" { ECHO; return STR_ATTR_HEIGHT; }
"id" { ECHO; return STR_ATTR_ID; }
"orientation" { ECHO; return STR_ATTR_ORIENT; }
"text" { ECHO; return STR_ATTR_TEXT; }
"textColor" { ECHO; return STR_ATTR_TEXTCOLOR; }
"src" { ECHO; return STR_ATTR_SRC; }
"padding" { ECHO; return STR_ATTR_PADDING; }
"checkedButton" { ECHO; return STR_ATTR_CHECKED; }
"max" { ECHO; return STR_ATTR_MAX; }
"progress" { ECHO; return STR_ATTR_PROGRESS; }
"count" { ECHO; return STR_ATTR_COUNT; }

<INITIAL,ST_STRING>{  
{P_INTEGER} {ECHO; yylval.int_val = atoi(yytext); return INTEGER; }
{P_STRING} {ECHO; yylval.str_val = strdup(yytext); return STRING; }
}


\< { ECHO; return '<'; }
> { ECHO; return '>'; }
\/ { ECHO; return '/'; }
\" { ECHO; BEGIN(ST_STRING); return '"'; }
: { ECHO; return ':'; }
= { ECHO; return '='; }

<ST_STRING>\" { ECHO; BEGIN(INITIAL); return '"'; }

\r\n|\n|\r {ECHO; line_number++;}
[ \t]+ {ECHO;}
<INITIAL,ST_STRING>. { ECHO; return yytext[0]; }

%%