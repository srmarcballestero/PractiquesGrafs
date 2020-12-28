// NOM: Marc Ballestero Ribó.
// GRUP: M1a.
// DATA d'ENTREGA: 13/01/2021.


#include <ctime>

#include "graphe.h"
#include "graph.h"


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


  cout << "Press enter to finish...";
  cin.get();
  return 0;
}
