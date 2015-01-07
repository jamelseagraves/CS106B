#include <iostream>
#include "/home/jcsax/CCPP/StanfordCPPLib/strlib.h"
using namespace std;

string convertSurnameToSoundex(string surname);
string removeDuplicateDigitsAndZeros(string surname);

int main() {
string surname;
while (true) {
cout << "Enter surname (RETURN to quit): ";
getline(cin, surname);
if (surname.length() >= 1) {
string soundex = convertSurnameToSoundex(surname);
cout << "Soundex code for " << surname << " is " << soundex << endl;
} else {
break;
}
}
return 0;
}

string convertSurnameToSoundex(string surname) {
char firstLetter = surname[0];
if (!isupper(firstLetter)) {
firstLetter = toupper(firstLetter);
surname.replace(0, 1, charToString(firstLetter));
}

for (unsigned int i = 1; i < surname.length(); i++) {
char letter = surname[i];
if (isupper(letter)) {
letter = tolower(letter);
}
switch (letter) {
case 'a': case 'e': case 'i': case 'o': case 'u': case 'h': case 'w': case 'y':
surname.replace(i, 1, "0");
break;
case 'b': case 'f': case 'p': case 'v':
surname.replace(i, 1, "1");
break;
case 'c': case 'g': case 'j': case 'k': case 'q': case 's': case 'x': case 'z':
surname.replace(i, 1, "2");
break;
case 'd': case 't':
surname.replace(i, 1, "3");
break;
case 'm': case 'n':
surname.replace(i, 1, "4");
break;
case 'l':
surname.replace(i, 1, "5");
break;
case 'r':
surname.replace(i, 1, "6");
break;
default:
surname.erase(i, 1);
i--;
}
}

surname = removeDuplicateDigitsAndZeros(surname);
while (surname.length() < 4) {
surname += "0";
}
return surname;
}

string removeDuplicateDigitsAndZeros(string surname) {
for (unsigned int i = 1; i < surname.length(); i++) {
if (surname[i] == surname[i-1] || surname[i] == '0') {
surname.erase(i, 1);
i--;
}
}
return surname;
}
