#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <String>
using namespace std;

template<class ItemType>
void
swap(ItemType *arr, int i, int j)
{
    ItemType temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


template<class ItemType>
void
perm(ItemType *arr, int n, int i, int* count)
{
    // found a permutation
    if (i == n) {
        for (int j = 0; j < n; j++) {
            cout << arr[j] << (i == n - 1 ? '\0' : ' ');
        }
        cout << endl;
        *count = *count + 1;
    } else {
        // go through the array and swap each member and check for further 
        // permutations with each swap
        // after the return, restore the original permutation
        for (int j = i; j < n; j++) {
            swap(arr, i, j);
            perm(arr, n, i+1, count);
            swap(arr, j, i);
        }
    }
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        cout << "need to pass in a number for permuations" << endl;
        return 1;
    }

    int n = atoi(argv[1]);

    int* arr = new int[n];
    int count = 0;

    for (int i = 0; i < n; i++) {
        arr[i] = i+1; 
    }

    perm(arr, n, 0, &count);
    cout << count << endl;

    delete [] arr;

    return 0;
}
