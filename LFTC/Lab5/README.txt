flex lab4.lx
bison -d lab4.y
gcc lex.yy.c lab4.tab.c
./a.exe ["1.txt"|"2.txt"|"3.txt"]