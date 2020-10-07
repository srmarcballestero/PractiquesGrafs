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
//  Star graph to adjacency matrix
//
vector<vector<int>> graphM_star (int n)
{
  vector<vector<int>> SnM (n+1, vector<int>(n+1, 0));
//
// ...
//

  return SnM;
}

//
//  Wheel graph to adjacency matrix
//
vector<vector<int>> graphM_wheel (int n)
{
  vector<vector<int>> WnM (n+1, vector<int>(n+1, 0));
//
// ...
//

  return WnM;
}
