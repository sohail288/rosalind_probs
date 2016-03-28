#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <String>
#include <utility>
using namespace std;

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <boost/graph/visitors.hpp>
using namespace boost;

#include "graph.h"


/* The reason I am doing -1 for every vertex in the distance array is because
   the relationship between a vertex i and its place in the vector is i --> i -1
*/


typedef adjacency_list< vecS, vecS, directedS > graph_t;

// create the distance recorder
template <typename DistanceMap>
class v_distance_recorder : public default_bfs_visitor
{
public:
    v_distance_recorder(DistanceMap dist) : d(dist) {}
    template <typename Edge, typename Graph>
    void tree_edge(Edge e, const Graph& g) const
    {
        typename graph_traits<Graph>::vertex_descriptor
            u = source(e, g), v = target(e, g);
            d[v-1] = d[u-1] + 1;

    }
private:
    DistanceMap d;
};

template <typename DistanceMap>
v_distance_recorder<DistanceMap>
v_record_distance(DistanceMap d)
{
    return v_distance_recorder<DistanceMap>(d);
}


void
bfs(graph_t graph, int source, vector<int>& distances)
{
    // get source
    graph_traits<graph_t>::vertex_descriptor s = vertex(source, graph);

    distances[source - 1] = 0;
    
    breadth_first_search(graph, s, visitor(v_record_distance(&distances[0])));
}

void
make_graph(graph_t* graph, edge_list edges)
{
    edge_list::iterator edgeIt;

    for (edgeIt = edges.begin(); edgeIt != edges.end(); edgeIt++) {
        add_edge((*edgeIt).first, (*edgeIt).second, *graph);
    }

}

int main(int argc, char* argv[])
{
    ifstream inFile("../data/rosalind_bfs.txt");

   if (! inFile) {
        cerr << "Couldn't read file" << endl;
        return -1;
    }

    pair<int, edge_list> graphSzAndEdges = read_edge_list(inFile);
    
    // init all to inf
    vector<int> distances(graphSzAndEdges.first, -1);
    

    graph_t graph(graphSzAndEdges.first);

    make_graph(&graph, graphSzAndEdges.second);
    

    cout << "doing bfs" << endl;
    bfs(graph, 1, distances);

    cout << "outputting the distances" << endl;

    for(vector<int>::iterator distanceIt = distances.begin();
       distanceIt != distances.end();
       distanceIt++) {
        cout << *distanceIt << " ";
    }
    cout << endl;



    return 0;
}
