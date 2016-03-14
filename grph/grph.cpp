#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <String>
using namespace std;

void
grph()
{


}

int main(int argc, char* argv[])
{
    ifstream inFile("../data/rosalind_grph.txt");

   if (! inFile) {
        cerr << "Couldn't read file" << endl;
        return -1;
    }


    return 0;
}
