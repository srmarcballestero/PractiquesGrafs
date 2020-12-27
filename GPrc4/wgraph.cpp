// NOM: Marc Ballestero Ribó.
// GRUP: M1a.
// DATA d'ENTREGA: 13/01/2021.


#include "wgraph.h"

//
//  Weighted complete graph with vn vertices and random weights up to Mw
//  to weighted adjacencies lists.
//
wgraph wgraph_complete(index n, weight Mw)
{
  vertex vn = n;
  wgraph WKn(vn);

  for (vertex v = 0; v < vn; ++v)
    for (vertex u = v+1; u < vn; ++u) {
      weight w = rand()%Mw + 1;
      WKn[v].push_back(pair<vertex, weight>(u, w));
      WKn[u].push_back(pair<vertex, weight>(v, w));
    }

  return WKn;
}

//
//  Weighted bipartite complete graph with vn vertices and random weights up to Mw
//  to weighted adjacencies lists.
//
wgraph wgraph_bipartite_complete(index n1, index n2, weight Mw)
{
  vertex vn = n1 + n2;
  wgraph WKn1n2(vn);

  for (vertex v = 0; v < n1; ++v)
    for (vertex u = n1; u < vn; ++u) {
      weight w = rand()%Mw + 1;
      WKn1n2[v].push_back(pair<vertex, weight>(u, w));
      WKn1n2[u].push_back(pair<vertex, weight>(v, w));
    }

  return WKn1n2;
}

//
//  Weighted cycle graph with vn vertices and random weights up to Mw
//  to weighted adjacencies lists.
//
wgraph wgraph_cycle(index n, weight Mw)
{
  vertex vn = n;
  wgraph WCn(vn);

  for (vertex v = 0; v < n-1; ++v) {
    weight w = rand()%Mw + 1;
    WCn[v].push_back(pair<vertex, weight>(v+1, w));
    WCn[v+1].push_back(pair<vertex, weight>(v, w));
  }
  weight w = rand() % Mw +1;
  WCn[n-1].push_back(pair<vertex, weight>(0, w));
  WCn[0].push_back(pair<vertex, weight>(n-1, w));

  return WCn;
}

//
//  Weighted star graph with vn vertices and random weights up to Mw
//  to weighted adjacencies lists.
//
wgraph wgraph_star(index n, weight Mw)
{
  vertex vn = n+1;
  wgraph WSn(vn);

  for (vertex v = 0; v < n; ++v) {
    weight w = rand()%Mw + 1;
    WSn[v].push_back(pair<vertex, weight>(n, w));
    WSn[n].push_back(pair<vertex, weight>(v, w));
  }

  return WSn;
}

//
//  Weighted wheel graph with vn vertices and random weights up to Mw
//  to weighted adjacencies lists.
//
wgraph wgraph_wheel(index n, weight Mw)
{
  vertex vn = n+1;
  wgraph WWn(vn);

  for (vertex v = 0; v < n-1; ++v) {
    weight w = rand()%Mw + 1;
    WWn[v].push_back(pair<vertex, weight>(v+1, w));
    WWn[v+1].push_back(pair<vertex, weight>(v, w));
  }
  weight w = rand()%Mw + 1;
  WWn[n-1].push_back(pair<vertex, weight>(0, w));
  WWn[0].push_back(pair<vertex, weight>(n-1, w));

  for (vertex v = 0; v < n; ++v) {
    weight w = rand()%Mw + 1;
    WWn[v].push_back(pair<vertex, weight>(n, w));
    WWn[n].push_back(pair<vertex, weight>(v, w));
  }

  return WWn;
}

//
//  Read from file fname of weighted edges to weighted adjacencies lists.
//
wgraph wgraph_read(string fname)
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

  wgraph WG(vn);

  for (edge e = 0; e < en; ++e) {
    vertex u, v;
    weight w;
    fin >> u >> v >> w;
    WG[u].push_back(pair<vertex, weight>(v, w));
    if (u != v)
      WG[v].push_back(pair<vertex, weight>(u, w));
  }

  return WG;
}

//
//  Write from weighted adjacencies lists (wgraph) to stream
//  - vertices and edges numbers
//  - weighted edges
//  - degrees and sorted degrees
void wgraph_write(wgraph &WG, ofstream &fout)
{
  vertex vn = WG.size();
  edge en = 0;

  for (vertex v = 0; v < vn; ++v)
    en += WG[v].size();
  en /= 2;

  fout << "WGraph with " << vn << " vertices and " << en << " edges" << endl;

  fout << "Weighted adjacencies lists" << endl;
  for (vertex v = 0; v < vn; ++v) {
    fout << v << "\t:";
    for (index i = 0; i < WG[v].size(); ++i)
      fout << " " << WG[v][i].first << "[" << WG[v][i].second << "] ";
    fout << endl;
  }
  fout << endl;

  fout << "Weighted edges" << endl;
  for (vertex v = 0; v < vn; ++v)
    for (index i = 0; i < WG[v].size(); ++i)
      if (v <= WG[v][i].first)
        fout << v << "-" << WG[v][i].first << "[" << WG[v][i].second << "] " << endl;

}
