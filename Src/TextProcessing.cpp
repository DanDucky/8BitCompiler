#include "TextProcessing.hpp"

using namespace std;

enum Instruct {
	eMOVE = 1, eDECL, eGOTO, eCLER
};

static hash<string> StringHasher;

static int IndexNums (string Line, int NumArgs) {
	static size_t Offset = 0;
	Offset = 0;
	Line = Line.substr(5,30);
	for (int Cycles = 1; Cycles <= NumArgs; Cycles++, Line = Line.substr(6 + Offset, 20)) {
		if (Line.find(' ') > 5) {
			Offset++;
		}
	}
	return Offset;
}

static string Interpret (string Args, string Instruction, unsigned char UsingRead) {
	static unsigned int HashedArgs = StringHasher(Args.substr(0,4));
	switch (HashedArgs) {
	case 1766669891: // MEMO !!!SOMETIMES USED AS "READ" BY "GOTO"!!!
		if (UsingRead == 1) Instruction = Instruction + "0";
		Instruction = Instruction + "1" +
				bitset<5>(stoi(Args.substr(4,2))).to_string();
		break;
	case 8525556: // CACH !!!SOMETIMES USED AS "MEMO" BY "GOTO"!!!
		if (UsingRead == 1) Instruction = Instruction + "0";
		Instruction = Instruction + "0" +
				bitset<5>(stoi(Args.substr(4,2))).to_string();
		break;
	case 3721290381: // READ
		Instruction = Instruction +
				"1" +
				bitset<5>(stoi(Args.substr(4,2))).to_string();
		break;
	default: // CATCH
		cout << "default";
		break;
	}
	return Instruction;
}

int StringToInt (std::string Instruction) { // I DID IT... ARE YA HAPPY MAEVE?
	if (Instruction == "MOVE") return eMOVE;
	if (Instruction == "DECL") return eDECL;
	if (Instruction == "GOTO") return eGOTO;
	if (Instruction == "CLER") return eCLER;
	return 0;
}

string InstructionP (string Line) {
	string Out;
	switch (StringToInt(Line.substr(0, 4))) {
		case 1: // MOVE
			Out = Interpret(Line.substr(5,6), "00", 1) + Interpret(Line.substr(11 + IndexNums(Line, 1), 6), "", 0);
			static unsigned int HashedArgs = StringHasher(Line.substr(17 + IndexNums(Line, 2),4));
			switch (HashedArgs) {
			case 321797183: // CLER
				Out = Out + "1";
				break;
			case 4088169964: // KEEP
				Out = Out + "0";
				break;
			default:
				cout << "ERROR";
				break;
			}
		Out = Out.substr(0, 8) + "\n" + Out.substr(8, 8);
			break;
		case 2: // DECL
			Out = Interpret(Line.substr(5,6), "01", 0) + Line.substr(11 + IndexNums(Line, 1),8);
		Out = Out.substr(0, 8) + "\n" + Out.substr(8, 8);
			break;
		case 3: // GOTO
			if (Line.substr(5,4) == "READ") Out = Interpret("MEMO" + Line.substr(9,2), "10", 0);
			else if (Line.substr(5,4) == "MEMO") Out = Interpret("CACH" + Line.substr(9,2), "10", 0);
			break;
		case 4: // CLER
			Out = Interpret(Line.substr(5,6), "11", 0);
			break;
		default:
//			cout << "\033[1;31mError\033[0m: could not process instruction call \"" << Line.substr(0,4) << "\" on line " << LineNum;
			exit(EXIT_FAILURE);
			break;
		}
	return Out;
}
