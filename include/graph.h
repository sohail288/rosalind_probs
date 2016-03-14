#ifndef _GRAPH_H
#define _GRAPH_H

#include <fstream>
#include <utility>
#include <vector>
#include <iostream>
using namespace std;

typedef vector<pair<int,int> > edge_list;

pair<int, edge_list>
read_edge_list(ifstream& inFile);

//template<class graphType>
//void
//make_graph(graphType* graph,  edge_list edges);

#endif
