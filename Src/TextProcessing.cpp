#include "TextProcessing.hpp"

using namespace std;

enum Instruct {
	eMOVE = 1, eDECL, eGOTO, eCLER
};

static hash<string> StringHasher;

static int MoveMemoryOffset (string Line) {
	static int Offset;
	return Offset;
	// RETURN AN OFFSET USING A SYSTEM OF FINDING NEXT INTEGER AND SKIPPING OVER TO FIND THE SECOND SET OF INTEGERS
	// TAKE INPUT OF NUMBER OF SKIPS TO REUSE IN MULTIPLE FUNCTIONS
}

static string Interpret (string Args, string Instruction, unsigned char UsingRead) {
	static unsigned int HashedArgs = StringHasher(Args.substr(0,4));
	switch (HashedArgs) {
	case 1766669891:
				if (UsingRead == 1) Instruction = Instruction + "0";
				Instruction = Instruction + "1" +
						bitset<5>(stoi(Args.substr(4,2))).to_string();
		break;
	case 8525556:
				if (UsingRead == 1) Instruction = Instruction + "0";
				Instruction = Instruction + "0" +
						bitset<5>(stoi(Args.substr(4,2))).to_string();
		break;
	case 3721290381:
		Instruction = Instruction +
				"1" +
				bitset<5>(stoi(Args.substr(4,2))).to_string();
		break;
	default:
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

int main () {
	int LineNum = 1;
	string Line;
	string Out;
	getline(cin, Line);
	switch (StringToInt(Line.substr(0,4))) {
	case 1:
		Out = Interpret(Line.substr(5,6), "00", 1);
		if (stoi(Line.substr(9,2)) >= 10) {
			Out = Out + Interpret(Line.substr(12,6), "", 0);
		}
//		static unsigned int HashedArgs = StringHasher(Line.substr(0,4));
		cout << Out;
		break;
	case 2:
		cout << "DECL";
		break;
	case 3:
		cout << "GOTO";
		break;
	case 4:
		cout << "CLER";
		break;
	default:
		cout << "\033[1;31mError\033[0m: could not process instruction call \"" << Line.substr(0,4) << "\" on line " << LineNum;
		exit(EXIT_FAILURE);
		break;
	}
}
