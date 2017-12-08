%{
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>

    extern int yylex();
    extern int yyparse();
    extern FILE *yyin;
    extern int nrLine;
    void yyerror(const char *s);
%}

%token IDENTIFICATOR
%token CONSTANT
%token USING
%token NAMESPACE
%token INCLUDE
%token MAIN
%token ENDL
%token IF
%token ELSE
%token FOR
%token WHILE
%token INT
%token COUT
%token CIN
%token STRUCT
%token DOUBLE
%token RETURN
%token GT
%token LT
%token GE
%token LE
%token ASSIGN
%token NEQ
%token EQ
%token AND
%token IN
%token OUT
%token PLUS

%%

program: includs usage main
includs: include | include includs
include: INCLUDE LT IDENTIFICATOR GT

usage: USING NAMESPACE IDENTIFICATOR ';'

main: INT MAIN '('')''{' stmt_list RETURN CONSTANT';''}'

stmt_list: stmt | stmt stmt_list

stmt: decl ';' | assign ';'| input ';'| loop | output ';' | conditional

decl: type ids | ids

ids: IDENTIFICATOR | IDENTIFICATOR ',' ids

type: INT | DOUBLE | struct

struct: STRUCT IDENTIFICATOR '{' decl ';' '}'

var: IDENTIFICATOR | IDENTIFICATOR'.'var | type IDENTIFICATOR

assign: var assignOP expr | var unaryOP | unaryOP var |

assignOP: ASSIGN
unaryOP: '-''-' | '+''+'
expr: var unaryOP | unaryOP var | var | expr op expr | CONSTANT
op: PLUS | '-' | '*' | '/' | '%'

loop: FOR '(' init ';' conditions ';' increment ')' block

init: decl assignOP CONSTANT | decl assignOP IDENTIFICATOR
conditions: cond | cond logicalOP conditions
cond: var condOP var | expr condOP CONSTANT
condOP: EQ | LT | LE | GT | GE | NEQ
logicalOP: AND
increment: expr | assign

block: '{' stmt_list '}'

input: CIN IN var
output: COUT OUT var

conditional: IF '(' conditions ')' block


%%

int main(int argc, char *argv[]) {
    ++argv, --argc; /* skip over program name */ 
    
    // sets the input for flex file
    if (argc > 0) 
        yyin = fopen(argv[0], "r"); 
    else 
        yyin = stdin; 
    
    //read each line from the input file and process it
    while (!feof(yyin)) {
        yyparse();
    }
    printf("The file is sintactly correct!\n");
    return 0;
}

void yyerror(const char *s) {
    printf("Error: %s at line -> %d ! \n", s, nrLine);
    exit(1);
}
