# 8BitCompiler
 8 Bit version of my previous compiler
 # Additions
 + More readable code
 + Functions IndexNums and Interpret
 + Memory efficient functions
 + More switches less ifs (even with strings!)
 + Better error detection

 # How to compile
 run 
 
 ```
 g++  -o "compiler" ./Src/Main.o ./Src/TextProcessing.o
 ```
 
 I know this probably isn't the best, but this is just what eclipse tells me :P
 
 # How to use
 install the program however you would like (I install to /bin) and then run it with the following syntax
 
 ```
 compiler SourceFile.txt OutputFile.txt
 ```