#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream ifs;

void openFile(const char* filename);
void readFile();
void printHistogram(vector<int> digits);

int main() {
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
int n,i=0,lines;
vector<int> firstDigits;
vector<int>::iterator it;
while (ifs >> n) {
it = firstDigits.end();
it = firstDigits.insert(it, n);
i++;
}
lines = i;
printHistogram(firstDigits);
}

void printHistogram(vector<int> digits) {
vector<int> histogram (10, 0);
for (unsigned int i = 0; i < digits.size(); i++) {
switch (digits.at(i)/10) {
case 0: histogram.at(0) = histogram.at(0) + 1;
break;
case 1: histogram.at(1) = histogram.at(1) + 1;
break;
case 2: histogram.at(2) = histogram.at(2) + 1;
break;
case 3: histogram.at(3) = histogram.at(3) + 1;
break;
case 4: histogram.at(4) = histogram.at(4) + 1;
break;
case 5: histogram.at(5) = histogram.at(5) + 1;
break;
case 6: histogram.at(6) = histogram.at(6) + 1;
break;
case 7: histogram.at(7) = histogram.at(7) + 1;
break;
case 8: histogram.at(8) = histogram.at(8) + 1;
break;
case 9: histogram.at(9) = histogram.at(9) + 1;
break;
default:
break;
}
}
for (unsigned int i = 0; i < histogram.size(); i++) {
if (i == 0) {
cout << "0" << "-" << "9: ";
} else {
cout << i << "0" << "-" << i << "9: ";
}
for (unsigned int j = 0; j < histogram.at(i); j++) {
cout << "X";
}
cout << "\n";
}
ifs.close();
}
