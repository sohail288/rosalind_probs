#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <String>
using namespace std;

void
bins()
{


}

int main(int argc, char* argv[])
{
    ifstream inFile("../data/rosalind_bins.txt");

   if (! inFile) {
        cerr << "Couldn't read file" << endl;
        return -1;
    }

    bins();

    return EXIT_SUCCESS;
}
