#include "graph.h"
// 
//  Complete graph with vn vertices to adjacencies lists (graph)
//
 graph
    graph_complete( index n )
{    
    vertex vn = n;
    graph Kn( vn );
    for( vertex v=0; v<vn; v++) 
        for( vertex u=v+1; u<vn; u++ ) {
             Kn[v].push_back( u );
             Kn[u].push_back( v );
        } 
    return Kn;
}

 //   0  :  1  2  3
 //   1  :  0  2  3 
 //   2  :  0  1  3
 //   3  :  0  1  2

// 
//  Cycle graph with vn vertices to adjacencies lists (graph)0
//
 graph
     graph_cycle(index n)
 {
     vertex vn = n;
     graph Cn(vn);
     for (vertex v = 0; v < n-1; v++){
          Cn[v].push_back(v+1);
          Cn[v+1].push_back(v);
     }
     Cn[n-1].push_back(0);
     Cn[0].push_back(n-1);
     return Cn;
 }

 // 
 //  Star graph with vn vertices to adjacencies lists (graph)0
 //
 graph
     graph_star(index n)
 {
     vertex vn = n+1;
     graph Sn(vn);
     for (vertex v = 0; v < n; v++) {
         //  v-n
         Sn[v].push_back(n);
         Sn[n].push_back(v);
     }
     return Sn;
 }

 // 
 //  Wheel graph with vn vertices to adjacencies lists (graph)0
 //
 graph
     graph_wheel(index n)
 {
     vertex vn = n + 1;
     graph Wn(vn);
     for (vertex v = 0; v < n - 1; v++) {   
         Wn[v].push_back(v + 1);
         Wn[v + 1].push_back(v);
     }
     Wn[n - 1].push_back(0);
     Wn[0].push_back(n - 1);
     for (vertex v = 0; v < n; v++) {
         //  v-n
         Wn[v].push_back(n);
         Wn[n].push_back(v);
     }
     return Wn;
 }

 //  COMPLETAR

 //  graph_bipartite_complete

// 
//  King graph in n1xn2 chessboard: Kgn1n2
//
 graph
     graph_king(index n1, index n2)
 {
     graph Kgn1n2(n1 * n2);
     for (index i1 = 0; i1 < n1; i1++)
         for (index i2 = 0; i2 < n2; i2++) {
             vertex v = i1 * n2 + i2;
             if (i2 < n2 - 1) {
                 Kgn1n2[v].push_back(v + 1);
                 Kgn1n2[v + 1].push_back(v);
             }
             if (i1 < n1 - 1) {
                 Kgn1n2[v].push_back(v + n2);
                 Kgn1n2[v + n2].push_back(v);
             }

             //                  v   v+1
             //          v+n2-1 v+n2 v+n2+1   
            
             if (i1 < n1 - 1 && i2 < n2 - 1) {
                 Kgn1n2[v].push_back(v + n2 + 1);
                 Kgn1n2[v + n2 + 1].push_back(v);
             }
             if (i1 < n1 - 1 && i2>0) {
                 Kgn1n2[v].push_back(v + n2 - 1);
                 Kgn1n2[v + n2 - 1].push_back(v);
             }
         }
     return Kgn1n2;
 }


 // 
 //  Knight graph in n1xn2 chessboard: Ktn1n2
 //
 graph
     graph_knight(index n1, index n2)
 {
     graph Ktn1n2(n1 * n2);
     for (index i1 = 0; i1 < n1; i1++)
         for (index i2 = 0; i2 < n2; i2++) {
             vertex v = i1 * n2 + i2;
             if (i1<n1-1 && i2 < n2 -2) {
                 Ktn1n2[v].push_back(v +n2 + 2);
                 Ktn1n2[v +n2+2].push_back(v);
             }
             if (i1 < n1 - 1 && i2>1 ) {
                 Ktn1n2[v].push_back(v + n2-2);
                 Ktn1n2[v + n2-2].push_back(v);
             }

             //                        v   
             //        v+n2-2                      v+n2+2
             //               v+2n2-1     v+2n2+1
             //
             if (i1 < n1 - 2 && i2 < n2 - 1) {
                 Ktn1n2[v].push_back(v + 2*n2 + 1);
                 Ktn1n2[v + 2*n2 + 1].push_back(v);
             }
             if (i1 < n1 - 2 && i2>0) {
                 Ktn1n2[v].push_back(v + 2*n2 - 1);
                 Ktn1n2[v + 2*n2 - 1 ].push_back(v);
             }
         }
     return Ktn1n2;
 }


 // 
//  Bishop graph in n1xn2 chessboard: Bpn1n2
//
 graph
     graph_bishop(index n1, index n2)
 {
     graph Bpn1n2(n1 * n2);
     for (index i1 = 0; i1 < n1; i1++)
         for (index i2 = 0; i2 < n2; i2++) {
             vertex v = i1 * n2 + i2;
             //
             //                  v   
             //           v+n2-1    v+n2+1
             //
             //       v+kn2-k            v+kn2+k
             //
             for (index k = 1; i1 + k < n1 && i2 + k < n2; k++) {
                 Bpn1n2[v].push_back(v + k * n2 + k);
                 Bpn1n2[v + k * n2 + k].push_back(v);
             }
             for (index k = 1; i1 + k < n1 && i2>=k; k++) {
                 Bpn1n2[v].push_back(v + k * n2 - k);
                 Bpn1n2[v + k * n2 - k].push_back(v);
             }
                
         }
     return Bpn1n2;
 }


 //  COMPLETEU EL QUE FALTA I 'USEU-LOS' EN LA FUNCIÓ main
 //  Manca graph_rook.
 

// 
//  Read from file fname of edges to adjacencies lists (graph)
//
 graph 
	graph_read( string fname )
{    
	ifstream fin;
    fin.open( fname.c_str() );    
    if( fin.fail() ) {
        cerr << "unable to open file " << fname.c_str() << " for reading" << endl;
        exit( 1 );
    }
 	vertex vn;
    edge en;
	fin >> vn >> en;
	graph G( vn );
    for( edge e=0; e<en; e++ ) {
         vertex v, u;
         fin >> v >> u; 
         G[v].push_back(u);
         if( u != v ) 
             G[u].push_back(v);
	}    
    return G;
}
// 
//  Write from adjacencies lists (graph) to stream
//  - vertices and edges numbers
//  - edges
  void 
	graph_write(  graph& G, ofstream& fout )
{    
//  Vertices number 
	vertex vn = G.size();
//  Count edges number from adjacencies lists
//  PLEASE CORRECT WHEN THERE ARE LOOPS
    edge en = 0; 
    for( vertex v = 0; v < vn; v++ ) 
         en += G[v].size();
    en /= 2;
//  Write edges         
    fout << "Graph with " << vn << " vertices and " << en << " edges " << endl;
    fout << "Adjacencies lists" << endl;
    for( vertex v=0; v<vn; v++ )  {
		fout << v << "\t:";
        for( index i=0; i<G[v].size(); i++) 
            fout << "\t" << G[v][i];
        fout << endl;
    }
    fout << "Edges" << endl;
    for( vertex v = 0; v < vn; v++ ) 
        for( index i = 0; i < G[v].size(); i++ ) 
            if( v <= G[v][i] )
                fout << v << "-" << G[v][i] << endl;
}
  //
  //     v     (i1,i2)  :   v = i1 n2 + i2   (v/n2, v%i2)
  //    (0,0)  (0,1)      (0,i2)              (0,n2-1)
  //    (1,0)
  //
  //    (i1,0)            (i1,i2)
  //
  void
      chess_graph_write(graph& G, index n1, index n2, ofstream& fout)
  {
     //  Vertices number 
     vertex vn = G.size();
     //  Count edges number from adjacencies lists
     //  PLEASE CORRECT WHEN THERE ARE LOOPS
     edge en = 0;
     for (vertex v = 0; v < vn; v++)
         en += G[v].size();
     en /= 2;
     //  Write edges         
     fout << "Graph with " << vn << " vertices and " << en << " edges " << endl;
     fout << "Adjacencies lists" << endl;
     for (vertex v = 0; v < vn; v++) {
         fout << "(" << v/n2 << ", " << v%n2 << ")" << "\t:";
         for (index i = 0; i < G[v].size(); i++)
             fout << "\t" << "(" << G[v][i]/ n2 << ", " << G[v][i] % n2 << ")" ;
         fout << endl;
     }
//   RETOQUEU-HO ESCRIVINT LES ARESTES EN FORMAT CASELLES... 

        fout << "Edges" << endl;
     for (vertex v = 0; v < vn; v++)
         for (index i = 0; i < G[v].size(); i++)
             if (v <= G[v][i])
                 fout << v << "-" << G[v][i] << endl;

////////////////////////////////////////

     fout << "Degrees matrix" << endl;
     for (index i1 = 0; i1 < n1; i1++) {
         for (index i2 = 0; i2 < n2; i2++)
             fout << G[i1 * n2 + i2].size() << "\t";
         fout << endl;
     }


 }
