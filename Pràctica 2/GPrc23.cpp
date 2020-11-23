// NOM: Marc Ballestero Ribó.
// GRUP: M1a.
// DATA d'ENTREGA: 28/11/2020.

#include <ctime>
#include "graph.h"
#include "wgraph.h"

int main()
{
  ofstream fout;
  srand( (unsigned int) time(NULL));

  //
  // UNWEIGHTED GRAPHS
  //

  // K10
  fout.open("K10.out");
  graph K10 = graph_complete(10);
  graph_write(K10, fout);
  fout << "\nNumber of DFS components: " << DFS_Trees(K10, fout) << endl;
  fout << "\nNumber of BFS components: " << BFS_Trees(K10, fout) << endl;
  Dijkstra(K10, 0, fout);
  fout.close();

  // K6_4
  fout.open("K6_4.out");
  graph K6_4 = graph_bipartite_complete(6, 4);
  graph_write(K6_4, fout);
  fout << "\nNumber of DFS components: " << DFS_Trees(K6_4, fout) << endl;
  fout << "\nNumber of BFS components: " << BFS_Trees(K6_4, fout) << endl;
  Dijkstra(K6_4, 0, fout);
  fout.close();

  // K4_6
  fout.open("K4_6.out");
  graph K4_6 = graph_bipartite_complete(6, 4);
  graph_write(K4_6, fout);
  fout << "\nNumber of DFS components: " << DFS_Trees(K4_6, fout) << endl;
  fout << "\nNumber of BFS components: " << BFS_Trees(K4_6, fout) << endl;
  Dijkstra(K4_6, 0, fout);
  fout.close();

  // C10
  fout.open("C10.out");
  graph C10 = graph_cycle(10);
  graph_write(C10, fout);
  fout << "\nNumber of DFS components: " << DFS_Trees(C10, fout) << endl;
  fout << "\nNumber of BFS components: " << BFS_Trees(C10, fout) << endl;
  Dijkstra(C10, 0, fout);
  fout.close();

  // S10
  fout.open("S10.out");
  graph S10 = graph_cycle(10);
  graph_write(S10, fout);
  fout << "\nNumber of DFS components: " << DFS_Trees(S10, fout) << endl;
  fout << "\nNumber of BFS components: " << BFS_Trees(S10, fout) << endl;
  Dijkstra(S10, 0, fout);
  fout.close();

  // W10
  fout.open("W10.out");
  graph W10 = graph_cycle(10);
  graph_write(W10, fout);
  fout << "\nNumber of DFS components: " << DFS_Trees(W10, fout) << endl;
  fout << "\nNumber of BFS components: " << BFS_Trees(W10, fout) << endl;
  Dijkstra(W10, 0, fout);
  fout.close();

  // G0
  fout.open("graph0.out");
  graph G0 = graph_read("graph0.in");
  graph_write(G0, fout);
  fout << "\nNumber of DFS components: " << DFS_Trees(G0, fout) << endl;
  fout << "\nNumber of BFS components: " << BFS_Trees(G0, fout) << endl;
  Dijkstra(G0, 0, fout);
  fout.close();

  // G1
  fout.open("graph1.out");
  graph G1 = graph_read("graph1.in");
  graph_write(G1, fout);
  fout << "\nNumber of DFS components: " << DFS_Trees(G1, fout) << endl;
  fout << "\nNumber of BFS components: " << BFS_Trees(G1, fout) << endl;
  Dijkstra(G1, 0, fout);
  fout.close();

  // G2
  fout.open("graph2.out");
  graph G2 = graph_read("graph2.in");
  graph_write(G2, fout);
  fout << "\nNumber of DFS components: " << DFS_Trees(G2, fout) << endl;
  fout << "\nNumber of BFS components: " << BFS_Trees(G2, fout) << endl;
  Dijkstra(G2, 0, fout);
  fout.close();

  // G3
  fout.open("graph3.out");
  graph G3 = graph_read("graph3.in");
  graph_write(G3, fout);
  fout << "\nNumber of DFS components: " << DFS_Trees(G3, fout) << endl;
  fout << "\nNumber of BFS components: " << BFS_Trees(G3, fout) << endl;
  Dijkstra(G3, 0, fout);
  fout.close();

  //
  // WEIGHTED GRAPHS
  //

  weight d, D, infty = UINT_MAX;

  // WG0
  fout.open("wgraph0.out");
  wgraph WG0 = wgraph_read("wgraph0.in");
  wgraph_write(WG0, fout);
  fout << "Distance between first and last vertex: ";
  d = Dijkstra(WG0, 0, WG0.size()-1);
  if (d == infty)
    fout << "undefined" << endl;
  else
    fout << d << endl;
  fout << "Maximum distance from first vertex: ";
  if (d == infty)
    fout << "undefined" << endl;
  else
    fout << d << endl;
  fout << "Distances from first vertex to all accessible vertices: " << endl;
  Dijkstra(WG0, 0, fout);
  fout << endl << "Diameter: ";
  D = Diameter(WG0);
  if (D == infty)
    fout << "undefined." << endl;
  else
    fout << D << endl;
  fout << "Paths from all vertices reachable from vertex 0: " << endl;
  Dijkstra_Tree(WG0, 0, fout);
  fout << endl;
  fout.close();




  return 0;
}
