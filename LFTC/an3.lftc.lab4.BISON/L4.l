%{		
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "L4.tab.h"

typedef struct{
    int id1;
    int id2;
    }FIP;

typedef struct{
    char nume[10];
}TSiden;

int lungFip=0;
int lungConst = 0;
int lungIdentif = 0;
FIP program[300];

TSiden TSidentif[30];

float TSconstante[30];

int nrLine = 1;

void addFip(int id1 , int id2){
    program[lungFip].id1 = id1;
    program[lungFip].id2 = id2;
    lungFip++;
}

void addConst(float atom){
    int gasit = 0 ;
    for(int i = 0;i<lungConst;i++){
        if (TSconstante[i] == atom){
            gasit =1;
            addFip(4,i);
        }
    }
    if (gasit == 0){
        TSconstante[lungConst]=atom;
        addFip(4,lungConst);
        lungConst++;
    }

}

void addIdentif(char* atom){
    int gasit = 0 ;
     int i= 0;
     
    while(i<lungIdentif){
        int rez = strcmp(TSidentif[i].nume,atom);
        if(strcmp(TSidentif[i].nume,atom)==0){
            gasit =1;
            addFip(5,i);
        }
        i++;
    }

    if (gasit == 0){
        strcpy(TSidentif[lungIdentif].nume,atom);
        addFip(5,lungIdentif);
        lungIdentif++;   
    }
}

void afisareFip(){

    for(int t=0;t<lungFip;t++){
        printf(" %d|%d ",program[t].id1,program[t].id2);
        if(program[t].id1 == 15)
            printf("\n");
    }
}

void afisareConst(){

    for(int i = 0 ;i<lungConst;i++)
        printf(" %f|%d", TSconstante[i] , i);
    printf("\n");
}

void afisareId(){
    for(int i = 0 ;i<lungIdentif;i++)
        printf(" %s|%d", TSidentif[i].nume , i);
    printf("\n");
}

void afisare(){
    printf("\n");
    printf("________________________________________________________________________________\n");
    printf("|******************************************************************************|\n");
    printf("|                                     TS                                       |\n");
    printf("|******************************************************************************|\n");
    printf("|                                 Constante                                    |\n");
    afisareConst();
    printf("|******************************************************************************|\n");
    printf("|                               Identificatori                                 |\n");
    afisareId();
    printf("________________________________________________________________________________\n");
    printf("|******************************************************************************|\n");
    printf("|                                    FIP                                       |\n");
    printf("|******************************************************************************|\n");
    afisareFip();
    printf("\n");
    printf("|______________________________________________________________________________|\n");

}

%} 

%option noyywrap
DIGIT 		[0-9] 
DIGITNENUL		[1-9]
ID      [a-z][a-z0-9]*

%%
"0"                                     {addConst(atoi( yytext )); return CONST; }
{DIGITNENUL}                            {addConst(atoi( yytext )); return CONST; }
{DIGITNENUL}{DIGIT}+                    {addConst(atoi( yytext )); return CONST; }
{DIGITNENUL}{DIGIT}+"."{DIGIT}*         {addConst(atof( yytext )); return CONST; }
"0""."{DIGIT}*                          {addConst(atof( yytext )); return CONST; }
{DIGITNENUL}"."{DIGIT}*                 {addConst(atof( yytext )); return CONST; }

\citireScan                             { addFip(0,0); return CITIRESCAN; } 
\scan.nextFloat                         { addFip(1,0); return SCANNEXTFLOAT; }
\scan.nextInt                           { addFip(2,0); return SCANNEXTINT; }
\System.out.println                     { addFip(3,0); return SYSTEMOUTPRINTLN; }
\const                                  { addFip(4,0); return CONST; }
\id                                     { addFip(5,0); return ID; }
float                                   { addFip(6,0); return FLOAT; }
\int                                    { addFip(7,0); return INT; }
fl_array                                { addFip(8,0); return FLARRAY; }
\=                                      { addFip(9,0); return ASSIGN; } 
\+                                      { addFip(10,0); return '+'; }
\*                                      { addFip(11,0); return '*'; }
\!=                                     { addFip(12,0); return NEQ; }
\{                                      { addFip(13,0); return '{'; }
\}                                      { addFip(14,0); return '}'; }
\;                                      { addFip(15,0); return ';'; }
\,                                      { addFip(16,0); return ','; }
\-                                      { addFip(17,0); return '-'; }
\if                                     { addFip(18,0); return IF; }
\while                                  { addFip(19,0); return WHILE; }
\else                                   { addFip(20,0); return ELSE; }
\(                                      { addFip(21,0); return '('; }
\)                                      { addFip(22,0); return ')'; }
\]                                      { addFip(23,0); return ']'; }
\public_static_void_cerc                { addFip(24,0); return PUBLICSTATICVOIDCERC; }
\public_static_void_cmmdc               { addFip(25,0); return PUBLICSTATICVOIDCMMDC; }
\public_static_void_suma                { addFip(26,0); return PUBLICSTATICVOIDSUMA; }
\init                                   { addFip(27,0); return INIT; }
return                                  { addFip(28,0); return RETURN; }
\double                                 { addFip(29,0); return DOUBLE; }
\or                                     { addFip(30,0); return OR; }
\>                                      { addFip(31,0); return GT; }
\<                                      { addFip(32,0); return LT; }
\<=                                     { addFip(33,0); return LE;}
\[                                      { addFip(34,0); return '['; }
main                                    { addFip(35,0); return MAIN; }
{ID}                                    { addIdentif( yytext); return ID;}
[ \t]+                                  /* eat up whitespace */ 
[\n\r]                                  ++nrLine;
.                       {   printf("|******************************************************************************|\n");
                        printf( "\n\n!!!!!! Eroare chr.: %s nu poate fii gasit!!!!!\n", yytext );}
%% 
