#include <iostream>
#include <cstdlib>
#include <String>
using namespace std;


string transcribe(string dna_seq)
{
    for (int i = 0; i < dna_seq.length(); i++) {
        if (dna_seq[i] == 'T') {
            dna_seq[i] = 'U';
        }
    }

    return dna_seq;
}


int main(int argc, char* argv[])
{
    string input = string(argv[1]);


    cout << transcribe(input) << endl;

}
