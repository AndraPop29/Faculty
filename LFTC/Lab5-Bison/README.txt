flex lab4.lx
bison -d lab4.y
gcc lex.yy.c lab4.tab.c
./a.exe ["sum.txt"]