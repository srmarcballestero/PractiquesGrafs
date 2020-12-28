// NOM: Marc Ballestero Ribó.
// GRUP: M1a.
// DATA d'ENTREGA: 13/01/2021.


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef unsigned int vertex;
typedef unsigned int edge;
typedef unsigned int index;
typedef unsigned int degree;
typedef unsigned int component;
typedef unsigned int length;
typedef unsigned int color;
typedef vector<vector<vertex>> graph;

graph graph_complete(index n);
graph graph_bipartite_complete(index n1, index n2);
graph graph_cycle(index n);
graph graph_star(index n);
graph graph_wheel(index n);
graph graph_knight(index n1, index n2);
graph graph_read(string fname);
void graph_write(graph &G, ofstream &fout);
void chess_graph_write(graph &G, index n1, index n2, ofstream &fout);
bool HamiltonianCycle(graph &G, ofstream &fout);
index HamiltonianCycles(graph &G, ofstream &fout);
color MinimalVertexColoring(graph &G, vector<color> &Gc, ofstream &fout);
