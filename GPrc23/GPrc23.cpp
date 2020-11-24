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
  fout << endl;
  DFS_Trees(K10, fout);
  fout << endl;
  BFS_Trees(K10, fout);
  fout << endl;
  Dijkstra(K10, 0, fout);
  fout.close();

  // K6_4
  fout.open("K6_4.out");
  graph K6_4 = graph_bipartite_complete(6, 4);
  graph_write(K6_4, fout);
  fout << endl;
  DFS_Trees(K6_4, fout);
  fout << endl;
  BFS_Trees(K6_4, fout);
  fout << endl;
  Dijkstra(K6_4, 0, fout);

  fout << endl;

  // K4_6
  graph K4_6 = graph_bipartite_complete(4, 6);
  graph_write(K4_6, fout);
  fout << endl;
  DFS_Trees(K4_6, fout);
  fout << endl;
  BFS_Trees(K4_6, fout);
  fout << endl;
  Dijkstra(K4_6, 0, fout);
  fout.close();

  // C10
  fout.open("C10.out");
  graph C10 = graph_cycle(10);
  graph_write(C10, fout);
  fout << endl;
  DFS_Trees(C10, fout);
  fout << endl;
  BFS_Trees(C10, fout);
  fout << endl;
  Dijkstra(C10, 0, fout);
  fout.close();

  // S10
  fout.open("S10.out");
  graph S10 = graph_star(10);
  graph_write(S10, fout);
  fout << endl;
  DFS_Trees(S10, fout);
  fout << endl;
  BFS_Trees(S10, fout);
  fout << endl;
  Dijkstra(S10, 0, fout);
  fout.close();

  // W10
  fout.open("W10.out");
  graph W10 = graph_wheel(10);
  graph_write(W10, fout);
  fout << endl;
  DFS_Trees(W10, fout);
  fout << endl;
  BFS_Trees(W10, fout);
  fout << endl;
  Dijkstra(W10, 0, fout);
  fout.close();

  // G0
  fout.open("graph0.out");
  graph G0 = graph_read("graph0.in");
  graph_write(G0, fout);
  fout << endl;
  DFS_Trees(G0, fout);
  fout << endl;
  BFS_Trees(G0, fout);
  fout << endl;
  Dijkstra(G0, 0, fout);
  fout.close();

  // G1
  fout.open("graph1.out");
  graph G1 = graph_read("graph1.in");
  graph_write(G1, fout);
  fout << endl;
  DFS_Trees(G1, fout);
  fout << endl;
  BFS_Trees(G1, fout);
  fout << endl;
  Dijkstra(G1, 0, fout);
  fout.close();

  // G2
  fout.open("graph2.out");
  graph G2 = graph_read("graph2.in");
  graph_write(G2, fout);
  fout << endl;
  DFS_Trees(G2, fout);
  fout << endl;
  BFS_Trees(G2, fout);
  fout << endl;
  Dijkstra(G2, 0, fout);
  fout.close();

  // G3
  fout.open("graph3.out");
  graph G3 = graph_read("graph3.in");
  graph_write(G3, fout);
  fout << endl;
  DFS_Trees(G3, fout);
  fout << endl;
  BFS_Trees(G3, fout);
  fout << endl;
  Dijkstra(G3, 0, fout);
  fout.close();

  //
  // WEIGHTED GRAPHS
  //

  weight d, infty = UINT_MAX;

  // WK10
  fout.open("WK10.out");
  wgraph WK10 = wgraph_complete(10, 9);
  wgraph_write(WK10, fout);
  fout << endl << "Distance between first and last vertex: ";
  d = Dijkstra(WK10, 0, WK10.size()-1);
  if (d == infty)
    fout << "undefined" << endl;
  else
    fout << d << endl;
  fout << "Maximum distance from first vertex: ";
  d = Dijkstra(WK10, 0);
  if (d == infty)
    fout << "undefined" << endl;
  else
    fout << d << endl;
  fout << endl << "Distances from first vertex to all accessible vertices: ";
  Dijkstra(WK10, 0, fout);
  fout << endl << "Diameter: ";
  d = Diameter(WK10);
  if (d == infty)
    fout << "undefined." << endl;
  else
    fout << d << endl;
  fout << endl << "Paths from all vertices reachable from vertex 0: ";
  Dijkstra_Tree(WK10, 0, fout);
  fout << endl << "KRUSKAL" << endl;
  fout << KruskalTrees(WK10, fout) << " is the total weight of the minimal trees by Kruskal";
  fout << endl;
  fout << endl << "PRIM" << endl;
  fout << PrimTrees(WK10, fout) << " is the total weight of the minimal trees by Prim";
  fout << endl;
  fout.close();

  // WK6_4
  fout.open("WK6_4.out");
  wgraph WK6_4 = wgraph_bipartite_complete(6, 4, 9);
  wgraph_write(WK6_4, fout);
  fout << endl << "Distance between first and last vertex: ";
  d = Dijkstra(WK6_4, 0, WK6_4.size()-1);
  if (d == infty)
    fout << "undefined" << endl;
  else
    fout << d << endl;
  fout << "Maximum distance from first vertex: ";
  d = Dijkstra(WK6_4, 0);
  if (d == infty)
    fout << "undefined" << endl;
  else
    fout << d << endl;
  fout << endl << "Distances from first vertex to all accessible vertices: ";
  Dijkstra(WK6_4, 0, fout);
  fout << endl << "Diameter: ";
  d = Diameter(WK6_4);
  if (d == infty)
    fout << "undefined." << endl;
  else
    fout << d << endl;
  fout << endl << "Paths from all vertices reachable from vertex 0: ";
  Dijkstra_Tree(WK6_4, 0, fout);
  fout << endl << "KRUSKAL" << endl;
  fout << KruskalTrees(WK6_4, fout) << " is the total weight of the minimal trees by Kruskal";
  fout << endl;
  fout << endl << "PRIM" << endl;
  fout << PrimTrees(WK6_4, fout) << " is the total weight of the minimal trees by Prim";
  fout << endl;

  fout << endl;

  // WK4_6
  wgraph WK4_6 = wgraph_bipartite_complete(4, 6, 9);
  wgraph_write(WK4_6, fout);
  fout << endl << "Distance between first and last vertex: ";
  d = Dijkstra(WK4_6, 0, WK4_6.size()-1);
  if (d == infty)
    fout << "undefined" << endl;
  else
    fout << d << endl;
  fout << "Maximum distance from first vertex: ";
  d = Dijkstra(WK4_6, 0);
  if (d == infty)
    fout << "undefined" << endl;
  else
    fout << d << endl;
  fout << endl << "Distances from first vertex to all accessible vertices: ";
  Dijkstra(WK4_6, 0, fout);
  fout << endl << "Diameter: ";
  d = Diameter(WK4_6);
  if (d == infty)
    fout << "undefined." << endl;
  else
    fout << d << endl;
  fout << endl << "Paths from all vertices reachable from vertex 0: ";
  Dijkstra_Tree(WK4_6, 0, fout);
  fout << endl << "KRUSKAL" << endl;
  fout << KruskalTrees(WK4_6, fout) << " is the total weight of the minimal trees by Kruskal";
  fout << endl;
  fout << endl << "PRIM" << endl;
  fout << PrimTrees(WK4_6, fout) << " is the total weight of the minimal trees by Prim";
  fout << endl;
  fout.close();

  // WC10
  fout.open("WC10.out");
  wgraph WC10 = wgraph_cycle(10, 9);
  wgraph_write(WC10, fout);
  fout << endl << "Distance between first and last vertex: ";
  d = Dijkstra(WC10, 0, WC10.size()-1);
  if (d == infty)
    fout << "undefined" << endl;
  else
    fout << d << endl;
  fout << "Maximum distance from first vertex: ";
  d = Dijkstra(WC10, 0);
  if (d == infty)
    fout << "undefined" << endl;
  else
    fout << d << endl;
  fout << endl << "Distances from first vertex to all accessible vertices: ";
  Dijkstra(WC10, 0, fout);
  fout << endl << "Diameter: ";
  d = Diameter(WC10);
  if (d == infty)
    fout << "undefined." << endl;
  else
    fout << d << endl;
  fout << endl << "Paths from all vertices reachable from vertex 0: ";
  Dijkstra_Tree(WC10, 0, fout);
  fout << endl << "KRUSKAL" << endl;
  fout << KruskalTrees(WC10, fout) << " is the total weight of the minimal trees by Kruskal";
  fout << endl;
  fout << endl << "PRIM" << endl;
  fout << PrimTrees(WC10, fout) << " is the total weight of the minimal trees by Prim";
  fout << endl;
  fout.close();

  // WS10
  fout.open("WS10.out");
  wgraph WS10 = wgraph_star(10, 9);
  wgraph_write(WS10, fout);
  fout << endl << "Distance between first and last vertex: ";
  d = Dijkstra(WS10, 0, WS10.size()-1);
  if (d == infty)
    fout << "undefined" << endl;
  else
    fout << d << endl;
  fout << "Maximum distance from first vertex: ";
  d = Dijkstra(WS10, 0);
  if (d == infty)
    fout << "undefined" << endl;
  else
    fout << d << endl;
  fout << endl << "Distances from first vertex to all accessible vertices: ";
  Dijkstra(WS10, 0, fout);
  fout << endl << "Diameter: ";
  d = Diameter(WS10);
  if (d == infty)
    fout << "undefined." << endl;
  else
    fout << d << endl;
  fout << endl << "Paths from all vertices reachable from vertex 0: ";
  Dijkstra_Tree(WS10, 0, fout);
  fout << endl << "KRUSKAL" << endl;
  fout << KruskalTrees(WS10, fout) << " is the total weight of the minimal trees by Kruskal";
  fout << endl;
  fout << endl << "PRIM" << endl;
  fout << PrimTrees(WS10, fout) << " is the total weight of the minimal trees by Prim";
  fout << endl;
  fout.close();

  // WW10
  fout.open("WW10.out");
  wgraph WW10 = wgraph_wheel(10, 9);
  wgraph_write(WW10, fout);
  fout << endl << "Distance between first and last vertex: ";
  d = Dijkstra(WW10, 0, WW10.size()-1);
  if (d == infty)
    fout << "undefined" << endl;
  else
    fout << d << endl;
  fout << "Maximum distance from first vertex: ";
  d = Dijkstra(WW10, 0);
  if (d == infty)
    fout << "undefined" << endl;
  else
    fout << d << endl;
  fout << endl << "Distances from first vertex to all accessible vertices: ";
  Dijkstra(WW10, 0, fout);
  fout << endl << "Diameter: ";
  d = Diameter(WW10);
  if (d == infty)
    fout << "undefined." << endl;
  else
    fout << d << endl;
  fout << endl << "Paths from all vertices reachable from vertex 0: ";
  Dijkstra_Tree(WW10, 0, fout);
  fout << endl << "KRUSKAL" << endl;
  fout << KruskalTrees(WW10, fout) << " is the total weight of the minimal trees by Kruskal";
  fout << endl;
  fout << endl << "PRIM" << endl;
  fout << PrimTrees(WW10, fout) << " is the total weight of the minimal trees by Prim";
  fout << endl;
  fout.close();

  // WG0
  fout.open("wgraph0.out");
  wgraph WG0 = wgraph_read("wgraph0.in");
  wgraph_write(WG0, fout);
  fout << endl << "Distance between first and last vertex: ";
  d = Dijkstra(WG0, 0, WG0.size()-1);
  if (d == infty)
    fout << "undefined" << endl;
  else
    fout << d << endl;
  fout << "Maximum distance from first vertex: ";
  d = Dijkstra(WG0, 0);
  if (d == infty)
    fout << "undefined" << endl;
  else
    fout << d << endl;
  fout << endl << "Distances from first vertex to all accessible vertices: ";
  Dijkstra(WG0, 0, fout);
  fout << endl << "Diameter: ";
  d = Diameter(WG0);
  if (d == infty)
    fout << "undefined." << endl;
  else
    fout << d << endl;
  fout << endl << "Paths from all vertices reachable from vertex 0: ";
  Dijkstra_Tree(WG0, 0, fout);
  fout << endl << "KRUSKAL" << endl;
  fout << KruskalTrees(WG0, fout) << " is the total weight of the minimal trees by Kruskal";
  fout << endl;
  fout << endl << "PRIM" << endl;
  fout << PrimTrees(WG0, fout) << " is the total weight of the minimal trees by Prim";
  fout << endl;
  fout.close();

  // WG1
  fout.open("wgraph1.out");
  wgraph WG1 = wgraph_read("wgraph1.in");
  wgraph_write(WG1, fout);
  fout << endl << "Distance between first and last vertex: ";
  d = Dijkstra(WG1, 0, WG1.size()-1);
  if (d == infty)
    fout << "undefined" << endl;
  else
    fout << d << endl;
  fout << "Maximum distance from first vertex: ";
  d = Dijkstra(WG1, 0);
  if (d == infty)
    fout << "undefined" << endl;
  else
    fout << d << endl;
  fout << endl << "Distances from first vertex to all accessible vertices: ";
  Dijkstra(WG1, 0, fout);
  fout << endl << "Diameter: ";
  d = Diameter(WG1);
  if (d == infty)
    fout << "undefined." << endl;
  else
    fout << d << endl;
  fout << endl << "Paths from all vertices reachable from vertex 0: ";
  Dijkstra_Tree(WG1, 0, fout);
  fout << endl << "KRUSKAL" << endl;
  fout << KruskalTrees(WG1, fout) << " is the total weight of the minimal trees by Kruskal";
  fout << endl;
  fout << endl << "PRIM" << endl;
  fout << PrimTrees(WG1, fout) << " is the total weight of the minimal trees by Prim";
  fout << endl;
  fout.close();

  // WG2
  fout.open("wgraph2.out");
  wgraph WG2 = wgraph_read("wgraph2.in");
  wgraph_write(WG2, fout);
  fout << endl << "Distance between first and last vertex: ";
  d = Dijkstra(WG2, 0, WG2.size()-1);
  if (d == infty)
    fout << "undefined" << endl;
  else
    fout << d << endl;
  fout << "Maximum distance from first vertex: ";
  d = Dijkstra(WG2, 0);
  if (d == infty)
    fout << "undefined" << endl;
  else
    fout << d << endl;
  fout << endl << "Distances from first vertex to all accessible vertices: ";
  Dijkstra(WG2, 0, fout);
  fout << endl << "Diameter: ";
  d = Diameter(WG2);
  if (d == infty)
    fout << "undefined." << endl;
  else
    fout << d << endl;
  fout << endl << "Paths from all vertices reachable from vertex 0: ";
  Dijkstra_Tree(WG2, 0, fout);
  fout << endl;
  fout.close();

  // WG3
  fout.open("wgraph3.out");
  wgraph WG3 = wgraph_read("wgraph3.in");
  wgraph_write(WG3, fout);
  fout << endl << "Distance between first and last vertex: ";
  d = Dijkstra(WG3, 0, WG3.size()-1);
  if (d == infty)
    fout << "undefined" << endl;
  else
    fout << d << endl;
  fout << "Maximum distance from first vertex: ";
  d = Dijkstra(WG3, 0);
  if (d == infty)
    fout << "undefined" << endl;
  else
    fout << d << endl;
  fout << endl << "Distances from first vertex to all accessible vertices: ";
  Dijkstra(WG3, 0, fout);
  fout << endl << "Diameter: ";
  d = Diameter(WG3);
  if (d == infty)
    fout << "undefined." << endl;
  else
    fout << d << endl;
  fout << endl << "Paths from all vertices reachable from vertex 0: ";
  Dijkstra_Tree(WG3, 0, fout);
  fout << endl << "KRUSKAL" << endl;
  fout << KruskalTrees(WG3, fout) << " is the total weight of the minimal trees by Kruskal";
  fout << endl;
  fout << endl << "PRIM" << endl;
  fout << PrimTrees(WG3, fout) << " is the total weight of the minimal trees by Prim";
  fout << endl;
  fout.close();

  // Example 3.2.2. WGraph: WG322
  fout.open("wgraph322.out");
  wgraph WG322 = wgraph_read("wgraph322.in");
  wgraph_write(WG322, fout);
  fout << endl << "Distance between first and last vertex: ";
  d = Dijkstra(WG322, 0, WG322.size()-1);
  if (d == infty)
    fout << "undefined" << endl;
  else
    fout << d << endl;
  fout << "Maximum distance from first vertex: ";
  d = Dijkstra(WG322, 0);
  if (d == infty)
    fout << "undefined" << endl;
  else
    fout << d << endl;
  fout << endl << "Distances from first vertex to all accessible vertices: ";
  Dijkstra(WG322, 0, fout);
  fout << endl << "Diameter: ";
  d = Diameter(WG322);
  if (d == infty)
    fout << "undefined." << endl;
  else
    fout << d << endl;
  fout << endl << "Paths from all vertices reachable from vertex 0: ";
  Dijkstra_Tree(WG322, 0, fout);
  fout << endl;
  fout.close();

  // Dodecahedron: WD.out
  fout.open("WD.out");
  wgraph WD = wgraph_read("WD.in");
  wgraph_write(WD, fout);
  fout << endl << "Distance between first and last vertex: ";
  d = Dijkstra(WD, 0, WD.size()-1);
  if (d == infty)
    fout << "undefined" << endl;
  else
    fout << d << endl;
  fout << "Maximum distance from first vertex: ";
  d = Dijkstra(WD, 0);
  if (d == infty)
    fout << "undefined" << endl;
  else
    fout << d << endl;
  fout << endl << "Distances from first vertex to all accessible vertices: ";
  Dijkstra(WD, 0, fout);
  fout << endl << "Diameter: ";
  d = Diameter(WD);
  if (d == infty)
    fout << "undefined." << endl;
  else
    fout << d << endl;
  fout << endl << "Paths from all vertices reachable from vertex 0: ";
  Dijkstra_Tree(WD, 0, fout);
  fout << endl << "KRUSKAL" << endl;
  fout << KruskalTrees(WD, fout) << " is the total weight of the minimal trees by Kruskal";
  fout << endl;
  fout << endl << "PRIM" << endl;
  fout << PrimTrees(WD, fout) << " is the total weight of the minimal trees by Prim";
  fout << endl;
  fout.close();

  // Icosahedron: WI.out
  fout.open("WI.out");
  wgraph WI = wgraph_read("WI.in");
  wgraph_write(WI, fout);
  fout << endl << "Distance between first and last vertex: ";
  d = Dijkstra(WI, 0, WI.size()-1);
  if (d == infty)
    fout << "undefined" << endl;
  else
    fout << d << endl;
  fout << "Maximum distance from first vertex: ";
  d = Dijkstra(WI, 0);
  if (d == infty)
    fout << "undefined" << endl;
  else
    fout << d << endl;
  fout << endl << "Distances from first vertex to all accessible vertices: ";
  Dijkstra(WI, 0, fout);
  fout << endl << "Diameter: ";
  d = Diameter(WI);
  if (d == infty)
    fout << "undefined." << endl;
  else
    fout << d << endl;
  fout << endl << "Paths from all vertices reachable from vertex 0: ";
  Dijkstra_Tree(WI, 0, fout);
  fout << endl << "KRUSKAL" << endl;
  fout << KruskalTrees(WI, fout) << " is the total weight of the minimal trees by Kruskal";
  fout << endl;
  fout << endl << "PRIM" << endl;
  fout << PrimTrees(WI, fout) << " is the total weight of the minimal trees by Prim";
  fout << endl;
  fout.close();

  //
  // CHESSBOARD GRAPHS
  //

  // King 6x6 graph Kg6_6: distances from (2,0)
  fout.open("Kg6_6.out");
  graph Kg6_6 = graph_king(6, 6);
  chess_graph_write(Kg6_6, 6, 6, fout);
  chess_Dijkstra(Kg6_6, 6, 6, 2, 0, fout);
  fout.close();

  // Rook 6x6 graph Rk6_6: distances from (2,0)
  fout.open("Rk6_6.out");
  graph Rk6_6 = graph_rook(6, 6);
  chess_graph_write(Rk6_6, 6, 6, fout);
  chess_Dijkstra(Rk6_6, 6, 6, 2, 0, fout);
  fout.close();

  // Bishop 6x6 graph Bp6_6: distances from (2,0)
  fout.open("Bp6_6.out");
  graph Bp6_6 = graph_bishop(6, 6);
  chess_graph_write(Bp6_6, 6, 6, fout);
  chess_Dijkstra(Bp6_6, 6, 6, 2, 0, fout);
  fout.close();

  // Knight 6x6 graph Kt6_6: distances from (2,0)
  fout.open("Kt6_6.out");
  graph Kt6_6 = graph_knight(6, 6);
  chess_graph_write(Kt6_6, 6, 6, fout);
  chess_Dijkstra(Kt6_6, 6, 6, 2, 0, fout);
  fout.close();

  //
  // CITY GRAPHS
  //

  // cities1.out
  fout.open("cities1.out");
  wgraph WGC1 = wgraph_read("cities1.in");
  fout << endl << "KRUSKAL" << endl;
  fout << KruskalTrees(WGC1, fout) << " is the total weight of the minimal trees by Kruskal";
  fout << endl;
  fout << endl << "PRIM" << endl;
  fout << PrimTrees(WGC1, fout) << " is the total weight of the minimal trees by Prim";
  fout << endl;
  fout.close();

  // cities2.out
  fout.open("cities2.out");
  wgraph WGC2 = wgraph_read("cities2.in");
  fout << endl << "KRUSKAL" << endl;
  fout << KruskalTrees(WGC2, fout) << " is the total weight of the minimal trees by Kruskal";
  fout << endl;
  fout << endl << "PRIM" << endl;
  fout << PrimTrees(WGC2, fout) << " is the total weight of the minimal trees by Prim";
  fout << endl;
  fout.close();

  //
  // ENDING
  //
  cout << endl << "Press enter to finish...";
  cin.get();

  return 0;
}
