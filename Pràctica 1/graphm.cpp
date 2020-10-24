// NOM: Marc Ballestero Ribó.
// GRUP: M1a.
// DATA d'ENTREGA: 23/10/2020.

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;


//
//  Complete graph to adjacency matrix
//
vector<vector<int>> graphM_complete (int n)
{
  vector<vector<int>> KnM(n, vector<int>(n, 0));

  for (int i = 0; i < n; ++i)
    for (int j = i+1; j < n; ++j)
      KnM[i][j] = KnM[j][i] = 1;

  return KnM;
}

//
//  Bipartite complete graph to adjacency matrix
//
vector<vector<int>> graphM_bipartite_complete (int n1, int n2)
{
  vector<vector<int>> Kn1n2M (n1+n2, vector<int>(n1+n2, 0));

  for (int i = 0; i < n1; ++i)
    for (int j = n1; j < n1+n2; ++j)
      Kn1n2M[i][j] = Kn1n2M[j][i] = 1;

  return Kn1n2M;
}

//
//  Cycle graph to adjacency matrix
//
vector<vector<int>> graphM_cycle (int n)
{
  vector<vector<int>> CnM(n, vector<int>(n, 0));

  for (int i = 0; i < n-1; ++i)
    CnM[i][i+1] = CnM[i+1][i] = 1;
  CnM[n-1][0] = CnM[0][n-1] = 1;

  return CnM;
}

//
//  Star graph to adjacency matrix
//
vector<vector<int>> graphM_star (int n)
{
  vector<vector<int>> SnM (n+1, vector<int>(n+1, 0));

  for (int i = 0; i < n; ++i)
    SnM[n][i] = SnM[i][n] = 1;

  return SnM;
}

//
//  Wheel graph to adjacency matrix
//
vector<vector<int>> graphM_wheel (int n)
{
  vector<vector<int>> WnM (n+1, vector<int>(n+1, 0));

  for (int i = 0; i < n; ++i)
  {
    WnM[i][i+1] = WnM[i+1][i] = 1;
    WnM[n][i] = WnM[i][n] = 1;
  }
  WnM[0][n-1] = WnM[n-1][0] = 1;

  return WnM;
}

//
//  Grid graph to adjacency matrix
//
vector<vector<int>> graphM_grid (int n1, int n2)
{
  vector<vector<int>> Gn1n2M (n1*n2, vector<int>(n1*n2, 0));

  for (int i = 0; i < n1; ++i)
    for (int j = 0; j < n2; ++j)
    {
      int v = i*n2 + j;
      if (j < n2 - 1)
        Gn1n2M[v][v+1] = Gn1n2M[v+1][v] = 1;
      if (i < n1 - 1)
        Gn1n2M[v][v+n2] = Gn1n2M[v+n2][v] = 1;
    }

  return Gn1n2M;
}

//
//  Read graph from file fname of edges to adjacency matrix.
//
vector<vector<int>> graphM_read (string fname)
{
  ifstream fin;
  fin.open( fname.c_str());
  if (fin.fail())
  {
    cerr << "unable to open file " << fname.c_str() << "for reading." << endl;
    exit(1);
  }

  int n, m;
  fin >> n >> m;

  vector<vector<int>> M(n, vector<int>(n, 0));

  for (int i = 0; i < m; ++i)
  {
    int u, v;
    fin >> u >> v;

    if (u == v)
      M[u][u] += 2;

    else
      M[u][v] = ++M[v][u];
  }
  return M;
}

//
// Write graph from adjacency matrix to filestream.
//
void graphM_write (vector<vector<int>> &M, ofstream &fout)
{
  int n = M.size();
  int m = 0;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < i+1; ++j)
    {
      if (i == j)
        m += M[i][i] / 2;
      else
        m += M[i][j];
    }

  fout << "Graph with " << n << " vertices and " << m << " edges " << endl;

  fout << "Adjacency matrix" << endl;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
      fout << "\t" << M[i][j];
    fout << endl;
  }

  fout << "Edges" << endl;
    for( int i = 0; i < n; ++i)
      for (int j = i; j < n; ++j)
      {
        if (i == j)
          for (int k = 0; k < M[i][i] / 2; ++k)
            fout << i << " " << i << endl;
        else
          for (int k = 0; k < M[i][j]; ++k)
            fout << i << " " << j << endl;
      }
  return;
}

//
// Test if two graphs are equal.
//
bool Test_Equality (vector<vector<int>> &M1, vector<vector<int>> &M2)
{
  int n1 = M1.size(), n2 = M2.size();

  if (n2 != n1)
    return false;

  for (int i = 0; i < n1; ++i)
    for (int j = 0; j < n1; ++j)
      if (M1[i][j] != M2[i][j])
        return false;

  return true;
}

//
// Test if a given permutation is a graph isomorphism.
//
bool Test_P_Isomorphism (vector<vector<int>> &M1, vector<vector<int>> &M2, vector<int> &P)
{
  int n1 = M1.size(), n2 = M2.size();

  if (n2 != n1)
    return false;

  for (int i = 0; i < n1; ++i)
    for (int j = 0; j < n2; ++j)
      if (M1[i][j] != M2[P[i]][P[j]])
        return false;

  return true;
}

//
// Test if a given permutation is a graph automorphism.
//
bool Test_P_Automorphism (vector<vector<int>> &M, vector<int> &P)
{
  int n = M.size(), nP = P.size();

  if (nP != n)
    return false;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (M[i][j] != M[P[i]][P[j]])
        return false;

  return false;
}

//
// Test if two graphs are isomorphic.
//
bool Test_Isomorphism (vector<vector<int>> &M1, vector<vector<int>> &M2)
{
  int n1 = M1.size(), n2 = M2.size();
  vector<int> P(n1);

  if (n1 != n2)
    return false;

  for (int i = 0; i < n1; ++i)
    P[i] = i;

  do
  {
    if (Test_P_Isomorphism(M1, M2, P))
      return true;
  } while (next_permutation(P.begin(), P.end()));

  return false;
}

//
// Returns a random permutation of a given order.
//
vector<int> Random_Permutation (int n)
{
  vector<int> RP(n);
  vector<bool> B(n, false);
  int r;

  for (int i = 0; i < n; ++i)
  {
    r = rand() % (n - i);
    for (int j = 0; j < r+1; ++j)
      if (B[j])
        ++r;

    B[r] = true;
    RP[i] = r;
  }

  return RP;
}

//
// Returns the permutated adjacency matrix of a graph.
//
vector<vector<int>> graphM_Permutate (vector<vector<int>> &M, vector<int> &P)
{
  int n = M.size(), nP = P.size();
  vector<vector<int>> MP(n, vector<int>(n, 0));

  if (nP != n)
  {
    cerr << "The adjacency matrix and the permutation have different dimensions." << endl;
    exit(1);
  }

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      MP[i][j] = M[P[i]][P[j]];

  return MP;
}

//
// Write all the possible isomorphisms between two graphs.
//
int Isomorphisms (vector<vector<int>> &M1, vector<vector<int>> &M2, ofstream &fout)
{
  int n1 = M1.size(), n2 = M2.size(), isoN = 0;
  vector<int> P(n1);

  if (n1 != n2)
    return 0;

  for (int i = 0; i < n1; ++i)
    P[i] = i;

  do
  {
    if (Test_P_Isomorphism(M1, M2, P))
    {
      ++isoN;
      fout << "Isomorphism #" << isoN << " : ";
      for (int i = 0; i < n1; ++i)
        fout << " " << P[i];
      fout << endl;
    }
  } while (next_permutation(P.begin(), P.end()));

  return isoN;
}

//
// Write all possible automorphisms of a graph.
//

int Automorphisms (vector<vector<int>> &M, ofstream &fout)
{
  int n = M.size(), autN = 0;
  vector<int> P(n), O(n);

  for (int i = 0; i < n; ++i)
    P[i] = O[i] = i;

  do
  {
    if (Test_P_Isomorphism(M, M, P))
    {
      ++autN;
      fout << "Automorphism  #" << autN << ":";
      for (int i = 0; i < n; ++i)
      {
        fout << " " << P[i];

        if (O[i] < O[P[i]])
          O[P[i]] = O[i];
        if (O[P[i]] < O[i])
          O[i] = O[P[i]];
      }
      fout << endl;
    }
  } while (next_permutation(P.begin(), P.end()));

  for (int i = 0; i < n; ++i)
  {
    if (O[i] == i)
    {
      fout << "Orbit #" << i << ":";
      for (int j = 0; j < n; ++j)
        if(O[j] == i)
          fout << " " << j;
      fout << "; ";
    }
  }
  fout << endl;

  return autN;
}


//
// Main function.
//
int main ()
{
  ofstream fout;
  srand(time(NULL));

  //
  // FILE: graph0.out
  //
  fout.open("graph0.out");
  vector<vector<int>> M0 = graphM_read("graph0.in");
  graphM_write(M0, fout);
  fout.close();


  //
  // FILE: graph1.out
  //
  fout.open("graph1.out");
  vector<vector<int>> M1 = graphM_read("graph1.in");
  graphM_write(M1, fout);
  fout.close();

  // Test if (1,2,3,0) is a graph1.in automorphism.
  vector<int> P4{1,2,3,0};
  if (Test_P_Automorphism(M1, P4))
    cout << "P4 is a graph1 automorphism." << endl;
  else
    cout << "P4 is NOT a graph1 automorphism." << endl;


  //
  // FILE: graph2.out
  //
  fout.open("graph2.out");
  vector<vector<int>> M2 = graphM_read("graph2.in");
  graphM_write(M2, fout);
  fout.close();

  // Test if graph1.in and graph2.in are the same.
  if (Test_Equality(M1, M2))
    cout << "graph1 and graph2 are equal." << endl;
  else
    cout << "graph1 and graph2 are NOT equal." << endl;

  //
  // FILE: graph3.out
  //
  fout.open("graph3.out");
  vector<vector<int>> M3 = graphM_read("graph3.in");
  graphM_write(M3, fout);
  fout.close();

  // Test if (1,2,3,0) is an isomorphism between graph1.in and graph3.in.
  if (Test_P_Isomorphism(M1, M3, P4))
    cout << "graph1 and graph3 are P4-isomorphic." << endl;
  else
    cout << "graph1 and graph3 are NOT P4-isomorphic." << endl;


  //
  // FILE: graph8.out
  //
  // Write all the automorphisms of graph8A.in.
  fout.open("graph8.out");
  vector<vector<int>> M8A = graphM_read("graph8A.in");
  fout << "Graph 8A:" << endl;
  graphM_write(M8A, fout);
  fout << "Graph 8A 's automorphisms and orbits:" << endl;
  cout << "There are " << Automorphisms(M8A, fout) << " graph 8A automorphisms." << endl;

  // Write all the automorphisms of graph8B.in.
  vector<vector<int>> M8B = graphM_read("graph8B.in");
  fout << "Graph 8B:" << endl;
  graphM_write(M8B, fout);
  fout << "Graph 8B 's automorphisms and orbits:" << endl;
  cout << "There are " << Automorphisms(M8B, fout) << " graph 8B automorphisms." << endl;

  // Write all the isomorphisms between graph8A.in and graph8B.in.
  fout << "Isomorphisms between graph8A and graph8B:" << endl;
  cout << "There are " << Isomorphisms(M8A, M8B, fout) << " isomorphisms between graph8A and graph8B." << endl;
  fout.close();


  //
  // FILE: graph10.out
  //
  // Write all the automorphisms of graph10A.in.
  fout.open("graph10.out");
  vector<vector<int>> M10A = graphM_read("graph10A.in");
  fout << "Graph 10A:" << endl;
  graphM_write(M10A, fout);
  fout << "Graph 10A 's automorphisms and orbits:" << endl;
  cout << "There are " << Automorphisms(M10A, fout) << " graph 10A automorphisms." << endl;

  // Write all the automorphisms of graph10B.in.
  vector<vector<int>> M10B = graphM_read("graph10B.in");
  fout << "Graph 10B:" << endl;
  graphM_write(M10B, fout);
  fout << "Graph 10B 's automorphisms and orbits:" << endl;
  cout << "There are " << Automorphisms(M10B, fout) << " graph 10B automorphisms." << endl;

  // Write all the isomorphisms between graph10A.in and graph10B.in.
  fout << "Isomorphisms between graph10A and graph10B:" << endl;
  cout << "There are " << Isomorphisms(M10A, M10B, fout) << " isomorphisms between graph10A and graph10B." << endl;
  fout.close();


  //
  // FILE: K10.out
  //
  fout.open("K10.out");
  vector<vector<int>> MK10 = graphM_complete(10);
  graphM_write(MK10, fout);

  // Write all the automorphisms of K10.
  fout << "Graph K10 's automorphisms and orbits:" << endl;
  cout << "There are " << Automorphisms(MK10, fout) << " graph K10 automorphisms." << endl;

  fout.close();


  //
  // FILE: C10.out
  //
  fout.open("C10.out");
  vector<vector<int>> MC10 = graphM_cycle(10);
  graphM_write(MC10, fout);

  // Write all the automorphisms of C10.
  fout << "Graph C10 's automorphisms and orbits:" << endl;
  cout << "There are " << Automorphisms(MC10, fout) << " graph C10 automorphisms." << endl;

  fout.close();


  //
  // FILE: S10.out
  //
  fout.open("S10.out");
  vector<vector<int>> MS10 = graphM_star(10);
  graphM_write(MS10, fout);

  // Write all the automorphisms of S10.
  fout << "Graph S10 's automorphisms and orbits:" << endl;
  cout << "There are " << Automorphisms(MS10, fout) << " graph S10 automorphisms." << endl;

  fout.close();


  //
  // FILE: W10.out
  //
  fout.open("W10.out");
  vector<vector<int>> MW10 = graphM_wheel(10);
  graphM_write(MW10, fout);

  // Write all the automorphisms of W10.
  fout << "Graph W10 's automorphisms and orbits:" << endl;
  cout << "There are " << Automorphisms(MW10, fout) << " graph W10 automorphisms." << endl;

  fout.close();


  //
  // FILE: K6_4.out
  //
  // Write all automorphisms of K6_4.
  fout.open("K6_4.out");
  vector<vector<int>> MK6_4 = graphM_bipartite_complete(6, 4);
  fout << "Graph K6_4:" << endl;
  graphM_write(MK6_4, fout);
  fout << "Graph K6_4 's automorphisms and orbits:" << endl;
  cout << "There are " << Automorphisms(MK6_4, fout) << " graph K6_4 automorphisms." << endl;

  // Write all automorphisms of K4_6.
  vector<vector<int>> MK4_6 = graphM_bipartite_complete(4, 6);
  fout << "Graph K4_6:" << endl;
  graphM_write(MK4_6, fout);
  fout << "Graph K4_6 's automorphisms and orbits:" << endl;
  cout << "There are " << Automorphisms(MK4_6, fout) << " graph K4_6 automorphisms." << endl;

  // Write all the isomorphisms between K6_4 and K4_6.
  fout << "Isomorphisms between K6_4 and K4_6:" << endl;
  cout << "There are " << Isomorphisms(MK6_4, MK4_6, fout) << " isomorphisms between K6_4 and K4_6." << endl;
  fout.close();

  // Test if (8,5,3,2,4,9,1,0,7,6) is an isomorphism between K6_4 and K4_6.
  vector<int> P10{8,5,3,2,4,9,1,0,7,6};
  if (Test_P_Isomorphism(MK6_4, MK4_6, P10))
    cout << "K6_4 and K4_6 are P10-isomorphic." << endl;
  else
    cout << "K6_4 and K4_6 are NOT P10-isomorphic." << endl;

  // Test if a random permutation of order 10 RP10 and check if K6_4 permuatated
  // by RP10 is isomorphic to K6_4.
  vector<int> RP10 = Random_Permutation(10);
  vector<vector<int>> MK6_4_RP10 = graphM_Permutate(MK6_4, RP10);
  if (Test_Isomorphism(MK6_4, MK6_4_RP10))
    cout << "K6_4 and K6_4 permutated randomly by RP10 are isomorphic." << endl;
  else
    cout << "K6_4 and K6_4 permutated randomly by RP10 are NOT isomorphic." << endl;


  //
  // FILE: G4_3.out
  //
  // Write all automorphisms of G4_3.
  fout.open("G4_3.out");
  vector<vector<int>> MG4_3 = graphM_grid(4, 3);
  fout << "Graph G4_3:" << endl;
  graphM_write(MG4_3, fout);
  fout << "Graph G4_3 's automorphisms and orbits:" << endl;
  cout << "There are " << Automorphisms(MG4_3, fout) << " graph G4_3 automorphisms." << endl;

  // Write all automorphisms of G4_3.
  vector<vector<int>> MG3_4 = graphM_grid(3, 4);
  fout << "Graph G3_4:" << endl;
  graphM_write(MG3_4, fout);
  fout << "Graph G3_4 's automorphisms and orbits:" << endl;
  cout << "There are " << Automorphisms(MG3_4, fout) << " graph G3_4 automorphisms." << endl;

  // Write all the isomorphisms between G4_3 and G3_4.
  fout << "Isomorphisms between G4_3 and G3_4:" << endl;
  cout << "There are " << Isomorphisms(MG4_3, MG3_4, fout) << " isomorphisms between G4_3 and G3_4." << endl;
  fout.close();

  // Finish.
  cout << endl << "Press enter to finish...";
  cin.get();

  return 0;
}
