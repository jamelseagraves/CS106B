#include<iostream>
using namespace std;

bool isPerfect(int n);

int main() {
int start = 1;
int end = 10000;
cout << "\nPerfect numbers between " << start << " and " << end << " are as follows:\n" << endl;
for (int i = start; i <= end; i++) {
if (isPerfect(i) == true) {
cout << i << endl;
}
}
cout << "\n";
return 0;
}

bool isPerfect(int n) {
int divisorTotal = 0;
for (int i = 1; i < n; i++) {
if (n % i == 0) {
divisorTotal += i;
}
}
if (divisorTotal == n) {
return true;
} else {
return false;
}
}
