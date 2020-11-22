// NOM: Marc Ballestero Ribó.
// GRUP: M1a.
// DATA d'ENTREGA: 28/11/2020.

#include "wgraph.h"


//
//  Weighted complete graph with vn vertices and random weights up to Mw
//  to weighted adjacencies lists.
//
wgraph wgraph_complete(index n, weight Mw)
{
  vertex vn = 0;
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
