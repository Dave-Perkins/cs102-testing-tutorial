#include <iostream>
#include <vector>
#include <string>
#include <fstream>  // for reading data from an input file
#include <sstream>  // to use stringstream() for tokenizing the input file's strings

using namespace std;

// Overload << so we can print a vector of integers:
ostream & operator<<(ostream &output, vector<int> &vec) {
    for (int entry : vec) {
        output << " " << entry;
    }
    output << endl;
    return output;
}

// Tokenize a string (used for grab_data() only):
void tokenize(string const &str, vector<string> &tokens) {
    tokens.clear();
    stringstream ss(str);
    string s;
    char delimiter = ' ';
    while (getline(ss, s, delimiter)) {
        tokens.push_back(s);
    }
}

// Grab data from the input text file:
void grab_data(string filename, vector<int> &data, int num_entries) {
    string line;
    vector<string> tokens;
    ifstream myfile(filename);
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            tokenize(line, tokens);
            for (int i = 0; i < tokens.size(); i++) {
                // Convert the token from string to integer, and push it into data:
                data.push_back(stoi(tokens.at(i)));
            }
        }
    myfile.close();
    }
}

/*  Notes: 
      argc will equal the number of arguments entered on the command line
      **argv will be an array of strings that capture those arguments
      (the compiled file does count, and appear in **argv!)

    To use this program in the replit shell:
      g++ -std=c++17 -o main main.cpp
      ./main input00.txt 
*/
int main(int argc,  char **argv) {
    // Read the filename from the command line:
    string filename(argv[1]);

    // Grab the graph data from the input file:
    int num_entries = 0;
    vector<int> data;
    grab_data(filename, data, num_entries);

    // Check if the data was successfully grabbed from the input file:
    cout << "Here's the data from the input file: " << data << endl;
    
    return 0;
}