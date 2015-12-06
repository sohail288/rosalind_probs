#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <String>
#include <map>
using namespace std;



void readFile(ifstream& inFile, map<string, string>& seqMap)
{
    string line;
    string currentSeq;

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

}

double
gc(string seq)
{
    int gc_content = 0;

    for (int i = 0; i < seq.length(); i++) {
        if (seq[i] == 'C' || seq[i] == 'G') {
            gc_content++;
        }
    }
    return (gc_content+0.0)/seq.length();
}


map<string, double>::iterator
max(map<string, double> gcMap) {
    map<string, double>::iterator gcIterator, gcMax;
    gcMax = gcMap.begin(); 

    for(gcIterator = gcMap.begin(); gcIterator != gcMap.end(); ++gcIterator) {
        if (gcIterator->second > gcMax->second) {
            gcMax = gcIterator;
        }
    }
    return gcMax;
}



int main(int argc, char* argv[])
{
    map<string, string> seqMap;
    map<string, double> gcMap;

    ifstream inFile("./gc/rosalind_gc.txt");

    if (!inFile) {
        cout << "couldn't open the txt file" << endl;
        exit(1);
    }

    readFile(inFile, seqMap);

    map<string, string>::iterator seqIterator;

    for(seqIterator = seqMap.begin(); 
        seqIterator != seqMap.end(); ++seqIterator){

        gcMap[seqIterator->first] = gc(seqIterator->second);
    } 

    cout << max(gcMap)->first << endl;

    return 0;
}
