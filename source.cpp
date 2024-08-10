#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int proc() {
    int tsize;
    cout << "How many cells: ";
    cin >> tsize;

    int tape[tsize] = {0}; // Initialize all cells to 0
    int i = 0;
    int* cptr = &tape[i]; // Pointer to the current cell
    string filename;
    cout << "Enter the file name: ";
    cin >> filename;

    ifstream file(filename);
    char c;
    
    while (file.get(c)) {
        if (c == '>') {
            i++;
            cptr = &tape[i]; // Move the pointer to the next cell
        } else if (c == '<') {
            i--;
            cptr = &tape[i]; // Move the pointer to the previous cell
        } else if (c == '+') {
            (*cptr)++; // Increment the value at the current cell
        } else if (c == '-') {
            (*cptr)--; // Decrement the value at the current cell
        } else if (c == '.') {
            cout << *cptr; // Output the value at the current cell as a character
        } else if (c == ',') {
            cin >> *cptr; // Input a value to the current cell
        } else {
            continue; // Ignore other characters
        }
    }

    return 0;
}

int main() {
    proc();
    return 0;
}
