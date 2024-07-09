.SILENT:

CC = gcc
CFLAGS = -lfl

OUT = a.out
PAR = ${subst .y,.tab.c,${BIS}}
HEAD = ${subst .y,.tab.h,${BIS}}

FLX = lexer.l
BIS = parser.y

.PHONY: all
all: clean ${PAR} lex.yy.c ${OUT}

.PHONY: flex
flex: lex.yy.c

.PHONY: bison
bison: ${PAR}

.PHONY: test
test:
	echo ${OUT} ${BIS} ${PAR} ${FLX} ${HEAD}

lex.yy.c: ${FLX}
	flex ${FLX}

${PAR}: ${BIS}
	bison -d ${BIS}

${OUT}: lex.yy.c
	${CC} ${CFLAGS} lex.yy.c ${PAR} list.c hashing.c -o ${OUT} -lm

.PHONY: clean
clean:
	rm -f lex.yy.c ${OUT} ${PAR} ${HEAD}
