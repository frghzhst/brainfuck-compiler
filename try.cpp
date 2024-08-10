#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int proc() {
    int tsize = 30000; // Number of cells in the tape
    vector<int> tape(tsize, 0); // Initialize tape with zeros
    int i = 0; // Pointer to the current cell
    string filename;
    
    cout << "Enter the Brainfuck file name: ";
    cin >> filename;
    
    ifstream file(filename);
    char c;
    
    while (file.get(c)) {
        if (c == '>') {
            i = (i + 1) % tsize; // Move the pointer to the right
        } else if (c == '<') {
            i = (i - 1 + tsize) % tsize; // Move the pointer to the left
        } else if (c == '+') {
            tape[i]++; // Increment the value at the current cell
        } else if (c == '-') {
            tape[i]--; // Decrement the value at the current cell
        } else if (c == '.') {
            cout << static_cast<char>(tape[i]); // Output the ASCII character at the cell
        } else if (c == ',') {
            char input;
            cin >> input;
            tape[i] = static_cast<int>(input); // Input a character to the current cell
        } else if (c == '[') {
            if (tape[i] == 0) {
                int loopCount = 1;
                while (loopCount != 0) {
                    if (file.get(c)) {
                        if (c == '[') {
                            loopCount++;
                        } else if (c == ']') {
                            loopCount--;
                        }
                    } else {
                        cout << "Unmatched '['" << endl;
                        return 1;
                    }
                }
            }
        } else if (c == ']') {
            if (tape[i] != 0) {
                int loopCount = 1;
                file.seekg(-1, ios::cur); // Move the file pointer back by 1
                while (loopCount != 0) {
                    if (file.get(c)) {
                        if (c == ']') {
                            loopCount++;
                        } else if (c == '[') {
                            loopCount--;
                        }
                        file.seekg(-2, ios::cur); // Move the file pointer back by 2
                    } else {
                        cout << "Unmatched ']'" << endl;
                        return 1;
                    }
                }
            }
        }
    }

    return 0;
}

int main() {
    proc();
    return 0;
}
