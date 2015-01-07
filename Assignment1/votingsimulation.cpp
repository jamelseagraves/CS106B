#include <iostream>
#include "/home/jcsax/CCPP/StanfordCPPLib/random.h"
using namespace std;

const int numTrials = 500;
bool runVotingSimulation(int voters, double spread, double error);

int main() {
int numVoters = 0;
double percentageSpread = -1;
double errorPercentage = -1;
cout << "\nThis is a voting simulation program.\n" << endl;
while (numVoters < 1) {
cout << "Enter number of voters: ";
cin >> numVoters;
if (numVoters < 1) {
cout << "\nError: Number of voters must be a positive integer.\n" << endl;
}
}
while (percentageSpread < 0 || percentageSpread > 1.0) {
cout << "Enter percentage spread between candidates: ";
cin >> percentageSpread;
if (percentageSpread < 0 || percentageSpread > 1.0) {
cout << "\nError: Percentage spread must be between 0 and 1.\n" << endl;
}
}
while (errorPercentage < 0 || errorPercentage > 1.0) {
cout << "Enter voting error percentage: ";
cin >> errorPercentage;
if (errorPercentage < 0 || errorPercentage > 1.0) {
cout << "\nError: Voting error percentage must be between 0 and 1.\n" << endl;
}
}

int invalidVotes = 0;
for (int i = 1; i <= numTrials; i++) {
bool result = runVotingSimulation(numVoters, percentageSpread, errorPercentage);
if (result == false) {
invalidVotes++;
}
}
double invalidResult = (double(invalidVotes)/numTrials) * 100;
cout << "\nChance of an invalid election result after " << numTrials << " trials = " << invalidResult << "%\n" << endl;
return 0;
}

bool runVotingSimulation(int voters, double spread, double error) {
int spread_ = (voters/2) * spread;
int candidateAVotes = voters/2 + spread_;
int candidateAErrors = 0;
int candidateBVotes = voters - candidateAVotes;
int candidateBErrors = 0;

for (int i = 1; i <= candidateAVotes; i++) {
bool probability = randomChance(error);
if (probability == true) {
candidateAErrors++;
}
}
candidateAVotes -= candidateAErrors;

for (int i = 1; i <= candidateBVotes; i++) {
bool probability = randomChance(error);
if (probability == true) {
candidateBErrors++;
}
}
candidateBVotes -= candidateBErrors;

if (candidateAVotes > candidateBVotes) {
return true;
} else {
return false;
}
}
