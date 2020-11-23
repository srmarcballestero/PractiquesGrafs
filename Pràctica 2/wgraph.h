#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned int vertex;
typedef unsigned int edge;
typedef unsigned int index;
typedef unsigned int degree;
typedef unsigned int component;
typedef unsigned int weight;
typedef vector<vector<pair<vertex,weight>>> wgraph;
wgraph wgraph_complete( index n,  weight Mw );
wgraph wgraph_bipartite_complete(index n1, index n2, weight Mw);
wgraph wgraph_cycle(index n, weight Mw);
wgraph wgraph_star(index n, weight Mw);
wgraph wgraph_wheel(index n, weight Mw);
wgraph wgraph_read( string fname );
void wgraph_write(  wgraph& G, ofstream& fout );
weight	Dijkstra(wgraph& G, vertex sv, vertex tv);
weight Dijkstra(wgraph& G, vertex sv);
weight Diameter(wgraph& G);
void 	 Dijkstra(wgraph& G, vertex sv, ofstream& fout);
void Dijkstra_Tree(wgraph& G, vertex sv, ofstream& fout);
weight KruskalTrees(wgraph& G, ofstream& fout);
weight PrimTrees(wgraph& G, ofstream& fout);
