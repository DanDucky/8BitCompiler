# 8BitCompiler
 8 Bit version of my previous compiler for my breadboard computer project
 
 The compiler compiles into 1 byte strings where some instructions span up to 2 lines of byte code
 # Additions
 + More readable code
 + Functions IndexNums and Interpret
 + Memory efficient functions
 + More switches less ifs (even with strings!)
 + Better error detection
 
 # How to use
 install the program however you would like (I install to /bin) and then run it with the following syntax
 
 ```
 compiler SourceFile.txt OutputFile.txt
 ```
 
  # Syntax
  The language has 4 instructions:
  ```
  MOVE
  DECL
  CLER
  GOTO
  ```
  + MOVE: Moves memory around and can either copy or cut depending on inputs
  + DECL: Declares an 8 bit string to a position in memory or cache
  + CLER: Clears one position in memory or cache
  + GOTO: repositions the instruction driver to read from a different position in memory or read only storage

  The lanuage has 3 different data storage types:
  ```
  MEMO
  CACH
  READ
  ```
  + MEMO: Memory, there are 32 positions in memory, the last 16 are reserved for instructions and the first 2 are "additive" meaning that they do not clear when being written to, rather they have to be force-cleared by the CPU, and the rest of the memory is free to use in any way
  + CACH: "Cache", used to operate the CPU (give inputs or take outputs). A graph of the 32 different cache positions will be uploaded in the future
  + READ: Read-only memory, there are 32 referecneable positions, the last 8 are consecutive while the rest each have 8 internal positions between them

  MOVE takes the following arguments
  ```
  MOVE <data type to move from (any)> <data type to move to (MEMO or CACH)> <KEEP (does not clear old memory position)/CLER (clears old memory position)>
  ```
  
  DECL takes the following arguments
  ```
  DECL <data type (MEMO or CACH)> <8 bit string>
  ```
  
  CLER takes the following arguments
  ```
  CLER <data type (MEMO or CACH)>
  ```
  
  GOTO takes the following arguments
  ```
  GOTO <data type (READ or last 16 bits of MEMO)>
  ```
