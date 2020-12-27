// NOM: Marc Ballestero Ribó.
// GRUP: M1a.
// DATA d'ENTREGA: 13/01/2021.

#include "graph.h"

//
//  Robert and Flores method for a hamiltonian cycle.
//
bool HamiltonianCycle (graph &G, ofstream &fout)
{
  vertex vn = G.size();
  vector<vertex> HCv(vn);
  vector<bool> HCl(vn, false);
  vector<index> ind(vn, 0);

  index HCi = 0;
  vertex v = 0;
  HCv[HCi++] = v;
  HCl[v] = true;


  do {
    while (ind[v] < G[v].size()) {
      if (!HCl[G[v][ind[v]]]) {
        v = G[v][ind[v]++];
        HCv[HCi++] = v;
        HCl[v] = true;
      }
      else ++ind[v];
    }

    if (HCi == vn) {
      for (index i = 0; i < G[v].size(); ++i)
        if (G[v][i] == 0) {
          fout << "Hamiltonian cycle found: ";
          for (index HCj = 0; HCj < vn; ++HCj)
            fout << HCv[HCj] << "-";
          fout << "0" << endl;

          return true;
        }
    }

    --HCi;
    if (HCi == 0)
      return 0;

    HCl[v] = false;
    ind[v] = 0;
    v = HCv[HCi-1];
  } while (true);

}

//
//  Robert and Flores method for hamiltonian cycles.
//
index HamiltonianCycles(graph &G, ofstream &fout)
{
  vertex vn = G.size();
  index HCn = 0;
  vector<vertex> HCv(vn);
  vector<bool> HCl(vn, false);
  vector<index> ind(vn, 0);

  index HCi = 0;
  vertex v = 0;
  HCv[HCi++] = v;
  HCl[v] = true;

  do {
    while (ind[v] < G[v].size()) {
      if (!HCl[G[v][ind[v]]]) {
        v = G[v][ind[v]++];
        HCv[HCi++] = v;
        HCl[v] = true;
      }
      else ++ind[v];
    }

    if (HCi == vn) {
      for (index i = 0; i < G[v].size(); ++i) {
        if (G[v][i] == 0) {
          ++HCn;
          fout << "Hamiltonian cycle #" << HCn << " : ";
          for (index HCj = 0; HCj < vn; ++HCj)
            fout << HCv[HCj] << "-";
          fout << "0" << endl;
          break;
        }
      }
    }

    --HCi;
    if (HCi == 0)
      return HCn;

    HCl[v] = false;
    ind[v] = 0;
    v = HCv[HCi-1];
  } while (true);
}
