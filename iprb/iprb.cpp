#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <String>
using namespace std;

/*

representing a population containing k+m+n organisms: 
k individuals are homozygous dominant for a factor, m are heterozygous, and n are homozygous recessive.

return: float: probability that two randomly selected mating organisms  
will produce an individual possessing a dominant allele (and thus 
displaying the dominant phenotype). Assume that any two organisms can mate.
*/

float
iprb(int k, int m, int n)
{
    // calculate the recessive genes and subtract from 1
    int total = k+m+n;

    cout << total << endl;

    float rec_parents = ((n+.0) / (total+.0)) * ((n-1.0)/(total-1.0));
    
    float het_parents = ((m+.0) / ((total+.0)) * ((m-1)/(total-1.0)));


    float het_rec_parents = (((m+.0) / (total+.0))*((n+.0)/(total-1.0)) +
                             ((n+.0)/(total+.0)) * ((m+.0)/(total-1.0)));


    return 1 - het_parents*.25 - het_rec_parents*.5-rec_parents;
}

void readFile(ifstream& inFile, int& k, int& m, int& n)
{
   inFile >> k;
   inFile >> m;
   inFile >> n;
   cout << k << " " << m << " " << n << endl;
}



int main(int argc, char* argv[])
{
    ifstream inFile("rosalind_iprb.txt");
    int k, m, n;
    
    if (!inFile) {
        cerr << "couldn't read file" << endl;
        return -1;
    }
    readFile(inFile, k, m, n);
    
    cout << iprb(k, m, n) << endl;

    inFile.close();
    return 0;
}
