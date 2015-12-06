#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <String>
#include <vector>
using namespace std;

void
subs(string str, string tok, vector<int>& indices)
{

    for (int i = 0; i < str.length(); i++) {
        if (str.compare(i, tok.size(), tok) == 0) {
            indices.push_back(i+1);
        }
    }
}

void
readFile(ifstream& inFile, string& strand, string& tok)
{
    inFile >> strand;
    inFile >> tok;
}

int main(int argc, char* argv[])
{
    vector <int> indices;
    string tok, strand;
    vector<int>::iterator indicesIterator;

    ifstream inFile("../data/rosalind_subs.txt");
    if (! inFile) {
        cerr << "Couldn't read file" << endl;
        return -1;
    }

    readFile(inFile, strand, tok);

    
    subs(strand, tok, indices);

    cout << "Spitting out vector" << endl;
    for (indicesIterator = indices.begin(); indicesIterator != indices.end();
            ++indicesIterator) {
        cout << *indicesIterator << " ";
    }
    cout << endl;
    

    return 0;
}
