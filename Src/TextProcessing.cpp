#include "TextProcessing.hpp"

using namespace std;

enum Instruct {
	eMOVE = 1, eDECL, eGOTO, eCLER
};

static hash<string> StringHasher;

static int IndexNums (string Line, int NumArgs) {
	static size_t Offset = 0;
	Line = Line.substr(5,30);
	for (static int Cycles = 1; Cycles <= NumArgs; Cycles++) {
		if (Line.find(' ') > 5 + Offset) {
			Offset++;
		}
		Line = Line.substr(6 + Offset, 20);
	}
	return Offset;
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
		Out = Interpret(Line.substr(5,6), "00", 1) + Interpret(Line.substr(11 + IndexNums(Line, 1), 6), "", 0);
		static unsigned int HashedArgs = StringHasher(Line.substr(17 + IndexNums(Line, 2),4));
		switch (HashedArgs) {
		case 321797183: // CLER
			Out = Out + "1";
			break;
		case 4088169964: // KEEP
			Out = Out + "0";
			break;
		}
		cout << Out << endl;
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
