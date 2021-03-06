#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include "/home/jcsax/CS106B/StanfordCPPLib/random.h"
using namespace std;

const int NUM_CHARS = 2000;
int sequence_length = 0;
ifstream ifs;

void openFile(const char* filename);
void readFile();
void sortData(vector<char> v);
void writeRandomly(string charSequence, map< string, map<string,int> > m1, map<string,int> m2);

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
map<string,int> m2;
int char_count = 0;
string sequence;
for (unsigned int i = 0; i < v.size(); i++) {
if (char_count < sequence_length) {
sequence += v.at(i);
char_count++;
} else {
m2[sequence] += 1;
string next_char;
next_char += v.at(i);
m1[sequence][next_char] += 1;
char_count = 0;
string new_sequence;
new_sequence += v.at(i-(sequence_length-1));
sequence = new_sequence;
char_count++;
i -= (sequence_length - 1);
}
}
int currentMax = 0;
string mostFrequentSequence;
for (map<string,int>::iterator it = m2.begin(); it != m2.end(); it++) {
if (it->second > currentMax) {
mostFrequentSequence = it->first;
currentMax = it->second;
}
}
writeRandomly(mostFrequentSequence, m1, m2);
}

void writeRandomly(string charSequence, map< string, map<string,int> > m1, map<string,int> m2) {
string output = charSequence;
map<string,int> inner_map;
for (unsigned int i = 0; i < (NUM_CHARS-sequence_length); i++) {
inner_map = m1[charSequence];
string next_char;
bool selected = false;
while (!selected) {
for (map<string,int>::iterator it = inner_map.begin(); it != inner_map.end(); it++) {
double probability = it->second/double(m2[charSequence]);
selected = randomChance(probability);
if (selected) {
next_char = it->first;
break;
}
}
}
output += next_char;
charSequence.erase(0,1);
charSequence += next_char;
if (m1.find(charSequence) == m1.end()) {
cout << "done" << endl;
break;
}
}
cout << "\n" << output << "\n" << endl;
}
