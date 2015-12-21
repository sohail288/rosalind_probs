#ifndef _RNA_TRANSLATION_H
#define _RNA_TRANSLATION_H

#include <map>
#include <vector>
#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;


map<string, char> getCodonTable();


/* gets a mapping of protein to possible codons */

map<char, vector<string> > getProteinTable();

map<char, double> getProteinMasses();
        

#endif
