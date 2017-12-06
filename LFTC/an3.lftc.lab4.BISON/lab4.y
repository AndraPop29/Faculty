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

%%

program : includs usage main
includs : include | includs
include : INCLUDE '<' IDENTIFICATOR '>'

usage: USING NAMESPACE IDENTIFICATOR ';'

main: INT MAIN '(){' stmt_list RETURN '0;}'

stmt_list: stmt | stmt stmt_list

stmt : decl ';' | assign ';'| input ';'| loop | output ';' | conditional

decl: type ids

ids ::= IDENTIFICATOR | IDENTIFICATOR ',' ids

type: INT | DOUBLE | struct

struct: 'struct' IDENTIFICATOR '{' decl '}'

var: IDENTIFICATOR | IDENTIFICATOR '.' var

assign: var assignOP expr | var unaryOP | unaryOP var

assignOP : ASSIGN
unaryOP : '--' | '++'
expr : var unaryOP | unaryOP var | var op var | idConst op var op var
op : '+' | '-' | '*' | '/' | '%'

loop ::= 'for('init ';' conditions ';' increment ')' block

init ::= "" | decl assignOP idConst | decl assignOP id
conditions ::= "" | cond | cond logicalOP conditions
cond ::= var condOP var
condOP ::= EQ | LT | LE | GT | GE | NEQ
logicalOP ::= AND
increment ::= "" | expr | assign

block ::= '{' stmtList '}'

input ::= CIN '>>' var ';'
output ::= COUT '<<' var ';'
str ::= strChar | strChar str | var
strChar ::= 'a' | ... | "z" (toate caracterele)

<conditional> ::= 'if(' conditions ')' block

//listaInstructiuni: instructiune | instructiune listaInstructiuni
//
//instructiune: atribuire | io | if | while | for | call
//
//atribuire: IDENTIFICATOR ASSIGN expresie
//
//expresie: term | expresie '+' term | expresie '-' term
//
//term: factor | factor '*' term | factor '/' term |factor '%' term
//
//factor: CONSTANT | IDENTIFICATOR | identifCompus | '(' expresie ')'
//
//identifCompus: IDENTIFICATOR '[' chestie ']'
//
//chestie: IDENTIFICATOR | CONSTANT
//
//io: READ '(' IDENTIFICATOR ')' | READ '(' identifCompus ')' | WRITE '(' IDENTIFICATOR ')' |  WRITE '(' identifCompus ')'
//
//if: IF conditie '{' listaInstructiuni '}' | IF conditie '{' listaInstructiuni '}' ELSE '{' listaInstructiuni '}'
//
//conditie: expresie relatie expresie
//
//relatie: LE | LT | GE | GT | EQ | NEQ
//
//while: WHILE conditie '{' listaInstructiuni '}'
//
//for: FOR ':' IDENTIFICATOR ASSIGN chestie ',' chestie '{' listaInstructiuni '}' | FOR ':' IDENTIFICATOR ASSIGN chestie ',' chestie ',' chestie '{' listaInstructiuni '}'
//
//call: CALL ':' IDENTIFICATOR '(' listaParam ')'
//
//listaParam:  IDENTIFICATOR ':' type | expresie ':' type | IDENTIFICATOR ':' type listaParam | expresie ':' type listaParam
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