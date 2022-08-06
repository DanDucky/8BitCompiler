#ifndef TEXTPROCESSING_HPP_
#define TEXTPROCESSING_HPP_

#include <iostream>
#include <string>
#include <map>
#include <bitset>
#include <stdlib.h>

static int IndexNums(std::string Line, int NumArgs);
static std::string Interpret(std::string Args, std::string Instruction,
		unsigned char UsingRead);
int StringToInt (std::string Instruction);
std::string InstructionP (std::string Line);

#endif /* TEXTPROCESSING_HPP_ */
