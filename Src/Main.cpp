#include "TextProcessing.hpp"

#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

void FileWrite(ofstream &OutputFile, string Binary) {
	OutputFile << Binary << "\n";
}

void FileRead(char** argv) {
	int LineNumOut = 1;
	ifstream InputFile;
	InputFile.open(argv[1]);
	string Line;
	string Binary;
	ofstream OutputFile;
	OutputFile.open((argv[2]));
	int Arrow;
	if (InputFile.is_open()) {
		int LineNum = 0;
		while (getline(InputFile, Line)) {
			LineNum++;
			cout << "Line " << LineNum << " ┼ " << Line << " ";
			auto start = high_resolution_clock::now();
			Binary = InstructionP(Line);
			FileWrite(OutputFile, Binary);
			auto stop = high_resolution_clock::now();
			auto Duration = duration_cast < microseconds > (stop - start);
			for (Arrow = 0; Arrow < 24 - Line.length(); Arrow++) {
				cout << "─";
			}
			if (Line.substr(0, 4) == "MOVE" || Line.substr(0, 4) == "DECL") {
				cout << "┬─" << "> " << Binary.substr(0, 8)
						<< " ┼ Compiled line "
						<< LineNumOut
						<< " ─╮\n       │                          ╰─> "
						<< Binary.substr(9, 8);
				LineNumOut++;
				cout << " ┼ Compiled line " << LineNumOut
						<< " ─┴─> \033[1;32mcompleted\033[0m in "
						<< Duration.count()
						<< " microseconds\n";
				LineNumOut++;
			} else {
				cout << "──> " << Binary
						<< " ┼ Compiled line " << LineNumOut
						<< " ───> \033[1;32mcompleted\033[0m in "
						<< Duration.count()
						<< " microseconds\n";
				LineNumOut++;
			}
			
		}

	} else {
		//TODO: error handling UWUUWUUWUUW
	}
}

int main (int argc, char** argv) {
//	cout << "─┬─>";
//           └└─>
	cout << "Compiling " << argv[1] << " to " << argv[2] << "\n";
	FileRead(argv);
}
