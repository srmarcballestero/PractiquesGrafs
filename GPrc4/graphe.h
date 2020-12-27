// NOM: Marc Ballestero Ribó.
// GRUP: M1a.
// DATA d'ENTREGA: 13/01/2021.


#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

#include "graph.h"

using namespace std;

typedef pair<vertex,index> vip;
typedef map<vip,edge> edges;

void graphe_complete(graph &Kn, edges &KnE, index n);
void graphe_bipartite_complete(graph &Kn1n2, edges &Kn1n2E, index n1, index n2);
void graphe_cycle(graph &Cn, edges &CnE, index n);
void graphe_star(graph &Sn, edges &SnE, index n);
void graphe_wheel(graph &Wn, edges &WnE, index n);
void line_graphe(graph &G, edges &GE, graph &LG, edges &LGE);
void graphe_read(graph &G, edges &GE, string fname);
void graphe_write(graph &G, edges &GE, ofstream &fout);
color MinimalVertexColoring(graph &G, vector<color> &Gc, ofstream &fout);
color MinimalEdgeColoring(graph &G, edges &GE, ofstream &fout);
color LeagueSchedule(graph &G, edges &GE, vector<string> teams, ofstream &fout);
vector<string> Teams(index n);
component BFS(graph &G);
bool Hierholzer(graph &G, edges &GE, ostream &fout);
