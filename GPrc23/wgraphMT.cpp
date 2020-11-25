// NOM: Marc Ballestero Ribó.
// GRUP: M1a.
// DATA d'ENTREGA: 28/11/2020.


#include "wgraph.h"

weight KruskalTrees(wgraph &G, ofstream &fout)
{
  vertex vn = G.size();
  vector<component> KT(vn);
  for (vertex v = 0; v < vn; ++v)
    KT[v] = v;
  vector<weight> Kw(vn, 0);
  weight infty = UINT_MAX;
  weight Tw = 0;

  do {
    weight mw = infty;
    vertex mv;
    index mvi;
    for (vertex v = 0; v < vn; ++v)
      for (index i = 0; i < G[v].size(); ++i)
        if (mw > G[v][i].second && KT[v] != KT[G[v][i].first]) {
          mw = G[v][i].second;
          mv = v;
          mvi = i;
        }

    if (mw == infty)
      break;

    vertex mva = G[mv][mvi].first;

    fout << "Minimal edge: " << mv << "(" << mvi << ") - " << mva;
    fout << " [" << mw << "]" << endl;

    Tw += mw;
    component mKT = min(KT[mv], KT[mva]), MKT = max(KT[mv], KT[mva]);
    for (vertex v = 0; v < vn; ++v)
      if (KT[v] == MKT)
        KT[v] = mKT;

    Kw[mKT] += Kw[MKT] + mw;
    Kw[MKT] = 0;
  } while (true);

  for (vertex v = 0; v < vn; ++v)
    if (KT[v] == v) {
      fout << "Component of vertex " << v << ": ";
      for (vertex u = 0; u < vn; ++u)
        if (KT[u] == v)
          fout << u << " ";

      fout << "\tWeight: " << Kw[v] << endl;
    }

  return Tw;
}

weight PrimTrees (wgraph &G, ofstream &fout)
{
  vertex vn = G.size();
  weight infty = UINT_MAX;
  vector<vertex> Pp(vn, vn);
  vector<component> PT(vn, infty);
  vector<weight> Pw(vn, 0);
  weight Tw = 0;
  component Tn = 0;

  do {
    weight mw = infty;
    vertex mv;
    index mvi;
    for (vertex v = 0; v < vn; ++v)
      if (Pp[v] == vn)
        for (index i = 0; i < G[v].size(); ++i)
          if (mw > G[v][i].second) {
            mw = G[v][i].second;
            mv = v;
            mvi = i;
          }

    if (mw == infty)
      break;

    vertex mva = G[mv][mvi].first;
    fout << "Minimal edge: " << mv << "(" << mvi << ") - " << mva;
    fout << " [" << mw << "]" << endl;

    Pp[mv] = mv;
    Pp[mva] = mv;
    PT[mv] = Tn;
    PT[mva] = Tn;
    Pw[Tn] += mw;
    Tw += mw;

    do {
      mw = infty;
      for (vertex v = 0; v < vn; ++v)
        if (Pp[v] < vn)
          for (index i = 0; i < G[v].size(); ++i)
            if (mw > G[v][i].second && Pp[G[v][i].first] == vn) {
              mw = G[v][i].second;
              mv = v;
              mvi = i;
            }

      if (mw == infty)
        break;

      vertex mva = G[mv][mvi].first;
      fout << "Minimal edge: " << mv << "(" << mvi << ") - " << mva;
      fout << " [" << mw << "]" << endl;

      Pp[mva] = mv;
      PT[mv] = Tn;
      PT[mva] = Tn;
      Pw[Tn] += mw;
      Tw += mw;

    } while (true);

    ++Tn;
  } while(true);

  for (component Ti = 0; Ti < Tn; ++Ti) {
    fout << "Component #" << Ti << ": ";
    for (vertex u = 0; u < vn; ++u)
      if (PT[u] == Ti)
        fout << u << " ";

    fout << "\tWeight: " << Pw[Ti] << endl;

    fout << "Edges:" << endl;
    for (vertex u = 0; u < vn; ++u)
        for (vertex v = u; v < vn; ++v)
          if ((u == Pp[v] || v == Pp[u]) && u != v && PT[u] == Ti)
            fout << u << "-" << v << endl;
  }

  for (vertex v = 0; v < vn; ++v)
    if (PT[v] == infty) {
      fout << "Component #" << Tn << ": " << v << " [0]" << endl;
      ++Tn;
    }


  return Tw;
}
