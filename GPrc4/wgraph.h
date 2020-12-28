// NOM: Marc Ballestero Ribó.
// GRUP: M1a.
// DATA d'ENTREGA: 13/01/2021.

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

#include "graph.h"

#define W_MAX 9

using namespace std;

typedef unsigned int vertex;
typedef unsigned int index;
typedef unsigned int edge;
typedef unsigned int weight;
typedef vector<vector<pair<vertex,weight>>> wgraph;

wgraph wgraph_complete(index n, weight Mw);
wgraph wgraph_bipartite_complete(index n1, index n2, weight Mw);
wgraph wgraph_cycle(index n, weight Mw);
wgraph wgraph_star(index n, weight Mw);
wgraph wgraph_wheel(index n, weight Mw);
wgraph wgraph_read(string fname);
void wgraph_write(wgraph &G, ofstream &fout);
graph WgraphToGraph(wgraph &WG);
index HamiltonianCycles(wgraph &G, ofstream &fout);
weight TravellingSalesmanProblem(wgraph &G, ofstream &fout);
