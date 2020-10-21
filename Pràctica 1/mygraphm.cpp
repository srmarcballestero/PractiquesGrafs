#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

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
vector<vector<int>> graphM_read(string fname)
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
// Write graph from adjaceny matrix to filestream.
//
void graphM_write(vector<vector<int>> &M, ofstream &fout)
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


int main ()
{
  ofstream fout;

  // graph0.in
  fout.open("graph0.out");
  vector<vector<int>> M0 = graphM_read("graph0.in");
  graphM_write(M0, fout);
  fout.close();

  // graph1.in
  fout.open("graph1.out");
  vector<vector<int>> M1 = graphM_read("graph1.in");
  graphM_write(M1, fout);
  fout.close();

  // graph2.in
  fout.open("graph2.out");
  vector<vector<int>> M2 = graphM_read("graph2.in");
  graphM_write(M2, fout);
  fout.close();

  // graph3.in
  fout.open("graph3.out");
  vector<vector<int>> M3 = graphM_read("graph3.in");
  graphM_write(M3, fout);
  fout.close();

  // K10
  fout.open("K10.out");
  vector<vector<int>> MK10 = graphM_complete(10);
  graphM_write(MK10, fout);
  fout.close();

  // K6_4
  fout.open("K6_4.out");
  vector<vector<int>> K6_4 = graphM_bipartite_complete(6, 4);
  graphM_write(K6_4, fout);
  fout.close();

  // K4_6
  fout.open("K4_6.out");
  vector<vector<int>> K4_6 = graphM_bipartite_complete(4, 6);
  graphM_write(K4_6, fout);
  fout.close();

  // C10
  fout.open("C10.out");
  vector<vector<int>> MC10 = graphM_cycle(10);
  graphM_write(MC10, fout);
  fout.close();

  // S10
  fout.open("S10.out");
  vector<vector<int>> MS10 = graphM_star(10);
  graphM_write(MS10, fout);
  fout.close();

  // W10
  fout.open("W10.out");
  vector<vector<int>> MW10 = graphM_wheel(10);
  graphM_write(MW10, fout);
  fout.close();

  // G4_3
  fout.open("G4_3.out");
  vector<vector<int>> MG4_3 = graphM_grid(4, 3);
  graphM_write(MG4_3, fout);
  fout.close();

  // G3_4
  fout.open("G3_4.out");
  vector<vector<int>> MG3_4 = graphM_grid(3, 4);
  graphM_write(MG3_4, fout);
  fout.close();

  return 0;
}
