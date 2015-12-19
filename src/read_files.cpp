#include "read_files.h"

map<string, string> read_fasta_file(ifstream& inFile)
{
    string line;
    string currentSeq;
    map<string, string> seqMap;

    getline(inFile, line);
    while (!inFile.eof()){
        if (line[0] == '>') {
            currentSeq = line.substr(1, line.length()-1);;
            seqMap[currentSeq] = "";
        } else {
            seqMap[currentSeq].append(line);
        }
        getline(inFile, line);
    }

    return seqMap;
}
