#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

int sequence_length = 0;
ifstream ifs;

void openFile(const char* filename);
void readFile();
void sortData(vector<char> v);

int main() {
string input;
while (sequence_length == 0) {
cout << "Enter character sequence length (must be a positive integer): ";
getline(cin, input);
stringstream inputStream(input);
if (!(inputStream >> sequence_length)) {
sequence_length = 0;
}
}

string fileName;
cout << "Enter file name (including .ext): ";
getline(cin, fileName);
openFile(fileName.c_str());
return 0;
}

void openFile(const char* filename) {
ifs.open(filename);
if (ifs.fail()) {
ifs.clear();
string fileName;
cout << "Could not open file. Please enter valid file name (including .ext): ";
getline(cin, fileName);
openFile(fileName.c_str());
} else {
readFile();
}
}

void readFile() {
char c;
vector<char> input_chars;
vector<char>::iterator it;
while (ifs >> noskipws >> c) {
it = input_chars.end();
it = input_chars.insert(it, c);
}
sortData(input_chars);
}

void sortData(vector<char> v) {
map< string, map<string,int> > m1;
int char_count = 0;
string sequence;
for (unsigned int i = 0; i < v.size(); i++) {
if (char_count < sequence_length) {
sequence += v.at(i);
char_count++;
} else {
string next_char;
next_char += v.at(i);
m1[sequence][next_char] += 1;
cout << sequence << " : " << next_char << " : " << m1[sequence][next_char] << endl;
char_count = 0;
string new_sequence;
new_sequence += v.at(i-(sequence_length-1));
sequence = new_sequence;
char_count++;
i -= (sequence_length - 1);
}
}

/*for (map< string, map<string,int> >::iterator it1 = m1.begin(); it1 != m1.end(); it1++) {
cout << it1->first << " has value: " << endl;
for (map<string,int>::iterator it2 = m2.begin(); it2 != m2.end(); it2++) {
cout << it2->first << " has value " << it2->second << endl;
}
}*/
}

/* void getMostFrequentSequence(vector<char> v) {
sort(v.begin(), v.end());
char currentChar = v[0];
char mostChar = v[0];
int currentCount = 0;
int mostCount = 0;
for (auto c : v) {
if ( c == currentChar )
currentCount++;
else {
if (currentCount > mostCount) {
mostChar = currentChar;
mostCount = currentCount;
}
currentChar = c;
currentCount = 1;
}
}
} */
