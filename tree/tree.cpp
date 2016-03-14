#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <String>
#include <vector>
using namespace std;

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/connected_components.hpp>
using namespace boost;

#include "graph.h"

typedef adjacency_list< listS, vecS, undirectedS > graph_t;

// for this one
// i did -1 because for some reason if 10 is included
// I get 11 vertices instead of 10

int
tree(graph_t& graph)
{
    vector<int> components(num_vertices(graph));
    cout << "graph has vertices : " << num_vertices(graph)
         << "graph has edges   : " << num_edges(graph)
         << endl;

    int numComponents = connected_components(graph, &components[0]);

    return numComponents - 1;
}

void
make_graph(graph_t* graph, edge_list& edges)
{
    edge_list::iterator edgeIt;
    
    for (edgeIt = edges.begin(); edgeIt != edges.end(); edgeIt++) {
        add_edge((*edgeIt).first - 1, (*edgeIt).second - 1, *graph);
    }
}

int main(int argc, char* argv[])
{
    ifstream inFile("../data/rosalind_tree.txt");

   if (! inFile) {
        cerr << "Couldn't read file" << endl;
        return -1;
    }

    pair<int, edge_list> graphSzAndEdges = read_edge_list(inFile); 
    graph_t graph(graphSzAndEdges.first);
    cout << "read " << graphSzAndEdges.first << " edges" << endl;
    make_graph(&graph, graphSzAndEdges.second);

    cout << tree(graph) << endl;

    return 0;
}

