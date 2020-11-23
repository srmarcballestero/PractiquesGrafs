// NOM: Marc Ballestero Ribó.
// GRUP: M1a.
// DATA d'ENTREGA: 28/11/2020.

#include "wgraph.h"


//
//  - Distance between two vertices
//    d(sv, v) = Dd[tv].
//
weight Dijkstra(wgraph &G, vertex sv, vertex tv)
{
  vertex vn = G.size();
  vector<bool> Dl(vn, false);

  weight infty = UINT_MAX;
  vector<weight> Dd(vn, infty);
  Dd[sv] = 0;

  vertex mdv = sv;
  do {
    Dl[mdv] = true;
    for (index i = 0; i < G[mdv].size(); ++i)
      if (Dd[G[mdv][i].first] > Dd[mdv]+G[mdv][i].second)
        Dd[G[mdv][i].first] = Dd[mdv]+G[mdv][i].second;

    weight md = infty;
    mdv = vn;
    for (vertex v = 0; v < vn; ++v)
      if (md > Dd[v] && !Dl[v]) {
        md = Dd[v];
        mdv = v;
      }
  } while (mdv < vn && mdv != tv);

  return Dd[tv];
}

//
//  - Maximum distance from starting vertex
//    Mdsv = max_v d(sv, v) = max_v Dd[v]
//
weight Dijkstra(wgraph &G, vertex sv)
{
  vertex vn = G.size();
  vector<bool> Dl(vn, false);

  weight infty = UINT_MAX;
  vector<weight> Dd(vn, infty);
  Dd[sv] = 0;

  vertex mdv = sv;
  do {
    Dl[mdv] = true;
    for (index i = 0; i < G[mdv].size(); ++i)
      if (Dd[G[mdv][i].first] > Dd[mdv]+G[mdv][i].second)
        Dd[G[mdv][i].first] = Dd[mdv]+G[mdv][i].second;

    weight md = infty;
    mdv = vn;
    for (vertex v = 0; v < vn; ++v)
      if (md > Dd[v] && !Dl[v]) {
        md = Dd[v];
        mdv = v;
      }
    } while (mdv < vn);

    weight Mdsv = Dd[0];
    for (vertex v = 1; v < vn; ++v) {
      if (Mdsv < Dd[v])
        Mdsv = Dd[v];
      if (Dd[v] == infty)
        v = vn;
    }

  return Mdsv;
}

//
//   Diameter
//   D = max_sv_tv d(sv,tv) = max_sv Mdsv
//
weight Diameter(wgraph &G)
{
  weight D = 0;
  vertex vn = G.size();
  weight infty = UINT_MAX;

  for (vertex sv = 0; sv < vn; ++sv) {
    weight Mdsv = Dijkstra(G, sv);
    if (Mdsv == infty)
      return Mdsv;
    if (D < Mdsv)
      D = Mdsv;
  }

  return D;
}

//
//  Minimal path weights by Dijkstra's method to stream
//  - Distances to all vertices: weights of minimal paths
//
void Dijkstra(wgraph &G, vertex sv, ofstream &fout)
{
  vertex vn = G.size();
  vector<bool> Dl(vn, false);

  weight infty = UINT_MAX;
  vector<weight> Dd(vn, infty);
  Dd[sv] = 0;

  vertex mdv = sv;
  do {
    Dl[mdv] = true;
    for (index i = 0; i < G[mdv].size(); ++i)
      if (Dd[G[mdv][i].first] > Dd[mdv] + G[mdv][i].second)
        Dd[G[mdv][i].first] = Dd[mdv] + G[mdv][i].second;

    weight md = infty;
    mdv = vn;
    for (vertex v = 0; v < vn; ++v)
      if (md > Dd[v] && !Dl[v]) {
        md = Dd[v];
        mdv = v;
      }
  } while (mdv < vn);

  fout << "\nDistances from starting vertex " << sv << endl;
  for (vertex v = 0; v < vn; ++v)
    if (Dd[v] < infty)
      fout << v << "\t" << Dd[v] << endl;
    else
      fout << v << "\tNot connected" << endl;

}

//
//   Minimal paths from/to starting vertex to ofstream.
//
void Dijkstra_Tree(wgraph &G, vertex sv, ofstream &fout)
{
  vertex vn = G.size();
  vector<bool> Dl(vn, false);
  vector<vertex> Dp(vn, vn);

  weight infty = UINT_MAX;
  vector<weight> Dd(vn, infty);
  Dd[sv] = sv;

  vertex mdv = sv;
  do {
    Dl[mdv] = true;
    for (index i = 0; i < G[mdv].size(); ++i)
      if (Dd[G[mdv][i].first] > Dd[mdv] + G[mdv][i].second)
        Dd[G[mdv][i].first] = mdv;

    weight md = infty;
    mdv = vn;
    for (vertex v = 0; v < vn; ++v)
      if (md > Dd[v] && !Dl[v]) {
        md = Dd[v];
        mdv = v;
      }
  } while (mdv < vn);

  fout << "\nDistances from starting vertex " << sv << endl;
  for (vertex v = 0; v < vn; ++v)
    if (Dd[v] < infty)
      fout << v << "\t" << Dd[v] << endl;
    else
      fout << v << "\tNot connected" << endl;

  fout << endl << "Minimal paths:" << endl;
  for (vertex v = 0; v < vn; ++v) {
    fout << v;
    if (Dp[v] < vn) {
      vertex pv = v;
      while (pv != sv) {
        pv = Dp[sv];
        fout << "-" << pv;
      }
      fout << endl;
    }
    else
      fout << "\tNot connected" << endl;
  }
}
