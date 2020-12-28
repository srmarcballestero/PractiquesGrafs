// NOM: Marc Ballestero Ribó.
// GRUP: M1a.
// DATA d'ENTREGA: 13/01/2021.


#include "graphe.h"

//
// Vertex coloring of one vertex.
//
color Vertex1Coloring(graph &G, vector<color> &Gc, color cn, vertex v, color oc)
{
  vector<bool> avc(cn+1, false);
  for (index i = 0; i < G[v].size(); ++i)
    if (G[v][i] < v)
      avc[Gc[G[v][i]]] = true;

  color c;
  for (c = oc; c < cn+1; ++c)
    if (!avc[c]) {
      Gc[v] = c;
      break;
    }

  if (c == cn+1)
    Gc[v] = ++cn;

  return cn;
}

//
// Brélaz coloring method.
//
color BrelazColoring(graph &G, vector<color> &Gc)
{
  color cn;
  vertex vn = G.size();

  Gc[0] = cn = 1;
  for (vertex v = 1; v < vn; ++v)
    cn = Vertex1Coloring(G, Gc, cn, v, 1);

  return cn;
}


//
// Minimal vertex coloring of graph.
//
color MinimalVertexColoring(graph &G, vector<color> &Gc, ofstream &fout)
{
  vertex vn = G.size();

  Gc = vector<color> (vn, 0);
  vector<color> Gpc(vn);
  color cn = BrelazColoring(G, Gpc);

  do {
    fout << "Coloring with " << cn << " colors:" << endl;
    cout << "Coloring with " << cn << " colors." << endl;

    Gc = Gpc;
    for (vertex v = 0; v < vn; ++v)
      fout << v << "\t" << Gc[v] << endl;

    for (color cv = 1; cv < cn+1; ++cv) {
      fout << "Color #" << cv << " : ";
      for (vertex v = 0; v < vn; ++v)
        if (Gc[v] == cv)
          fout << v << " ";
      fout << endl;
    }

    vertex cnv;
    for (cnv = 0; cnv < vn; ++cnv)
      if (Gpc[cnv] == cn)
        break;

    do {
      do {
        --cnv;
        if (cnv == 0) {
          fout << "Minimal vertex coloring found with " << cn << " colors." << endl << endl;
          return cn;
        }
        Vertex1Coloring(G, Gpc, cn, cnv, Gpc[cnv]+1);
      } while (Gpc[cnv] >= cn);

      for (++cnv; cnv < vn; ++cnv) {
        Vertex1Coloring(G, Gpc, cn, cnv, 1);
        if (Gpc[cnv] >= cn)
          break;
      }
    } while (cnv < vn);

    --cn;
  } while(true);

}

//
// Edge coloring by vertex coloring line graph.
//
color MinimalEdgeColoring(graph &G, edges &GE, ofstream &fout)
{
  graph LG;
  vector<color> LGc;
  edges LGE;
  line_graphe(G, GE, LG, LGE);

  fout << "Associate line graph:" << endl;
  graphe_write(LG, LGE, fout);

  fout << "Line graph vertex coloring:" << endl;
  cout << "Edge coloring." << endl;

  color ecn = MinimalVertexColoring(LG, LGc, fout);
  vertex vn = G.size();
  fout << "Edge coloring:" << endl;
  fout << "Edge\t\t" << "Color" << endl;
  for (vertex v = 0; v < vn; ++v)
    for (index i = 0; i < G[v].size(); ++i)
      if (v < G[v][i])
        fout << v << "-" << G[v][i] << "(" << GE[vip(v, i)] << ")" << "\t" << LGc[GE[vip(v, i)]] << endl;

  for (color ec = 1; ec < ecn+1; ++ec) {
    fout << "Color #" << ec << ":" << endl;
    for (vertex v = 0; v < vn; ++v)
      for (index i = 0; i < G[v].size(); ++i)
        if (v < G[v][i] && LGc[GE[vip(v, i)]] == ec)
          fout << v << "-" << G[v][i] << " (" << GE[vip(v, i)] << ")\t" << endl;
  }
  fout << endl;

  return ecn;
}

//
// League scheduling with n teams.
//
color LeagueSchedule(graph &G, edges &GE, vector<string> teams, ofstream &fout)
{
  graph LG;
  edges LGE;
  vector<color> LGc;
  line_graphe(G, GE, LG, LGE);
  color ecn =  MinimalVertexColoring(LG, LGc, fout);

  fout << "Teams:" << endl;
  for (index i = 0; i < teams.size(); ++i)
    fout << teams[i] << endl;
  fout << endl;

  fout << "Schedule:" << endl;
  for (color ec = 1; ec < ecn+1; ++ec) {
    fout << "Match day #" << ec << ":" << endl;
    for (vertex v = 0; v < G.size(); ++v)
      for (index i = 0; i < G[v].size(); ++i)
        if (v < G[v][i]) {
          if (LGc[GE[vip(v, i)]] == ec) {
            fout << teams[v] << " vs. " << teams[G[v][i]] << endl;
          }
        }
    fout << endl;
  }

  return ecn;
}

//
// Returns n league teams names.
//
vector<string> Teams(index n)
{
  vector<string> teams(14);
  vector<string> nTeams(n);

  teams[0] = "New Caledonia Mandrills";
  teams[1] = "Prussia Raccoons";
  teams[2] = "Carolingian Sloths";
  teams[3] = "Belarus Gnus";
  teams[4] = "North Korea Bears";
  teams[5] = "Alaska Beavers";
  teams[6] = "Atlantis Seahorses";
  teams[7] = "Mars Hedgehogs";
  teams[8] = "New Guinea Guinea Pigs";
  teams[9] = "East Germany Capuchins";
  teams[10] = "Bhutan Wildcats";
  teams[11] = "Antarctic Red foxes";
  teams[12] = "Wuhan Pangolins";
  teams[13] = "Ottoman Lizards";

  for (index i = 0; i < n; ++i)
    nTeams[i] = teams[i];

  return nTeams;
}
