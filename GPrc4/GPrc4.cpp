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
  for (int n = 3; n < 8; ++n) {
    graph Kn;
    edges KnE;
    graphe_complete(Kn, KnE, n);
    graphe_write(Kn, KnE, fout);
    cout << "K" << n << endl;
    fout << endl << "K_" << n << endl;
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

  cout << "Press enter to finish...";
  cin.get();
  return 0;
}
