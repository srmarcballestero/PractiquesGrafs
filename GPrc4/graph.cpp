// NOM: Marc Ballestero Ribó.
// GRUP: M1a.
// DATA d'ENTREGA: 13/01/2021.


#include "graph.h"

//
// Complete graph with vn vertices to adjacencies lists.
//
graph graph_complete (index n)
{
  vertex vn = n;
  graph Kn (vn);
  for (vertex v = 0; v < vn; ++v)
    for (vertex u = v+1; u < vn; ++u) {
      Kn[v].push_back(u);
      Kn[u].push_back(v);
    }

  return Kn;
}

//
// Bipartite complete graph with partitions of vn1 and vn2 vertices to adjacencies lists.
//
graph graph_bipartite_complete (index n1, index n2)
{
  vertex vn = n1 + n2;
  graph Kn1n2(vn);

  for (vertex v = 0; v < n1; ++v)
    for (vertex u = n1; u < vn; ++u) {
      Kn1n2[v].push_back(u);
      Kn1n2[u].push_back(v);
    }

  return Kn1n2;
}

//
// Cycle graph with vn vertices to adjacencies lists.
//
graph graph_cycle (index n)
{
  vertex vn = n;
  graph Cn(vn);

  for (vertex v = 0; v < n-1; ++v) {
    Cn[v].push_back(v+1);
    Cn[v+1].push_back(v);
  }
  Cn[n-1].push_back(0);
  Cn[0].push_back(n-1);

  return Cn;
}

//
// Star graph with vn vertices to adjacencies lists.
//
graph graph_star(index n)
{
  vertex vn = n+1;
  graph Sn(vn);

  for (vertex v = 0; v < n; ++v) {
    Sn[v].push_back(n);
    Sn[n].push_back(v);
  }

  return Sn;
}

//
// Wheel graph with vn vertices to adjacencies lists.
//
graph graph_wheel(index n)
{
  vertex vn = n+1;
  graph Wn(vn);

  for (vertex v = 0; v < n-1; ++v) {
    Wn[v].push_back(v+1);
    Wn[v+1].push_back(v);
  }
  Wn[n-1].push_back(0);
  Wn[0].push_back(n-1);

  for (vertex v = 0; v < n; ++v) {
    Wn[v].push_back(n);
    Wn[n].push_back(v);
  }

  return Wn;
}


//
// Knight graph in n1xn2 chessboard: Ktn1n2.
//
graph graph_knight(index n1, index n2)
{
  graph Ktn1n2(n1*n2);

  for (index i1 = 0; i1 < n1; ++i1)
    for (index i2 = 0; i2 < n2; ++i2) {
      vertex v = i1*n2 + i2;

      if (i1 < n1-1 && i2 < n2-2) {
          Ktn1n2[v].push_back(v+n2+2);
          Ktn1n2[v+n2+2].push_back(v);
      }
      if (i1 < n1-1 && i2 > 1) {
          Ktn1n2[v].push_back(v+ n2-2);
          Ktn1n2[v+n2-2].push_back(v);
      }
      if (i1 < n1-2 && i2 < n2-1) {
          Ktn1n2[v].push_back(v + 2*n2 + 1);
          Ktn1n2[v + 2*n2 + 1].push_back(v);
      }
      if (i1 < n1-2 && i2 > 0) {
          Ktn1n2[v].push_back(v + 2*n2 - 1);
          Ktn1n2[v + 2*n2 - 1 ].push_back(v);
      }
    }

  return Ktn1n2;
}


//
// Read from file fname of edges to adjacencies lists.
//
graph graph_read (string fname)
{
  ifstream fin;
  fin.open(fname.c_str());
  if (fin.fail()) {
    cerr << "unable to open file " << fname.c_str() << " for reading" << endl;
    exit(1);
  }

  vertex vn;
  edge en;

  fin >> vn >> en;

  graph G(vn);

  for (edge e = 0; e < en; ++e) {
    vertex v, u;
    fin >> v >> u;
    G[v].push_back(u);
    if (u != v)
      G[u].push_back(v);
  }

  return G;
}

//
// Write from adjacencies lists to stream
//
void graph_write(graph &G, ofstream &fout)
{
  vertex vn = G.size();
  edge en = 0;

  for (vertex v = 0; v < vn; ++v) {
    en += G[v].size();
    for (index i = 0; i < G[v].size(); ++i)
      if (G[v][i] == v)
        ++en;
  }
  en /= 2;

  fout << "Graph with " << vn << " vertices and " << en << " edges" << endl;

  fout << "Adjacencies lists" << endl;
  for (vertex v = 0; v < vn; ++v) {
    fout << v << "\t:";
    for (index i = 0; i < G[v].size(); ++i)
      fout << "\t" << G[v][i];
    fout << endl;
  }

  fout << "Edges" << endl;
  for (vertex v = 0; v < vn; ++v)
    for (index i = 0; i < G[v].size(); ++i)
      if (v <= G[v][i])
        fout << v << "-" << G[v][i] << endl;

}

//
// Write chess graph from adjacencies lists to stream
//
void chess_graph_write(graph &G, index n1, index n2, ofstream &fout)
{
  vertex vn = G.size();

  edge en = 0;
  for (vertex v = 0; v < vn; ++v) {
    en += G[v].size();
    for (index i = 0; i < G[v].size(); ++i)
      if (G[v][i] == v)
        ++en;
  }
  en /= 2;

  fout << "Graph with " << vn << " vertices and " << en << " edges " << endl;

  fout << "Adjacencies lists" << endl;
  for (vertex v = 0; v < vn; ++v) {
    fout << "(" << v/n2 << ", " << v%n2 << ")" << "\t:";
    for (index i = 0; i < G[v].size(); ++i)
      fout << "\t" << "(" << G[v][i]/n2 << ", " << G[v][i]%n2 << ")";
    fout << endl;
  }

  fout << endl << "Edges" << endl;
  for (index i1 = 0; i1 < n1; ++i1)
    for (index i2 = 0; i2 < n2; ++i2) {
      vertex v = i1*n2 + i2;
      for (index k = 0; k < G[v].size(); ++k)
        if (v < G[v][k] + 1)
          fout << "(" << i1 << "," << i2 << ")" << "-" << "(" << G[v][k]/n2 <<
            "," << G[v][k]%n2 << ")" << endl;
    }

  fout << endl << "Degrees matrix" << endl;
  for (index i1 = 0; i1 < n1; ++i1) {
      for (index i2 = 0; i2 < n2; ++i2)
          fout << G[i1*n2 + i2].size() << "\t";
      fout << endl;
  }

}
