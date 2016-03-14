#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <String>
#include <vector>
using namespace std;

#include <boost/graph/adjacency_list.hpp>
using namespace boost;

#include "graph.h"

typedef adjacency_list< listS, vecS, undirectedS > graph_t;

void
ddeg(graph_t& graph, vector<int>& double_degrees)
{
    // use adjacent_vertices(v, g) to access the
    // adjacent vertices

    // use vertices to go through every vertex in the graph
    graph_traits<graph_t>::vertex_iterator vi, vi_end;
    graph_traits<graph_t>::adjacency_iterator ai, ai_end;
    graph_traits<graph_t>::adjacency_iterator di, di_end;

    // i'm guessing tie unpacks the pair tuple
    for (tie(vi, vi_end) = vertices(graph); vi != vi_end; ++vi) {
        for (tie(ai, ai_end) = adjacent_vertices(*vi, graph);
             ai != ai_end;
             ai++) {
            for (tie(di, di_end) = adjacent_vertices(*ai, graph);
                 di != di_end;
                 di++) {
                ++double_degrees[*vi - 1];
            }
        }  

    }
}

void
make_graph(graph_t* graph, edge_list& edges)
{
    edge_list::iterator edgeIt;
    
    for (edgeIt = edges.begin(); edgeIt != edges.end(); edgeIt++) {
        add_edge((*edgeIt).first, (*edgeIt).second, *graph);
    }
}

int main(int argc, char* argv[])
{
    ifstream inFile("../data/rosalind_ddeg.txt");

   if (! inFile) {
        cerr << "Couldn't read file" << endl;
        return -1;
    }

    pair<int, edge_list> graphSzAndEdges = read_edge_list(inFile);
    graph_t graph(graphSzAndEdges.first);

    make_graph(&graph, graphSzAndEdges.second);
    
    vector<int> double_degrees(graphSzAndEdges.first);

    cout << "ddeg" << endl;
    ddeg(graph, double_degrees);

    cout << "graph has vertices: " << num_vertices(graph)
         << "Edges: " << num_edges(graph)
         <<  endl;

    for(vector<int>::iterator it = double_degrees.begin();
         it != double_degrees.end();
         it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
