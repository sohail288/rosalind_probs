#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <String>
#include <utility>
using namespace std;

#include <boost/graph/adjacency_list.hpp>
using namespace boost;

#include "graph.h"


typedef vector<pair<int,int> > edge_list;

vector<int>
deg(int graphSize, edge_list& edges)
{
    adjacency_list<vecS, vecS, undirectedS> Graph(graphSize);
    edge_list::iterator edgeIt;
    vector<int> degrees;

    for (edgeIt = edges.begin(); edgeIt != edges.end(); edgeIt++) {
        add_edge((*edgeIt).first, (*edgeIt).second, Graph);
    }

    for (int i = 1; i <= graphSize; i++) {
        degrees.push_back(in_degree(i, Graph)); 

    }


    return degrees;

}

int main(int argc, char* argv[])
{
    ifstream inFile("../data/rosalind_deg.txt");

   if (! inFile) {
        cerr << "Couldn't read file" << endl;
        return EXIT_FAILURE;
    }

    pair<int, edge_list> szAndEdges = read_edge_list(inFile);

    cout << "Number of vertices read: " << szAndEdges.first << endl;

    vector<int> degrees = deg(szAndEdges.first, szAndEdges.second);
    vector<int>::iterator vecIt;


    for (vecIt = degrees.begin(); vecIt != degrees.end(); vecIt++) {
        cout << *vecIt << " ";
    }
    cout << endl;
    


    return 0;
}
