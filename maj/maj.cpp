#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <String>
using namespace std;

void
maj()
{


}

int main(int argc, char* argv[])
{
    ifstream inFile("../data/rosalind_maj.txt");

   if (! inFile) {
        cerr << "Couldn't read file" << endl;
        return -1;
    }

    maj();

    return EXIT_SUCCESS;
}
