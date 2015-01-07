#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
map<string,map<string,int> m1;
map<string,int> m2;
vector<char> input_chars;
int sequence_length;
int char_count = 0;
string sequence;
for (unsigned int i = 0; i < input_chars; i++) {
if (char_count < sequence_length) {
sequence += input_chars.at(i);
char_count++;
} else {
string new_sequence = input_chars.at(i);
if(m2[new_sequence]) {
m2[new_sequence] += 1;
} else {
m2[new_sequence] = 1;
}
m1[sequence] = m2;
char_count = 0;
sequence = new_sequence;
char_count++;
i -= (sequence_length - 1);
}
}
return 0;
}