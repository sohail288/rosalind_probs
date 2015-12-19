#ifndef _READ_FILES_H
#define _READ_FILES_H

#include <map>
#include <vector>
#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;


// reada a fasta file and returns a map<string, string> object
map<string, string> read_fasta_file(ifstream& inFile);


        

#endif
