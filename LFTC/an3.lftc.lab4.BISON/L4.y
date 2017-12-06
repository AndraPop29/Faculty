%{
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>

    extern int yylex();
    extern int yyparse();
    extern FILE *yyin;
    extern int nrLine;
    extern void afisare();
    void yyerror(const char *s);
%}

%token CITIRESCAN
%token SCANNEXTFLOAT
%token SCANNEXTINT
%token SYSTEMOUTPRINTLN
%token CONST
%token ID
%token FLOAT
%token INT
%token FLARRAY
%token EQ
%token NEQ
%token IF
%token WHILE
%token ELSE
%token PUBLICSTATICVOIDCERC
%token PUBLICSTATICVOIDCMMDC
%token PUBLICSTATICVOIDSUMA
%token INIT
%token DOUBLE
%token OR
%token GT
%token LT
%token LE
%token ASSIGN
%token RETURN
%token MAIN
       
%%     

program: MAIN '(' ')' '{' lista_subprograme '}'

lista_subprograme: subprogram 
                | subprogram lista_subprograme

subprogram: antet '{' bloc_var instructiuni_compuse '}'

antet: PUBLICSTATICVOIDCERC
    | PUBLICSTATICVOIDCMMDC
    | PUBLICSTATICVOIDSUMA

bloc_var: declarare_var ';' | declarare_var ';' bloc_var

declarare_var: tip lista_identif

tip: FLOAT | DOUBLE | INT | FLARRAY
    
lista_identif: ID | ID ',' lista_identif 
            | ID ASSIGN CONST
            | ID ASSIGN INIT

instructiuni_compuse: instructiune_compusa
                | instructiune_compusa instructiuni_compuse

instructiune_compusa: instr_intrare 
                    | instr_atribuire 
                    | instr_iesire
                    | instr_selectie
                    | instr_ciclare

instr_intrare: CITIRESCAN ';'

instr_iesire: SYSTEMOUTPRINTLN '(' ID ')' ';'

instr_atribuire: ID ASSIGN intrare ';'
            | ID ASSIGN expresie ';'
            | ID ASSIGN ID ';'
            | ID ASSIGN CONST ';'
            | ID '[' ID ']' ASSIGN intrare ';'

intrare: SCANNEXTFLOAT | SCANNEXTINT

expresie: CONST op ID op ID
        | CONST op CONST op ID
        | ID op ID
        | ID op CONST
        | ID op ID '[' ID ']'

op: '+' | '-' | '*'

instr_selectie: IF '(' conditie ')' RETURN ';'
| IF '(' conditie ')' instr_atribuire ELSE instr_atribuire

conditie: ID LT CONST OR ID LT CONST
        | ID NEQ ID
        | ID GT ID
        | ID LE ID

instr_ciclare: WHILE '(' conditie ')' '{' bloc_ciclare '}'

bloc_ciclare: instr_selectie
            | instructiuni_atribuire

instructiuni_atribuire: instr_atribuire |
    instr_atribuire instructiuni_atribuire

                    
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