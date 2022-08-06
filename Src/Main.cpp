#include "TextProcessing.hpp"

#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

void FileWrite(ofstream &OutputFile, string Binary) {
	OutputFile << Binary << "\n";
}

void FileRead(char** argv) {
	ifstream InputFile;
	InputFile.open(argv[1]);
	string Line;
	ofstream OutputFile;
	OutputFile.open((argv[2]));
	if (InputFile.is_open()) {
		int LineNum = 0;
		while (getline(InputFile, Line)) {
			auto start = high_resolution_clock::now();
			LineNum++;
			FileWrite(OutputFile, InstructionP(Line));
			auto stop = high_resolution_clock::now();
			auto Duration = duration_cast < microseconds > (stop - start);
			cout << Duration.count() + "microseconds\n";
		}

	} else {
		//TODO: error handling UWUUWUUWUUW
	}
}

int main (int argc, char** argv) {
	FileRead(argv);
}
