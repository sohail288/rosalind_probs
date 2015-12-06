#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;


char*  complimentDna(const char* dna_string)
{
    char* new_str = new char[strlen(dna_string)+11];
    

    // first reverse it
    for (int i = strlen(dna_string) - 1, j = 0; i >= 0; i--, j++) {
        new_str[j] = dna_string[i];
        
    }
    new_str[strlen(dna_string)] = '\0';

    for (int i = 0; new_str[i]; i++) {
        switch (new_str[i]) {
            case 'A': new_str[i] = 'T'; break;
            case 'T': new_str[i] = 'A'; break;
            case 'C': new_str[i] = 'G'; break;
            case 'G': new_str[i] = 'C'; break;
            default: break;
            
        }
    }
    return new_str;
}


int main(int argc, char* argv[])
{
    cout << "REVC" << endl;
    char* new_str = complimentDna(argv[1]);
    
    cout << new_str << endl;

    delete [] new_str;

    return 0;
}
