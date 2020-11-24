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

//
// Save BFS trees and send info about vertices and edges to ofstream.
//
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
  fout << "Number of BFS components: " << Tn << endl;
  fout << "v\tIndex\tParent\tDepth" << endl;
  for (vertex v = 0; v < vn; ++v)
    fout << v << "\t\t" << BFSind[v] << "\t\t\t" << BFSp[v] << "\t\t\t\t" << BFSd[v] << endl;

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

//
// Recursive function for DFS from v.
//
void DFS (graph &G, vector<bool> &DFSl, vertex v)
{
  for (index i = 0; i < G[v].size(); ++i)
    if (!DFSl[G[v][i]]) {
      DFSl[G[v][i]] = true;
      DFS(G, DFSl, G[v][i]);
    }
}

//
// Depth first search: returns components/trees number.
//
component DFS(graph &G)
{
  vertex vn = G.size();
  component Tn = 0;
  vector<bool> DFSl(vn, false);

  for (vertex rv = 0; rv < vn; ++rv)
    if (!DFSl[rv]) {
      ++Tn;
      DFSl[rv] = true;
      DFS(G, DFSl, rv);
    }

  return Tn;
}

//
// Recursive function for DFS from v.
//
void DFS_Trees(graph &G, index &DFSn, vector<index> &DFSind, vector<vertex> &DFSp,
  vector<length> &DFSd, vertex v)
{
  vertex vn = G.size();

  for (index i = 0; i < G[v].size(); ++i)
    if (DFSp[G[v][i]] == vn) {
      DFSp[G[v][i]] = v;
      DFSind[G[v][i]] = DFSn++;
      DFSd[G[v][i]] = DFSd[v] + 1;
      DFS_Trees(G, DFSn, DFSind, DFSp, DFSd, G[v][i]);
    }
}

//
// Depth First Search: returns components/trees number.
//
component DFS_Trees(graph &G, ofstream &fout)
{
  vertex vn = G.size();
  component Tn = 0;

  vector<vertex> DFSp(vn, vn);
  vector<index> DFSind(vn);
  vector<length> DFSd(vn);

  index DFSn = 0;
  for (vertex rv = 0; rv < vn; ++rv)
    if (DFSp[rv] == vn) {
      ++Tn;
      DFSp[rv] = rv;
      DFSind[rv] = DFSn++;
      DFSd[rv] = 0;
      DFS_Trees(G, DFSn, DFSind, DFSp, DFSd, rv);
    }

  fout << "DFS" << endl;
  fout << "Number of DFS components: " << Tn << endl;
  fout << "v\tIndex\tParent\tDepth" << endl;
  for (vertex v = 0; v < vn; ++v)
    fout << v << "\t\t" << DFSind[v] << "\t\t\t" << DFSp[v] << "\t\t\t\t" << DFSd[v] << endl;

  fout << "Edges" << endl;
  for (vertex v = 0; v < vn; ++v)
    for (index i = 0; i < G[v].size(); ++i)
      if (v <= G[v][i]) {
        fout << v << "-" << G[v][i];
        if (DFSp[G[v][i]] == v || DFSp[v] == G[v][i])
          fout << " IN spanning tree " << endl;
        else
          fout << " NOT IN spanning tree" << endl;
        }
  return Tn;
}

//
//  Minimal path lengths by Dijkstra's method to stream
//  - Distances to all vertices: lengths of minimal paths
//
void Dijkstra(graph &G, vertex sv, ofstream &fout)
{
  vertex vn = G.size();
  vector<bool> Dl(vn, false);

  length infty = UINT_MAX;
  vector<length> Dd(vn, infty);
  Dd[sv] = 0;

  vertex mdv = sv;
  do {
    Dl[mdv] = true;
    for (index i = 0; i < G[mdv].size(); ++i)
      if (Dd[G[mdv][i]] > Dd[mdv]+1)
        Dd[G[mdv][i]] = Dd[mdv] + 1;

    length md = infty;
    mdv = vn;
    for (vertex v = 0; v < vn; ++v)
      if (md > Dd[v] && !Dl[v]) {
        md = Dd[v];
        mdv = v;
      }
  } while (mdv < vn);

  fout << "Distances from starting vertex " << sv << endl;
  for (vertex v = 0; v < vn; ++v)
    if (Dd[v] < infty)
      fout << v << "\t" << Dd[v] << endl;
    else
      fout << v << "\tNot connected" << endl;

}

//
//  Minimal chess graph path lengths by Dijkstra's method to stream
//  - Distances to all vertices: lengths of minimal paths
//
void chess_Dijkstra(graph &G, index n1, index n2, index s1, index s2, ofstream &fout)
{
  vertex vn = G.size();
  vector<bool> Dl(vn, false);

  length infty = UINT_MAX;
  vector<length> Dd(vn, infty);

  vertex sv = s1*n2 + s2;
  Dd[sv] = 0;

  vertex mdv = sv;
  do {
    Dl[mdv] = true;

    for (index i = 0; i < G[mdv].size(); ++i)
      if (Dd[G[mdv][i]] > Dd[mdv]+1)
        Dd[G[mdv][i]] = Dd[mdv] + 1;

    length md = infty;
    mdv = vn;
    for (vertex v = 0; v < vn; ++v)
      if (md > Dd[v] && !Dl[v]) {
        md = Dd[v];
        mdv = v;
      }
  } while (mdv < vn);

  fout << "Distances matrix from starting square (" << sv/n2 << "," << sv%n2 <<
    ")" << endl;
  for (index i1 = 0; i1 < n1; ++i1) {
      for (index i2 = 0; i2 < n2; ++i2)
        if (Dd[i1*n2 + i2] == infty)
          fout << "n/d" << "\t";
        else
          fout << Dd[i1*n2 + i2] << "\t";
      fout << endl;
  }

}
