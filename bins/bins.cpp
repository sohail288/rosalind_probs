#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <String>
#include <cmath>
using namespace std;



int
binary_search(int* arr, int number, int beg, int end)
{
    // prevent arithmetic overflow
    int mid = beg + (end - beg)/2;

    if (arr[mid] == number) {
        return mid;
    } else {
        if (beg  >=  end) {
            // didn't find it in the array
            return -1;
        } else if (arr[mid] > number) {
            return binary_search(arr, number, beg, mid - 1);
        } else {
            return binary_search(arr, number, mid + 1, end);
        }
    }
}

void
bins(int* sortedArray, int* numbersToSearchFor, int* indices, int n, int m)
{

    for (int i = 0; i < m; i++) {
        indices[i] = binary_search(sortedArray, numbersToSearchFor[i], 0, n);
    }

}

void
read_file(ifstream& inFile, int** sortedArray, int** numbersToSearchFor, 
         int& n, int& m)
{
    inFile >> n;
    inFile >> m;

    *sortedArray = new int[n];
    *numbersToSearchFor = new int[m];
    
    for (int i = 0; i < n; i++) {
        inFile >> *(*sortedArray + i);
    }

    for (int i = 0; i < m; i++) {
        inFile >> *(*numbersToSearchFor + i);
    }

}



int main(int argc, char* argv[])
{
    ifstream inFile("../data/rosalind_bins.txt");

   if (! inFile) {
        cerr << "Couldn't read file" << endl;
        return -1;
    }

    int *sortedArray, *numbersToSearchFor,
        *indices, n, m;

    read_file(inFile, &sortedArray, &numbersToSearchFor, n, m); 
    
//    cout << "Input Array" << endl;
//    for (int i = 0; i < n; i++) {
//        cout << sortedArray[i] << " ";
//    }
//    cout << endl;

//    cout << "Numbers to search for" << endl;
//    for (int i = 0; i < m; i++) {
//        cout << numbersToSearchFor[i] << " ";
//    }
//    cout << endl;

    indices = new int[m];

    bins(sortedArray, numbersToSearchFor, indices, n, m);


//    for (int i = 0; i < m; i++) {
//        cout << (indices[i] >= 0 ? indices[i] + 1 : indices[i]) << " ";
//    }
//    cout << endl;

    delete [] sortedArray;
    delete [] numbersToSearchFor;
    delete [] indices;

    return EXIT_SUCCESS;
}
