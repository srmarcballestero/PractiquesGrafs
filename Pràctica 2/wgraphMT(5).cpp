#include "wgraph.h"

 weight
	 KruskalTrees(wgraph& G, ofstream& fout)
 {
	 vertex vn = G.size();
	 vector<component> KT(vn);
	 vector<weight> Kw(vn,0);
	 for (vertex v = 0; v < vn; v++)
		 KT[v] = v;
	 weight infty = UINT_MAX;
	 weight Tw = 0;
	 do {
	//   Cerca d'aresta minimal entre components diferents
    //         v ------ G[v][i].first  [G[v][i].second]
		 weight mw = infty;
		 vertex mv; index mvi;
		 for( vertex v=0; v<vn; v++ )
			 for( index i=0; i<G[v].size(); i++ )
				 if (mw > G[v][i].second && KT[v] != KT[G[v][i].first]) {
					 mw = G[v][i].second;
					 mv = v;
					 mvi = i;
				 }
		 if (mw == infty)
			 break;
     //       mv (mvi) ------ mva = G[mv][mvi].first  [mw]
     //      KT[mv]           KT[mva]

     // 
		 vertex mva = G[mv][mvi].first;
		 fout << "Aresta minimal : " << mv << "(" << mvi << ") - " << mva;
		 fout << " [" << mw << "]" << endl;
		 Tw += mw;
     //  Unir components
		 component mKT = min(KT[mv], KT[mva]), MKT = max(KT[mv], KT[mva]);
	 //  Posa tots els vèrtexs de la component MKT a la component mKT
     //   ... 

		 Kw[mKT] += Kw[MKT] + mw;
		 Kw[MKT] = 0;
      //           mw
	  //      mKT  --  MKT	        mKT
	 } while (true);
     //  Escriure a fout: els vèrtexs que conformen cada component
	 //  i el pes de l'arbre minimal en aquesta component

	 return Tw;
 }


 weight
	 PrimTrees(wgraph& G, ofstream& fout)
 {
	 vertex vn = G.size();
	 vector<vertex> Pp(vn, vn);
	 vector<component> PT(vn);
	 vector<weight> Pw(vn, 0);
	 weight infty = UINT_MAX;
	 weight Tw = 0;
	 component Tn = 0;
	 do {
	 //   Cerca d'aresta minimal que no sigui de les components anteriors
	 //        
		 weight mw = infty;
		 vertex mv; index mvi;
		 for (vertex v = 0; v < vn; v++)
			 if( Pp[v]==vn )
			 for (index i = 0; i < G[v].size(); i++)
				 if (mw > G[v][i].second ) {
					 mw = G[v][i].second;
					 mv = v;
					 mvi = i;
				 }
		 if (mw == infty)
			 break;
		 //       mv (mvi) ------ mva = G[mv][mvi].first  [mw]
	     //                         mv                         	
		 //                          |   [mw]
		 //                         mva
		 //
		 vertex mva = G[mv][mvi].first;
		 fout << "Aresta minimal : " << mv << "(" << mvi << ") - " << mva;
		 fout << " [" << mw << "]" << endl;
		// Inici de nou arbre amb mv i mva	
		 Pp[mv] = mv;
		 Pp[mva] = mv;
//    Actualitza PT i Pw
		 Tw += mw;
		 do {
			 //   Cerca d'aresta minimal que surti 'fora' de l'arbre
			 //          v ------ G[v][i].first
			 //        arbre        no arbre
			 //
			 mw = infty;
			 for (vertex v = 0; v < vn; v++)
				 if (Pp[v] < vn)   // v de l'arbre
					 for (index i = 0; i < G[v].size(); i++)
						 if (mw > G[v][i].second  && Pp[G[v][i].first]==vn ) {
							 mw = G[v][i].second;
							 mv = v;
							 mvi = i;
						 }
			 if (mw == infty)
				 break;
			 //       mv (mvi) ------ mva = G[mv][mvi].first  [mw]
			 //
			 //           ____ mv (arbre) -----  mva (no arbre)
			 //           ARBRE
			 //
			 vertex mva = G[mv][mvi].first;
			 fout << "Aresta minimal : " << mv << "(" << mvi << ") - " << mva;
			 fout << " [" << mw << "]" << endl;
		 // Continuació d'arbre amb mva
			 Pp[mva] = mv;

	//    Actualitza PT i Pw

			 Tw += mw;

		 } while (true);
		 Tn++;
	 } while (true);
 //  Escriu a fout: 
 //  - els vèrtexs que conformen cada component
 //  - arestes que conformen l'arbre minimal de cada component
 //  - el pes de l'arbre minimal en aquesta component
 //  
	 return Tw;
 }