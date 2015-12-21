#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <String>
#include <iomanip>
using namespace std;


// load the protein masses file
#include "rna_translation.h"

double
prtm(string proteinString, map<char, double>& proteinTable)
{
    double totalWeight = 0;

    cout << setprecision(9) << endl;
    for (int i = 0; i < proteinString.length(); i++) {
        cout << proteinString[i] << proteinTable[proteinString[i]] << endl;
        totalWeight += proteinTable[proteinString[i]];
    }

    return totalWeight;
}


string readFile(ifstream& inFile)
{
    string proteinString;

    inFile >> proteinString;
    
    return proteinString;
}

int main(int argc, char* argv[])
{
    ifstream inFile("../data/rosalind_prtm.txt");
    string proteinString;
    map<char, double> proteinTable = getProteinMasses();

   if (! inFile) {
        cerr << "Couldn't read file" << endl;
        return -1;
    }

    proteinString = readFile(inFile);

    cout << prtm(proteinString, proteinTable) << endl;

    return 0;
}
