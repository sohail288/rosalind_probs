#include "../include/rna_translation.h"

map<string, char>
getCodonTable()
{
    map<string, char> codonToProtein;

    ifstream inFile("../data/rna_codon_table.txt");

    if (!inFile) {
        cerr << "Couldn't find codon table file" << endl;
        exit(1);
    }

    string currentStr;
    string currentCodon;
    char currentProtein;

    inFile >> currentStr;
    while (!inFile.eof()) {
        currentCodon = currentStr; 
        inFile >> currentStr;

        if (currentStr.compare("Stop") == 0) {
            currentProtein = ' ';
        } else {
            currentProtein = currentStr[0];
        }

        codonToProtein[currentCodon] = currentProtein;

        inFile >> currentStr;
    }

    return codonToProtein;
}


/* gets a mapping of protein to possible codons */

map<char, vector<string> >
getProteinTable()
{
    map<string, char>::iterator codonMapIt;
    map<char, vector<string> > proteinMap;

    char currentProtein;
    
    map<string, char> codonMap = getCodonTable();



    for (codonMapIt = codonMap.begin(); 
            codonMapIt != codonMap.end();
            codonMapIt++) {

        currentProtein = codonMapIt->second;
        
        // add the codon to the protein vector
        proteinMap[currentProtein].push_back(codonMapIt->first);
    }

    return proteinMap;
}

/* get a mapping of proteins to their monoisotropic masses */
        
map<char, double> getProteinMasses()
{
    ifstream inFile("../data/monoisotropic_mass_table.txt");

    if (!inFile) {
        cerr << "Couldn't open protein mass file " << endl;
        exit(1);
    }

    map<char, double> massTable;
    char protein;
    double mass;

    inFile >> protein;
    while (!inFile.eof()) {
        inFile >> mass;

        massTable[protein] = mass; 

        inFile >> protein;
    }

    return massTable;
}
