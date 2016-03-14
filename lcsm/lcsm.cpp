#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <String>
using namespace std;

#include "read_files.h"

void
lcsm(map<string,string>& sequences, string& longestSubStr)
{
    string longestSeq;
    string currentSeq;
    bool allSequencesContainSeq;
    string firstSeq = sequences.begin()->second;
    int lenLongestSeq = 0;


    // start this iterator on the second sequence
    map<string, string>::iterator it_ = sequences.begin();
    it_++;

    for (int i = 0; i < firstSeq.length(); i++) {
        for (int j = i; j < firstSeq.length(); j++) {

            currentSeq = firstSeq.substr(i, j-i+1);
            allSequencesContainSeq = true;

            for(map<string, string>::iterator it = it_; 
                    it != sequences.end() && allSequencesContainSeq; 
                    ++it){
                // if not found
                if (it->second.find(currentSeq) == string::npos) {
                    allSequencesContainSeq = false; 
                }
            }

            if (allSequencesContainSeq) {
                if (lenLongestSeq < currentSeq.length()) {
                    lenLongestSeq = currentSeq.length();
                    longestSeq = currentSeq;
                }
            }
                
        }
    }

    longestSubStr = longestSeq;            

}

int main(int argc, char* argv[])
{
    ifstream inFile("../data/rosalind_lcsm.txt");
    map<string, string> sequences;
    string longestSubStr;

   if (! inFile) {
        cerr << "Couldn't read file" << endl;
        return -1;
    }

    sequences = read_fasta_file(inFile);   

    

    lcsm(sequences, longestSubStr);

    cout << "Longest Common Subsequence is: " << endl;
    cout << longestSubStr << endl;

    return 0;
}
