// NOM: Marc Ballestero Ribó.
// GRUP: M1a.
// DATA d'ENTREGA: 28/11/2020.

#include "graph.h"

//
// Breadth First Search: returns components/trees number.
//
component BFS(graph &G)
{
  vertex vn = G.size();
  component Tn = 0;

  vector<vertex> BFSv(vn);
  vector<bool> BFSl(vn, false);
  index BFSn = 0;

  for (vertex rv = 0; rv < vn; ++rv)
    if (!BFSl[rv]) {
      index BFSi = BFSn;
      ++Tn;

      BFSl[rv] = true;
      BFSv[BFSn++] = rv;
      if (G[rv].size())
        do {
          vertex v = BFSv[BFSi++];
          for (index i = 0; i < G[v].size(); ++i)
            if (!BFSl[G[v][i]]) {
              BFSl[G[v][i]] = true;
              BFSv[BFSn++] = G[v][i];
            }
        } while (BFSi < BFSn);
      }

  return Tn;
}

component BFS_Trees(graph &G, ofstream &fout)
{
  vertex vn = G.size();
  component Tn = 0;

  vector<vertex> BFSv(vn);      // Vertexs
  vector<index> BFSind(vn);     // Indices
  vector<vertex> BFSp(vn, vn);  // Parents
  vector<length> BFSd(vn);      // Depths

  index BFSn = 0; // List index
  for (vertex rv = 0; rv < vn; ++rv)
    if (BFSp[rv] == vn) {
      index BFSi = BFSn;
      ++Tn;
      BFSind[rv] = BFSn;
      BFSp[rv] = rv;
      BFSd[rv] = 0;
      BFSv[BFSn++] = rv;
      if (G[rv].size())
        do {
          vertex v = BFSv[BFSi++];
          for (index i = 0; i < G[v].size(); ++i)
            if (BFSp[G[v][i]] == vn) {
              BFSind[G[v][i]] = BFSn;
              BFSp[G[v][i]] = v;
              BFSd[G[v][i]] = BFSd[v] + 1;
              BFSv[BFSn++] = G[v][i];
            }
        } while (BFSi < BFSn);
    }

  fout << "BFS" << endl;
  for (vertex v = 0; v < vn; ++v) {
    fout << "Vertex " << v << ":" << endl;
    fout << "Index:\t" << BFSind[v] << endl;
    fout << "Parent:\t" << BFSp[v] << endl;
    fout << "Depth:\t" << BFSd[v] << endl;
  }

  fout << "Edges" << endl;
  for (vertex v = 0; v < vn; ++v)
    for (index i = 0; i < G[v].size(); ++i)
      if (v <= G[v][i]) {
        fout << v << "-" << G[v][i];
        if (BFSp[G[v][i]] == v || BFSp[v] == G[v][i])
          fout << " IN spanning tree " << endl;
        else
          fout << " NOT IN spanning tree" << endl;
        }

  return Tn;
}
