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

  // Kn
  fout.open("Kn.out");
  cout << endl << "--- Complete Graphs Kn ---" << endl;
  for (index n = 3; n < 9; ++n) {
    graph Kn;
    edges KnE;
    cout << "K" << n << endl;
    fout << "C_" << n << endl;
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


  // CATALONIA
  // ...

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


  weight mw;

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
