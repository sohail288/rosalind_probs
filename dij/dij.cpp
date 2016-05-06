#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <String>
#include <utility>
#include <vector>
#include <limits>
using namespace std;

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
using namespace boost;

#include "graph.h"


typedef adjacency_list< vecS, 
                        vecS, 
                        directedS,
                        // vertex properties
                        property<vertex_distance_t, int>,
                        // edge properties
                        property<edge_weight_t, int>
    >  graph_t;

typedef graph_traits<graph_t>::vertex_descriptor vertex_descriptor;
typedef property_map<graph_t, vertex_distance_t>::type distance_map_t;
typedef property_map<graph_t, edge_weight_t>::type weight_map_t;


const int INF = numeric_limits<int>::max();


const int SOURCE = 1;

void
dij(graph_t& graph, int source, vector<int>& distances)
{
    // get source
    vertex_descriptor s = vertex(source, graph); 

    // would this still work?
    distances[source - 1] = 0;

    dijkstra_shortest_paths(graph, s, distance_map(&distances[0]));
}

void
make_graph(graph_t* graph, weighted_edge_list& edges)
{
    weighted_edge_list::iterator edgeIt;
    
    
    for (edgeIt = edges.begin();
             edgeIt != edges.end(); 
             edgeIt++) {
        property<edge_weight_t, int> edge_property((*edgeIt)[2]);
        
//        cout << (*edgeIt)[0] << " " << (*edgeIt)[1] << " " << (*edgeIt)[2]
//             << endl;

        // add the edge property to the graph along with edge
        // minus one for mapping
        add_edge((*edgeIt)[0], (*edgeIt)[1], edge_property,  *graph);

    }
}

int main(int argc, char* argv[])
{
    ifstream inFile("../data/rosalind_dij.txt");

   if (! inFile) {
        cerr << "Couldn't read file" << endl;
        return -1;
    }

    pair<int, weighted_edge_list> graphSzAndEdges = read_weighted_edge_list(
        inFile
    );
    

    vector<int> distances(graphSzAndEdges.first + 1);
    graph_t graph(graphSzAndEdges.first);

    // property getters
    weight_map_t weight_map = get(edge_weight, graph); 
    distance_map_t distance_map = get(vertex_distance, graph);

    make_graph(&graph, graphSzAndEdges.second);
    
    cout << "doing dij" << endl;
    dij(graph, SOURCE, distances);

    cout << "INF: " << INF << endl;
    cout << "outputting shortest paths" << endl;
    for (vector<int>::iterator distanceIt = distances.begin();
         distanceIt != distances.end();
         distanceIt++) {
        cout << ((*distanceIt == INF)? -1 : *distanceIt) << " ";
    }
    cout << endl;

//    cout << "distances" << endl;
//    graph_traits<graph_t>::vertex_iterator vi, vi_end;
//    for(tie(vi, vi_end) = vertices(graph); vi != vi_end; ++vi) {
//        cout << (distances[*vi] ) << " "; 
//    }
//    cout << endl;

    return EXIT_SUCCESS;
}
