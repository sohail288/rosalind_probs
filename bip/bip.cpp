/*
Given: A positive integer k≤20k≤20 and kk simple graphs in the edge list format with at most 103103 vertices each.

Return: For each graph, output "1" if it is bipartite and "-1" otherwise.

*/
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <String>
using namespace std;

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <boost/graph/visitors.hpp>
using namespace boost;

#include "graph.h"

typedef adjacency_list< vecS, vecS, undirectedS > graph_t;

// store each graph in this vector
typedef vector< graph_t > graph_vector;

void
bip()
{


}


void read_data(ifstream& inFile, int& k, graph_vector& graphs)
{
    inFile >> k;
    graphs.resize(k);
    string ln;
    int u,v;
    char ch;
    istringstream lnstream;

    graph_t tempGraph;

    // ignore first empty space
    inFile.get(ch);
    getline(inFile, ln);
    while (!inFile.eof()) {
        getline(inFile, ln);
        lnstream.str(ln);
        if (ln.empty()) {
            cout << "created new graph" << endl;
            graphs.push_back(tempGraph); 
            tempGraph.clear();
        } else {
            lnstream >> u >> v;
            cout << u << " " << v << endl;
            add_edge(u, v, tempGraph);
            lnstream.str("");
            lnstream.clear();
            
        }
    }

}

int main(int argc, char* argv[])
{
    ifstream inFile("../data/rosalind_bip.txt");
    int k;
    graph_vector graphs;

   if (! inFile) {
        cerr << "Couldn't read file" << endl;
        return -1;
    }

    read_data(inFile, k, graphs); 

    cout << "Types are alright" << endl;
    cout << k << endl;

    cout << "checking if graphs read properly" << endl;
    graph_traits<graph_t>::vertex_iterator vi, vi_end;
    graph_vector::iterator graphIt;

    cout << graphs.size() << endl;
    for (graphIt = graphs.begin(); graphIt != graphs.end(); graphIt++){
        cout << 1 << endl;
        for (tie(vi,vi_end) = vertices(*graphIt); vi != vi_end; vi++)  {
            cout << 0  << endl;
        }
    }

    return EXIT_SUCCESS;
}
