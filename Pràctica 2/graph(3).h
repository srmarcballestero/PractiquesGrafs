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
 typedef unsigned int length;
 typedef vector<vector<vertex> > graph;
 graph graph_complete( index n );
 graph graph_cycle(index n);
 graph graph_star(index n);
 graph graph_wheel(index n);
 graph graph_king(index n1, index n2);
 graph graph_knight(index n1, index n2);
 graph graph_read( string fname );
 void graph_write(  graph& G, ofstream& fout );
 void chess_graph_write(graph& G, index n1, index n2, ofstream& fout);
 component BFS( graph &G );
 component DFS( graph &G );
 void Dijkstra( graph &G, vertex sv, ofstream& fout );
 void chess_Dijkstra(graph& G, index n1, index n2, index i1, index i2, ofstream& fout);
 component BFS_Trees(graph& G, ofstream& fout);
 component DFS_Trees(graph& G, ofstream& fout);

 
 