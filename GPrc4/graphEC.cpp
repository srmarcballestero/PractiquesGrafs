// NOM: Marc Ballestero Ribó.
// GRUP: M1a.
// DATA d'ENTREGA: 13/01/2021.

#include "graphe.h"

//
// Eulerian cycles by Hierholzer method.
//
bool Hierholzer(graph &G, edges &GE, ofstream &fout)
{
  vertex vn = G.size();
  edge en = GE.size() / 2;  // Assume NO loops

  for (vertex v = 0; v < vn; ++v)
    if (G[v].size() % 2) {
      fout << "Vertex " << v << " has odd degree, so the graph is not eulerian." << endl << endl;
      return false;
    }

  if (BFS(G) > 1) {
    fout << "Graph is not connected, so it is not eulerian." << endl << endl;
    return false;
  }

  vector<vertex> ECv(en+1, vn);
  ECv[0] = 0;

  vector<bool> Gl(en, false);
  edge ei = 0;

  vector<degree> rdeg(vn);
  for (vertex v = 0; v < vn; ++v)
    rdeg[v] = G[v].size();

  vertex v0;
  index i;
  do {
    for (i = 0; i < en+1; ++i)
      if (rdeg[ECv[i]] > 0) {
        v0 = ECv[i];
        break;
      }

    vector<vertex> auxECv(en+1);
    auxECv = ECv;
    for (index j = 0; j < ei-i; ++j)
      ECv[j] = auxECv[i+j];
    for (index j = ei-i; j < ei+1; ++j)
      ECv[j] = auxECv[i+j-ei];

    vertex u = v0;
    do {
      for (index i = 0; i < G[u].size(); ++i)
        if (!Gl[GE[vip(u, i)]]) {
          ECv[ei+1] = G[u][i];
          Gl[GE[vip(u, i)]] = true;
          --rdeg[u];
          u = G[u][i];
          --rdeg[u];
          ++ei;
          break;
        }

      if (u == v0)
        break;
    } while (true);
  } while (ei < en);

  fout << "The graph is eulerian." << endl;
  fout << "Eulerian circuit: " << endl;
  for (index i = 0; i < en; ++i)
    for (index j = 0; j < G[ECv[i]].size(); ++j)
      if (G[ECv[i]][j] == ECv[i+1])
        fout << ECv[i] << "-(" << GE[vip(ECv[i], j)] << ")-";
  fout << ECv[en] << endl << endl;

  return true;
}


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
