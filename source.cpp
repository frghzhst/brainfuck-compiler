#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // Include for using system()

using namespace std;

int proc() {
    string usrans;
    cout << "Are you on Windows or Linux: ";
    cin >> usrans;

    int tc = 1;
    char t = '	'; // Use '\t' to represent a tab character
    string filename;
    cout << "Enter the file name: ";
    cin >> filename;
    ifstream file(filename);

    int tsize;
    cout << "How many cells: ";
    cin >> tsize;
    fstream bfs("bfsource.cpp", ios::out); // Open file in write mode

    bfs << "#include<iostream>\n";
    bfs << "using namespace std;\n";
    bfs << "\n";
    bfs << "int main() {\n";
    bfs << "    int tape[" << tsize << "] = {0};\n";
    bfs << "    int i = 0;\n";
    bfs << "    int* cptr = &tape[i];\n";

    char c;

    while (file.get(c)) {
		string repeatedChar(tc, t);
        if (c == '>') {
            bfs << repeatedChar << "i++;\n";
            bfs << repeatedChar << "cptr = &tape[i];\n";
        } else if (c == '<') {
            bfs << repeatedChar << "i--;\n";
            bfs << repeatedChar << "cptr = &tape[i];\n"; // Move the pointer to the previous cell
        } else if (c == '+') {
            bfs << repeatedChar << "*cptr++;\n"; // Increment the value at the current cell
        } else if (c == '-') {
            bfs << repeatedChar << "*cptr--;\n"; // Decrement the value at the current cell
        } else if (c == '.') {
            bfs << repeatedChar << "char sigma = static_cast<char>(*cptr);\n";
            bfs << repeatedChar << "cout << sigma;\n"; // Output the value at the current cell as a character
        } else if (c == ',') {
            bfs << repeatedChar << "cin >> *cptr;\n"; // Input a value to the current cell
        } else if (c == '[') {
            bfs << repeatedChar << "while (tape[0] != 0) {\n";
            tc++;
        } else if (c == ']') {
            tc = tc - 1;
			string repeatedChar(tc, t);
            bfs << repeatedChar << "}\n";
        }
    }
	bfs << "\n	return 0;\n";
	bfs << "}";

    if (usrans == "windows") {
        system("g++ bfsource.cpp -o brainfuckoutput.exe");
		system("brainfuckoutput.exe");
	} else {
        system("g++ bfsource.cpp -o brainfuckoutput");
		system("./brainfuckoutput");
    }

    bfs.close(); // Close the file after writing
    return 0;
}

int main() {
    proc();
    return 0;
}
