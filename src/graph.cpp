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

pair<int, weighted_edge_list>
read_weighted_edge_list(ifstream& inFile)
{
    int source, dest, weight;
    int numVertices, numEdges;

    weighted_edge_list edges;
    vector<int> edge_description(3,0);

    // file starts off with number of vertices
    // and number of edges
    inFile >> numVertices >> numEdges;

    inFile >> source >> dest >> weight;
    while (!inFile.eof()) {
//        cout << "("<<source << ","<< dest <<  "," << weight << ")"<<endl;
        edge_description[0] = source;
        edge_description[1] = dest;
        edge_description[2] = weight;
        edges.push_back(edge_description);

        inFile >> source >> dest >> weight;
    }
    edge_description[0] = source;
    edge_description[1] = dest;
    edge_description[2] = weight;
    edges.push_back(edge_description);

    return make_pair(numVertices, edges);
}

