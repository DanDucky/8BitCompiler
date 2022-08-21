#include "TextProcessing.hpp"

#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

int LineNumOut = 1;
ofstream OutputFile;

void FileWrite(ofstream &OutputFile, string Binary) {
	OutputFile << Binary << "\n";
}

void FileRead(char** argv) {
	ifstream InputFile;
	InputFile.open(argv[1]);
	string Line;
	string Binary;
	int LineNum = 0;
	OutputFile.open(argv[2]);
	static unsigned int Arrow;
	auto StartFull = high_resolution_clock::now();
	if (InputFile.is_open()) {
		while (getline(InputFile, Line)) {
			if (Line.find("  ") != string::npos) { //slowslowslow
				Line = Line.substr(0, Line.find("  "));
			}
			LineNum++;
			cout << "Line " << LineNum << " ┼ " << Line << " ";
			auto start = high_resolution_clock::now();
			Binary = InstructionP(Line, LineNum);
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
		cout
				<< "\n\033[1;31mError\033[0m: could not open file \""
				<< argv[1]
				<< "\" please enter a valid file path"
				<< "\nExiting...\n";
		exit(EXIT_FAILURE);
	}
	auto StopFull = high_resolution_clock::now();
	auto Duration = duration_cast<microseconds>(StopFull - StartFull);
	cout << "Compiled " << LineNum <<
	" lines of source code to " << LineNumOut - 1
			<< " lines of bytecode in " <<
	Duration.count()
			<< " microseconds\n";
}

int main (int argc, char** argv) {
	cout << "Compiling " << argv[1] << " to " << argv[2] << "\n";
	FileRead(argv);
	if (LineNumOut < 200) {
		for (; LineNumOut <= 200; LineNumOut++) {
			FileWrite(OutputFile, "10000001");
		}
	}
}
