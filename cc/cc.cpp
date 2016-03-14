#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <String>
using namespace std;

void
cc()
{


}

int main(int argc, char* argv[])
{
    ifstream inFile("../data/rosalind_cc.txt");

   if (! inFile) {
        cerr << "Couldn't read file" << endl;
        return -1;
    }

    cc(argv[1]);

    return 0;
}
