# php-compiler
This is a repository for a Compiler built using the FLEX tool. The compiler is built for the PHP language, and handles all basics of the PHP language. It also includes functionality for the while and the switch construct. Nested constructs are allowed, along with all kinds of permissible PHP expressions. The complete permissible grammar is detailed in the 'Grammar_PHP.docx' file. 

## Note
- For loops and do-while loops are not defined. 
- The script will have to include <?php as the starting block and ?> as the ending block.
- Lex and YACC compilers are a prerequisite. 
- n9gramopt.y is the optimized version. Optimizations - 1. Copy Propogate 2. Constant Evaluation

## Execution Instructions
1. Compile the .l file using 'lex newgram.l'
2. Compile the .y file using 'yacc -d n9gramunopt.y'
3. Compile the two using 'gcc -ll -lm y.tab.c lex.yy.c'
4. Run the executable file using './a.out'
