#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <String>
#include <vector>
#include <cmath>
using namespace std;


void readFile(ifstream& inFile, string& aString)
{
    string line;
    aString = "";
    
    getline(inFile, line);
    while (!inFile.eof()) {
        if (line[0] != '>') {
            aString.append(line); 
        }

        getline(inFile, line);
    }
}

bool reverseCompliment(string substr) 
{
    
    char curBase;
    bool isCompliment = true;

    if (substr.length() < 4 || substr.length() > 12) {
        isCompliment = false;
    } 
        

    
    for (int i = substr.length() - 1, j = 0 ; 
            i >= ceil(substr.length() / 2) && isCompliment;
            j++, i--) {
        
        switch(substr[i]) {
            case 'A': curBase = 'T'; break;

            case 'T': curBase = 'A'; break;

            case 'C': curBase = 'G'; break;

            case 'G': curBase = 'C'; break;
            default:
                cerr << "Error in reading dna string" << endl;
                cerr << "read: " << substr[i] << endl;
                exit(1);
        } 
        
        if (substr[j] != curBase) {
            isCompliment = false;
        }
    }
    
    return isCompliment;
    
}

void
revp(const string aString, vector<string>& indices)
{
    char buff[256];
    int len;
    
    //cout << aString << endl;    
    //cout << aString.length() << endl;
    for (int i = 0; i < aString.length(); i++) {
        for (int j = i; j  < aString.length(); j++) {
            //cout << "j: " << j << " " << aString.substr(i,j-i)<< " " << j-i << endl;
            if ( reverseCompliment(aString.substr(i, j-i+1))) {
                //cout << aString.substr(i, j-i+1) << endl;
                len = j - i+1;
                snprintf(buff, 255, "%d %d", i+1, len);
                indices.push_back(string(buff));
            }
        }
    }
}

int main(int argc, char* argv[])
{
    string aString;
    vector<string> indices;
    vector<string>::iterator it;

    ifstream inFile("../data/rosalind_revp.txt");

    cout << "reading file" << endl;
    readFile(inFile, aString);
    
    cout << "revp" << endl;
    revp(aString, indices);

    cout << "outputing results" << endl;
    for (it = indices.begin(); it != indices.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}
