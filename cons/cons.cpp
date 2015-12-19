#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <String>
using namespace std;


#include "read_files.h"


#define A 0
#define C 1
#define G 2
#define T 3

string rowNumToBase = "ACGT";

const int numRows = 4;

void
cons(map<string, string>& seqMap, int** matrix)
{
    map<string, string>::iterator seqIt;
    string currentSeq;

    for (seqIt=seqMap.begin(); seqIt != seqMap.end(); seqIt++) {

        // iterate over the sequence
        currentSeq = seqIt->second;
        for (int i = 0; i < currentSeq.length(); i++) {
            switch (currentSeq[i]) {
                case 'A': matrix[A][i] += 1; break;
                case 'C': matrix[C][i] += 1; break;
                case 'G': matrix[G][i] += 1; break;
                case 'T': matrix[T][i] += 1; break;
            }
        }
    }

}


int** createMatrix(int rows, int columns)
{
    int** matrix;

    matrix = new int*[rows];

    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[columns];
            
        // set to zero
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = 0;
        }
    }

    return matrix; 
}

string getConsensusString(int** profileMatrix, int rows, int columns) 
{
    string consensusString = "";
    int maxBaseCount, maxBase;
    // traverse all rows for one column and then move on
    for (int j = 0; j < columns; j++) {
        
        // what is the max base in the col?
        maxBase = maxBaseCount = 0; 
        for (int i = 0; i < rows; i++) {
            if (profileMatrix[i][j] >= maxBaseCount) {
                maxBaseCount = profileMatrix[i][j];

                // row number indicates the base
                maxBase      = i;
            }
        }

        // found the max base so append it by translating the row to a char
        consensusString += rowNumToBase[maxBase];
    }

    
    return consensusString;
}

void getProfileMatrix(int** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        cout << rowNumToBase[i] << ": ";
        for(int j = 0; j < cols; j++) {
           cout << matrix[i][j] << " "; 
        }
        cout << endl;
    }
}

int main(int argc, char* argv[])
{
    ifstream inFile("../data/rosalind_cons.txt");

   if (! inFile) {
        cerr << "Couldn't read file" << endl;
        return -1;
    }

    map<string, string> seqMap = read_fasta_file(inFile);

    // get length from any of the strands
    int strand_length = seqMap.begin()->second.length();

    int** profileMatrix = createMatrix(numRows, strand_length);

    cons(seqMap, profileMatrix);

    cout << getConsensusString(profileMatrix, numRows, strand_length) << endl;

    getProfileMatrix(profileMatrix, numRows, strand_length);

    return 0;
}
