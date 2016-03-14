#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <String>
#include <vector>
#include <utility>
using namespace std;


#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/connected_components.hpp>
using namespace boost;

#include "graph.h"

typedef adjacency_list< listS, vecS, undirectedS > graph_t;

int
cc(graph_t& graph)
{
    vector<int> components(num_vertices(graph));

    int numComponents = connected_components(graph, &components[0]);

    return numComponents;
}

void
make_graph(graph_t* graph, edge_list edges)
{
    edge_list::iterator edgeIt;
    
    for (edgeIt = edges.begin(); edgeIt != edges.end(); edgeIt++) {
        add_edge((*edgeIt).first -1, (*edgeIt).second  - 1, *graph);
    }
}

int main(int argc, char* argv[])
{
    ifstream inFile("../data/rosalind_cc.txt");

   if (! inFile) {
        cerr << "Couldn't read file" << endl;
        return -1;
    }
    
    pair<int, edge_list> graphSzAndEdges = read_edge_list(inFile);
    graph_t graph(graphSzAndEdges.first);
    make_graph(&graph, graphSzAndEdges.second);

    cout << cc(graph) << endl;

    return 0;
}
