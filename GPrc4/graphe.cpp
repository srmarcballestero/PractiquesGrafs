// NOM: Marc Ballestero Ribó.
// GRUP: M1a.
// DATA d'ENTREGA: 13/01/2021.


#include "graphe.h"

//
// Complete graph to adjacencies lists and mapped edges.
//
void graphe_complete(graph &Kn, edges &KnE, index n)
{
  vertex vn = n;
  Kn = graph(vn);
  edge e = 0;

  for (vertex v = 0; v < vn; ++v)
    for (vertex u = v+1; u < vn; ++u) {
      KnE[vip(v, Kn[v].size())] = e;
      KnE[vip(u, Kn[u].size())] = e++;
      Kn[v].push_back(u);
      Kn[u].push_back(v);
    }
}


//
// Bipartite complete graph to adjacencies lists and mapped edges.
//
void graphe_bipartite_complete(graph &Kn1n2, edges &Kn1n2E, index n1, index n2)
{
  vertex vn = n1+n2;
  Kn1n2 = graph(vn);
  edge e = 0;

  for (vertex v = 0; v < n1; ++v)
    for (vertex u = n1; u < vn; ++u) {
      Kn1n2E[vip(v, Kn1n2[v].size())] = e;
      Kn1n2E[vip(u, Kn1n2[u].size())] = e++;
      Kn1n2[v].push_back(u);
      Kn1n2[u].push_back(v);
    }
}

//
// Cycle graph to adjacencies lists and mapped edges.
//
void graphe_cycle(graph &Cn, edges &CnE, index n)
{
  vertex vn = n;
  Cn = graph(vn);
  edge e = 0;

  CnE[vip(0, 0)] = e;
  CnE[vip(1, 0)] = e++;
  Cn[0].push_back(1);
  Cn[1].push_back(0);

  for (vertex v = 1; v < vn-1; ++v) {
    CnE[vip(v, 1)] = e;
    CnE[vip(v+1, 0)] = e++;
    Cn[v].push_back(v+1);
    Cn[v+1].push_back(v);
  }

  CnE[vip(vn-1, 1)] = e;
  CnE[vip(0,1)] = e++;
  Cn[vn-1].push_back(0);
  Cn[0].push_back(vn-1);

}

//
// Star graph to adjacencies lists and mapped edges.
//
void graphe_star(graph &Sn, edges &SnE, index n)
{
  vertex vn = n+1;
  Sn = graph(vn);
  edge e = 0;

  for (vertex v = 0; v < vn-1; ++v) {
    SnE[vip(v, Sn[v].size())] = e;
    SnE[vip(vn-1, Sn[v].size())] = e++;
    Sn[v].push_back(vn-1);
    Sn[vn-1].push_back(v);
  }

}

//
// Wheel graph to adjacencies lists and mapped edges.
//
void graphe_wheel(graph &Wn, edges &WnE, index n)
{
  vertex vn = n+1;
  Wn = graph(vn);
  edge e = 0;

  for (vertex v = 1; v < vn; ++v) {
    WnE[vip(0, Wn[0].size())] = e;
    WnE[vip(v, Wn[v].size())] = e++;
    Wn[v].push_back(0);
    Wn[0].push_back(v);
  }

  for (vertex v = 1; v < vn; ++v) {
    WnE[vip(v, Wn[v].size())] = e;
    WnE[vip(v+1, Wn[v+1].size())] = e++;
    Wn[v].push_back(v+1);
    Wn[v+1].push_back(v);
  }

  WnE[vip(1, Wn[1].size())] = e;
  WnE[vip(vn-1, Wn[vn-1].size())] = e++;
  Wn[1].push_back(vn-1);
  Wn[vn-1].push_back(1);
}

//
// Line graph: graph of edges as vertices, adjacencies of edges: other edges with a common vertex.
//
void line_graphe(graph &G, edges &GE, graph &LG, edges &LGE)
{
  vertex vn = G.size();
  edge en = 0;

  for (vertex v = 0; v < vn; ++v)
    for (index i = 0; i < G[v].size(); ++i)
      if (v < G[v][i])
        ++en;

  LG = graph(en);
  edge ei, ek, le = 0;
  for (vertex v = 0; v < vn; ++v)
    for (index i = 0; i < G[v].size(); ++i)
      if (v < G[v][i]) {
        ei = GE[vip(v, i)];

        for (index k = 0; k < G[v].size(); ++k){
          ek = GE[vip(v, k)];
          if (ek > ei) {
            LGE[vip(ei, LG[ei].size())] = le;
            LGE[vip(ek, LG[ek].size())] = le++;
            LG[ei].push_back(ek);
            LG[ek].push_back(ei);
          }
        }

        vertex u = G[v][i];
        for (index k = 0; k < G[u].size(); ++k) {
          edge ek = GE[vip(u, k)];
          if (ek > ei) {
            LGE[vip(ei, LG[ei].size())] = le;
            LGE[vip(ek, LG[ek].size())] = le++;
            LG[ei].push_back(ek);
            LG[ek].push_back(ei);
          }
        }
      }

}


//
// Read from file fname of edges to adjacencies lists.
//
void graphe_read(graph &G, edges &GE, string fname)
{
  ifstream fin;
  fin.open(fname.c_str());
  if (fin.fail()) {
    cerr << "Unable to read from file " << fname.c_str() << endl;
    exit(1);
  }

  vertex vn;
  edge en;
  fin >> vn >> en;
  G = graph(vn);
  for (edge e = 0; e < en; ++e) {
    vertex u, v;
    fin >> v >> u;
    GE[vip(v, G[v].size())] = e;
    G[v].push_back(u);
    if (u != v) {
      GE[vip(u, G[u].size())] = e;
      G[u].push_back(v);
    }
  }
}

//
// Write graphe form adjacencies lists to stream.
//
void graphe_write(graph &G, edges &GE, ofstream &fout)
{
  vertex vn = G.size();
  edge en = 0;

  for (vertex v = 0; v < vn; ++v)
    for (index i = 0; i < G[v].size(); ++i)
      if (v < G[v][i])
        ++en;

}
