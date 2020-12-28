// NOM: Marc Ballestero Ribó.
// GRUP: M1a.
// DATA d'ENTREGA: 13/01/2021.


#include <ctime>

#include "graphe.h"
#include "wgraph.h"


int main()
{
  ofstream fout;
  srand(time(NULL));

  //
  // UNWEIGHTED GRAPHS
  //

  // Kn
  fout.open("Kn.out");
  cout << endl << "--- Complete Graphs Kn ---" << endl;
  for (index n = 3; n < 9; ++n) {
    graph Kn;
    edges KnE;
    cout << "K" << n << endl;
    fout << "K_" << n << endl;
    graphe_complete(Kn, KnE, n);
    graphe_write(Kn, KnE, fout);
    if (HamiltonianCycle(Kn, fout))
      cout << "K" << n << " is hamiltonian." << endl;
    else
      cout << "K" << n << " is not hamiltonian." << endl;
    cout << HamiltonianCycles(Kn, fout) << " hamiltonian cycles found in " << "K" << n << endl;
    vector<color> Knc;
    fout << "Vertex coloring:" << endl;
    cout << "Vertex coloring." << endl;
    cout << MinimalVertexColoring(Kn, Knc, fout) << " required colors for the vertices of " << "K" << n << endl;
    cout << MinimalEdgeColoring(Kn, KnE, fout) << " required colors for the edges of " << "K" << n << endl;
    if (Hierholzer(Kn, KnE, fout))
      cout << "K" << n << " is eulerian." << endl;
    else
      cout << "K" << n << " is not eulerian." << endl;
    cout << endl;
  }
  fout.close();

  // Kn1n2
  fout.open("Kn1n2.out");
  cout << endl << "--- Bipartite Complete Graphs Kn1,n2 ---" << endl;
  for (index n = 3; n < 10; ++n)
    for (index n2 = 1; n2 <= n/2; ++n2) {
      index n1 = n-n2;
      graph Kn1n2;
      edges Kn1n2E;
      cout << "K" << n1 << "," << n2 << endl;
      fout << "K_" << n1 << "_" << n2 << endl;
      graphe_bipartite_complete(Kn1n2, Kn1n2E, n1, n2);
      graphe_write(Kn1n2, Kn1n2E, fout);
      if (HamiltonianCycle(Kn1n2, fout))
        cout << "K" << n1 << "," << n2 << " is hamiltonian." << endl;
      else
        cout << "K" << n1 << "," << n2 << " is not hamiltonian." << endl;
      cout << HamiltonianCycles(Kn1n2, fout) << " hamiltonian cycles found in " << "K" << n1 << "," << n2 << endl;
      vector<color> Kn1n2c;
      fout << "Vertex coloring:" << endl;
      cout << "Vertex coloring." << endl;
      cout << MinimalVertexColoring(Kn1n2, Kn1n2c, fout) << " required colors for the vertices of " << "K" << n1 << "," << n2 << endl;
      cout << MinimalEdgeColoring(Kn1n2, Kn1n2E, fout) << " required colors for the edges of " << "K" << n1 << "," << n2 << endl;
      if (Hierholzer(Kn1n2, Kn1n2E, fout))
        cout << "K" << n1 << "," << n2 << " is eulerian." << endl;
      else
        cout << "K" << n1 << "," << n2 << " is not eulerian." << endl;
      cout << endl;
    }
  fout.close();

  // Cn
  fout.open("Cn.out");
  cout << endl << "--- Cycle Graphs Cn ---" << endl;
  for (index n = 3; n < 9; ++n) {
    graph Cn;
    edges CnE;
    cout << "C" << n << endl;
    fout << "C_" << n << endl;
    graphe_cycle(Cn, CnE, n);
    graphe_write(Cn, CnE, fout);
    if (HamiltonianCycle(Cn, fout))
      cout << "C" << n << " is hamiltonian." << endl;
    else
      cout << "C" << n << " is not hamiltonian." << endl;
    cout << HamiltonianCycles(Cn, fout) << " hamiltonian cycles found in " << "C" << n << endl;
    vector<color> Cnc;
    fout << "Vertex coloring:" << endl;
    cout << "Vertex coloring." << endl;
    cout << MinimalVertexColoring(Cn, Cnc, fout) << " required colors for the vertices of " << "C" << n << endl;
    cout << MinimalEdgeColoring(Cn, CnE, fout) << " required colors for the edges of " << "C" << n << endl;
    if (Hierholzer(Cn, CnE, fout))
      cout << "C" << n << " is eulerian." << endl;
    else
      cout << "C" << n << " is not eulerian." << endl;
    cout << endl;
  }
  fout.close();

  // Sn
  fout.open("Sn.out");
  cout << endl << "--- Star Graphs Sn ---" << endl;
  for (index n = 3; n < 9; ++n) {
    graph Sn;
    edges SnE;
    cout << "S" << n << endl;
    fout << "S_" << n << endl;
    graphe_star(Sn, SnE, n);
    graphe_write(Sn, SnE, fout);
    if (HamiltonianCycle(Sn, fout))
      cout << "S" << n << " is hamiltonian." << endl;
    else
      cout << "S" << n << " is not hamiltonian." << endl;
    cout << HamiltonianCycles(Sn, fout) << " hamiltonian cycles found in " << "S" << n << endl;
    vector<color> Snc;
    fout << "Vertex coloring:" << endl;
    cout << "Vertex coloring." << endl;
    cout << MinimalVertexColoring(Sn, Snc, fout) << " required colors for the vertices of " << "S" << n << endl;
    cout << MinimalEdgeColoring(Sn, SnE, fout) << " required colors for the edges of " << "S" << n << endl;
    if (Hierholzer(Sn, SnE, fout))
      cout << "S" << n << " is eulerian." << endl;
    else
      cout << "S" << n << " is not eulerian." << endl;
    cout << endl;
  }
  fout.close();

  // Wn
  fout.open("Wn.out");
  cout << endl << "--- Wheel Graphs Wn ---" << endl;
  for (index n = 3; n < 9; ++n) {
    graph Wn;
    edges WnE;
    cout << "W" << n << endl;
    fout << "W_" << n << endl;
    graphe_wheel(Wn, WnE, n);
    graphe_write(Wn, WnE, fout);
    if (HamiltonianCycle(Wn, fout))
      cout << "W" << n << " is hamiltonian." << endl;
    else
      cout << "W" << n << " is not hamiltonian." << endl;
    cout << HamiltonianCycles(Wn, fout) << " hamiltonian cycles found in " << "W" << n << endl;
    vector<color> Wnc;
    fout << "Vertex coloring:" << endl;
    cout << "Vertex coloring." << endl;
    cout << MinimalVertexColoring(Wn, Wnc, fout) << " required colors for the vertices of " << "W" << n << endl;
    cout << MinimalEdgeColoring(Wn, WnE, fout) << " required colors for the edges of " << "W" << n << endl;
    if (Hierholzer(Wn, WnE, fout))
      cout << "W" << n << " is eulerian." << endl;
    else
      cout << "W" << n << " is not eulerian." << endl;
    cout << endl;
  }
  fout.close();

  // Ktn1n2
  fout.open("Ktn1n2.out");
  cout << endl << "--- Knight Graphs Ktn1,n2 ---" << endl;
  for (index n = 6; n < 14; ++n)
    for (index n2 = 1; n2 <= n/2; ++n2) {
      index n1 = n-n2;
      if ((n1 > 5 && n2 > 3) || n1 < 3 || n2 < 3)
        continue;

      graph Ktn1n2 = graph_knight(n1, n2);
      cout << "Kt" << n1 << "," << n2 << endl;
      fout << "Kt_" << n1 << "_" << n2 << endl;
      graph_write(Ktn1n2, fout);
      if (HamiltonianCycle(Ktn1n2, fout))
        cout << "Kt" << n1 << "," << n2 << " is hamiltonian." << endl;
      else
        cout << "Kt" << n1 << "," << n2 << " is not hamiltonian." << endl;
      cout << HamiltonianCycles(Ktn1n2, fout) << " hamiltonian cycles found in " << "Kt" << n1 << "," << n2 << endl;
      vector<color> Ktn1n2c;
      fout << "Vertex coloring:" << endl;
      cout << "Vertex coloring." << endl;
      cout << MinimalVertexColoring(Ktn1n2, Ktn1n2c, fout) << " required colors for the vertices of " << "K" << n1 << "," << n2 << endl;
      cout << endl;
    }
  fout.close();

  // E1
  fout.open("E1.out");
  cout << "--- Input Graph E1.in ---" << endl;
  graph E1;
  edges E1E;
  graphe_read(E1, E1E, "E1.in");
  graphe_write(E1, E1E, fout);
  cout << MinimalEdgeColoring(E1, E1E, fout) << " required colors for the edges of E1." << endl;
  if (Hierholzer(E1, E1E, fout))
    cout << "E1 is eulerian." << endl;
  else
    cout << "E1 is not eulerian." << endl;
  cout << endl;
  fout.close();

  // E2
  fout.open("E2.out");
  cout << "--- Input Graph E2.in ---" << endl;
  graph E2;
  edges E2E;
  graphe_read(E2, E2E, "E2.in");
  graphe_write(E2, E2E, fout);
  cout << MinimalEdgeColoring(E2, E2E, fout) << " required colors for the edges of E2." << endl;
  if (Hierholzer(E2, E2E, fout))
    cout << "E2 is eulerian." << endl;
  else
    cout << "E2 is not eulerian." << endl;
  cout << endl;
  fout.close();

  // E3
  fout.open("E3.out");
  cout << "--- Input Graph E3.in ---" << endl;
  graph E3;
  edges E3E;
  graphe_read(E3, E3E, "E3.in");
  graphe_write(E3, E3E, fout);
  cout << MinimalEdgeColoring(E3, E3E, fout) << " required colors for the edges of E3." << endl;
  if (Hierholzer(E3, E3E, fout))
    cout << "E3 is eulerian." << endl;
  else
    cout << "E3 is not eulerian." << endl;
  cout << endl;
  fout.close();

  // E4
  fout.open("E4.out");
  cout << "--- Input Graph E4.in ---" << endl;
  graph E4;
  edges E4E;
  graphe_read(E4, E4E, "E4.in");
  graphe_write(E4, E4E, fout);
  cout << MinimalEdgeColoring(E4, E4E, fout) << " required colors for the edges of E4." << endl;
  if (Hierholzer(E4, E4E, fout))
    cout << "E4 is eulerian." << endl;
  else
    cout << "E4 is not eulerian." << endl;
  cout << endl;
  fout.close();

  // League graph
  cout << "--- League Graphs ---" << endl;
  for (index n = 4; n < 15; n += 2) {
    fout.open("league" + to_string(n) + ".out");
    fout << "League of " << n << " teams" << endl;
    cout << "League of " << n << " teams" << endl;
    graph LG;
    edges LGE;
    graphe_complete(LG, LGE, n);
    graphe_write(LG, LGE, fout);
    vector<string> teams = Teams(n);
    color cn = LeagueSchedule(LG, LGE, teams, fout);
    cout << "Number of match days: " << cn << endl << endl;
    fout.close();
  }

  // Catalonia graph
  fout.open("catalonia.out");
  cout << "--- Regions of Catalonia graph ---" << endl;
  graph CG = graph_read("catalonia.in");
  graph_write(CG, fout);
  vector<color> CGc;
  fout << "Vertex coloring:" << endl;
  cout << "Vertex coloring." << endl;
  cout << MinimalVertexColoring(CG, CGc, fout) << " required colors for the regions of Catalonia." << endl << endl;
  fout.close();


  //
  // WEIGHTED GRAPHS
  //

  weight mw;

  // WKn
  fout.open("WKn.out");
  cout << endl << "--- Weighted Complete Graphs WKn ---" << endl;
  for (index n = 3; n < 9; ++n) {
    wgraph WKn = wgraph_complete(n, W_MAX);
    cout << "WK" << n << endl;
    fout << "WK_" << n << endl;
    wgraph_write(WKn, fout);
    mw = TravellingSalesmanProblem(WKn, fout);
    if (mw < UINT_MAX)
      cout << "TSP solution for WK" << n << " has weight " << mw << endl;
    else
      cout << "WK" << n << " is not hamiltonian, so TSP cannot be solved." << endl;
    cout << endl;
  }
  fout.close();

  //WKn1n2
  fout.open("WKn1n2.out");
  cout << endl << "--- Weighted Bipartite Complete Graphs WKn1,n2 ---" << endl;
  for (index n = 3; n < 9; ++n)
    for (index n2 = 1; n2 <= n/2; ++n2) {
      index n1 = n-n2;
      wgraph WKn1n2 = wgraph_bipartite_complete(n1, n2, W_MAX);
      cout << "WK" << n1 << "," << n2 << endl;
      fout << "WK_" << n1 << "_" << n2 << endl;
      wgraph_write(WKn1n2, fout);
      mw = TravellingSalesmanProblem(WKn1n2, fout);
      if (mw < UINT_MAX)
        cout << "TSP solution for WK" << n1 << "," << n2 << " has weight " << mw << endl;
      else
        cout << "WK" << n1 << "," << n2 << "is not hamiltonian, so TSP cannot be solved." << endl;
      cout << endl;
  }
  fout.close();

  // WCn
  fout.open("WCn.out");
  cout << endl << "--- Weighted Cycle Graphs WCn ---" << endl;
  for (index n = 3; n < 9; ++n) {
    wgraph WCn = wgraph_cycle(n, W_MAX);
    cout << "WC" << n << endl;
    fout << "WC_" << n << endl;
    wgraph_write(WCn, fout);
    mw = TravellingSalesmanProblem(WCn, fout);
    if (mw < UINT_MAX)
      cout << "TSP solution for WC" << n << " has weight " << mw << endl;
    else
      cout << "WC" << n << " is not hamiltonian, so TSP cannot be solved." << endl;
    cout << endl;
  }
  fout.close();

  // WSn
  fout.open("WSn.out");
  cout << endl << "--- Weighted Star Graphs WSn ---" << endl;
  for (index n = 3; n < 9; ++n) {
    wgraph WSn = wgraph_star(n, W_MAX);
    cout << "WS" << n << endl;
    fout << "WS_" << n << endl;
    wgraph_write(WSn, fout);
    mw = TravellingSalesmanProblem(WSn, fout);
    if (mw < UINT_MAX)
      cout << "TSP solution for WS" << n << " has weight " << mw << endl;
    else
      cout << "WS" << n << " is not hamiltonian, so TSP cannot be solved." << endl;
    cout << endl;
  }
  fout.close();

  // WWn
  fout.open("WWn.out");
  cout << endl << "--- Weighted Wheel Graphs WWn ---" << endl;
  for (index n = 3; n < 9; ++n) {
    wgraph WWn = wgraph_wheel(n, W_MAX);
    cout << "WW" << n << endl;
    fout << "WW_" << n << endl;
    wgraph_write(WWn, fout);
    mw = TravellingSalesmanProblem(WWn, fout);
    if (mw < UINT_MAX)
      cout << "TSP solution for WW" << n << " has weight " << mw << endl;
    else
      cout << "WW" << n << " is not hamiltonian, so TSP cannot be solved." << endl;
    cout << endl;
  }
  fout.close();


  // Cities graph
  fout.open("cities.out");
  cout << "--- Cities Graph ---" << endl;
  wgraph WC = wgraph_read("cities.in");
  wgraph_write(WC, fout);
  mw = TravellingSalesmanProblem(WC, fout);
  if (mw < UINT_MAX)
    cout << "TSP solution for the cities graph has weight " << mw << endl;
  else
    cout << "The cities graph is not hamiltonian, so TSP cannot be solved." << endl;
  cout << endl;
  fout.close();


  // Dodecahedron
  fout.open("D.out");
  cout << "--- Weighted Dodecahedron ---" << endl;
  wgraph WD = wgraph_read("WD.in");
  graph D = WgraphToGraph(WD);
  wgraph_write(WD, fout);
  mw = TravellingSalesmanProblem(WD, fout);
  if (mw < UINT_MAX)
    cout << "TSP solution for the dodecahedron has weight " << mw << endl;
  else
    cout << "Dodecahedron is not hamiltonian, so TSP cannot be solved." << endl;
  vector<color> Dc;
  fout << "Vertex coloring:" << endl;
  cout << "Vertex coloring." << endl;
  cout << MinimalVertexColoring(D, Dc, fout) << " required colors for the vertices." << endl;
  cout << endl;
  fout.close();

  // Iscosahedron
  fout.open("I.out");
  cout << "--- Weighted Icosahedron ---" << endl;
  wgraph WI = wgraph_read("WI.in");
  graph I = WgraphToGraph(WI);
  wgraph_write(WI, fout);
  mw = TravellingSalesmanProblem(WI, fout);
  if (mw < UINT_MAX)
    cout << "TSP solution for the icosahedron has weight " << mw << endl;
  else
    cout << "Icosahedron is not hamiltonian, so TSP cannot be solved." << endl;
  vector<color> Ic;
  fout << "Vertex coloring:" << endl;
  cout << "Vertex coloring." << endl;
  cout << MinimalVertexColoring(I, Ic, fout) << " required colors for the vertices." << endl;
  cout << endl;
  fout.close();


  // END
  cout << "Press enter to finish...";
  cin.get();
  return 0;

}
