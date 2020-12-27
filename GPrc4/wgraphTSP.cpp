// NOM: Marc Ballestero Ribó.
// GRUP: M1a.
// DATA d'ENTREGA: 13/01/2021.

#include "wgraph.h"

//
//  Robert and Flores method for hamiltonian cycles in weighted graphs.
//
index HamiltonianCycles (wgraph &G, ofstream &fout)
{
  vertex vn = G.size();
  weight HCw = 0;
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
      if (!HCl[G[v][ind[v]].first]) {
        HCw += G[v][ind[v]].second;
        v = G[v][ind[v]++].first;
        HCv[HCi++] = v;
        HCl[v] = true;
      }
      else ++ind[v];
    }

    if (HCi == vn) {
      for (index i = 0; i < G[v].size(); ++i)
        if (G[v][i].first == 0) {
          ++HCn;
          HCw += G[v][i].second;
          fout << "Weighted hamiltonian cycle #" << HCn << " : ";
          for (index HCj = 0; HCj < vn; ++HCj)
            fout << HCv[HCj] << "-";
          fout << "0 " << "[" << HCw << "]" << endl;

          HCw -= G[v][i].second;
          break;
        }
    }

    --HCi;
    if (HCi == 0)
      return HCn;

    HCl[v] = false;
    ind[v] = 0;
    v = HCv[HCi-1];
    HCw -= G[v][ind[v]-1].second;
  } while (true);

}


//
//  Travelling Salesman Problem for weighted graphs.
//
weight TravellingSalsemanProblem(wgraph &G, ofstream &fout)
{
  vertex vn = G.size();
  weight mHCw = UINT_MAX;
  index mHCn;
  vector<vertex> mHCv(vn);

  weight HCw = 0;
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
      if (!HCl[G[v][ind[v]].first]) {
        HCw += G[v][ind[v]].second;
        v = G[v][ind[v]++].first;
        HCv[HCi++] = v;
        HCl[v] = true;
      }
      else ++ind[v];
    }

    if (HCi == vn) {
      for (index i = 0; i < G[v].size(); ++i)
        if (G[v][i].first == 0) {
          ++HCn;
          HCw += G[v][i].second;
          fout << "Weighted hamiltonian cycle #" << HCn << " : ";
          for (index HCj = 0; HCj < vn; ++HCj)
            fout << HCv[HCj] << "-";
          fout << "0 " << "[" << HCw << "]" << endl;

          if (mHCw > HCw) {
            mHCw = HCw;
            mHCv = HCv;
            mHCn = HCn;
          }

          HCw -= G[v][i].second;
          break;
        }
    }

    --HCi;
    if (HCi == 0) {
      if (mHCn) {
        fout << "TSP solution: ";
        for (index mHCj = 0; mHCj < vn; ++mHCj)
          fout << mHCv[mHCj] << "-";
        fout << "0 " << "[" << mHCw << "]" << endl;
      }
      else {
        fout << "The TSP cannot be solved for this graph." << endl;
      }

      return mHCw;
    }

    HCl[v] = false;
    ind[v] = 0;
    v = HCv[HCi-1];
    HCw -= G[v][ind[v]-1].second;
  } while(true);

}
