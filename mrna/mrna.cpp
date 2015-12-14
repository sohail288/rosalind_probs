#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <String>
using namespace std;


// get the rna  and protein map
#include "../include/rna_translation.h"

int
mrna(string rnaString, map<char, vector<string>>& proteinMap)
{
    unsigned long long numPossibilities= 1;
    char curProtein;

    for (int i = 0; i < rnaString.length(); i++) {
        curProtein = rnaString[i]; 
        
        // multiply by size of the vector
        numPossibilities *= proteinMap[curProtein].size();
        numPossibilities %= (1000*1000);
    }
    
    // multiply by number of stop codons
    numPossibilities *= proteinMap[' '].size();

    return numPossibilities % (1000*1000);

}

void
readFile(ifstream& inFile, string& rnaString)
{
    inFile >> rnaString; 
}

int main(int argc, char* argv[])
{
    ifstream inFile("../data/rosalind_mrna.txt");
    string   rnaString;
    map<char, vector<string>> proteinMap = getProteinTable();

   if (! inFile) {
        cerr << "Couldn't read file" << endl;
        return -1;
    }

    

    readFile(inFile, rnaString);

    cout << mrna(rnaString, proteinMap) << endl;

    return 0;
}
