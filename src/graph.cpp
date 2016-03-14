#include <boost/graph/adjacency_list.hpp>
#include "graph.h"

pair<int, edge_list>
read_edge_list(ifstream& inFile)
{

    int source, dest;
    int numVertices;
    int numEdges;
    edge_list edges;
    

    inFile >> numVertices;
    inFile >> numEdges;
    inFile >> source >> dest;    
    while (!inFile.eof()) {
        cout << "("<<source << ","<< dest << ")"<<endl;
        edges.push_back(make_pair(source, dest)); 
        inFile >> source >> dest;    
    }

    return make_pair(numVertices, edges);
    

}


//template<class graphType>
//void
//make_graph(graphType* graph, edge_list edges)
//{
//    edge_list::iterator edgeIt;
//
//    for (edgeIt = edges.begin(); edgeIt != edges.end(); edgeIt++) {
//        add_edge((*edgeIt).first, (*edgeIt).second, *graph);
//    }
//
//}
