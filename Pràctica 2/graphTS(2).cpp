//
//	TREE SEARCH IN GRAPHS
//  - BFS method
//  - DFS method
//  - Dijkstra (without weights) method
//
#include "graph.h"
//
//  Breadth First Search: returns components/trees number
//
 component
    BFS( graph &G ) 
{
    vertex vn = G.size();
    component Tn = 0;
//  Vertices list
	vector<vertex> BFSv( vn );
//  Label vertices as unvisited
	vector<bool> BFSl( vn, false );
//  List index
	index BFSn = 0;
//  Find non labeled vertex as root vertex rv of new component/tree Tn
	for( vertex rv=0; rv<vn; rv++ ) 
		if( !BFSl[rv] ) {
		//  Actualize display index
			index BFSi = BFSn;
		//  New root rv found for new component
			Tn++;
		//  Label and list rv
			BFSl[rv] = true;
			BFSv[BFSn++] = rv;
			if( G[rv].size() )
			do {
			//  New vertex v to display 
				vertex v = BFSv[BFSi++]; 				
				for( index i=0; i<G[v].size(); i++ ) 
					if( !BFSl[G[v][i]] ) {
					//  Label and list adjacent G[v][i]
						BFSl[G[v][i]] = true;
						BFSv[BFSn++] = G[v][i];
					}
			} while( BFSi < BFSn );
		}
   return Tn;
}           
 //                         BFSi                         BFSn
 //  BFSv  0    1    4   5    2   6   3    9   10   14


 //             v
 //         ...   G[v][i]
//

 component
	 BFS_Trees(graph& G, ofstream& fout)
 {
	 vertex vn = G.size();
	 component Tn = 0;
	 //  Vertices list
	 vector<vertex> BFSv(vn);
	 //  Label vertices as unvisited
	 vector<index> BFSind(vn);
	 vector<vertex> BFSp(vn, vn);
	 vector<length> BFSd(vn);
	 //  List index
	 index BFSn = 0;
	 //  Find non labeled vertex as root vertex rv of new component/tree Tn
	 for (vertex rv = 0; rv < vn; rv++)
		 if (BFSp[rv]==vn) {
			 //  Actualize display index
			 index BFSi = BFSn;
			 //  New root rv found for new component
			 Tn++;
			 //  Label and list rv
			 BFSind[rv] = BFSn;
			 BFSp[rv] = rv;
			 BFSd[rv] = 0;
			 BFSv[BFSn++] = rv;
			 if (G[rv].size())
				 do {
					 //  New vertex v to display 
					 vertex v = BFSv[BFSi++];
					 for (index i = 0; i < G[v].size(); i++)
						 if (BFSp[G[v][i]]==vn) {
							 //  Label and list adjacent G[v][i]
							 BFSind[G[v][i]] = BFSn;
							 BFSp[G[v][i]] = v;
							 BFSd[G[v][i]] = BFSd[v] + 1;
							 BFSv[BFSn++] = G[v][i];
						 }
				 } while (BFSi < BFSn);
		 }
	 // ESCRIURE INFORMACIÓ A fout
	 //        v     BFSind[v]   BFSp[v]    BFSd[v]    ....
	 //      v-G[v][i]  Arbre o no?



	 return Tn;
 }
//
//  Recursive function for Depth First Search from v
//
 void 
    DFS( graph &G, vector<bool> &DFSl,  vertex v ) 
{
	for( index i=0; i<G[v].size(); i++ ) 
        if( !DFSl[G[v][i]] ) {
		//  Label adjacent vertex as visited
            DFSl[G[v][i]] = true;
		//  DFS recursive for non visited adjacent vertices   
            DFS( G, DFSl, G[v][i] );
        }
}
//
//  Depth First Search: returns components/trees number
//
 component 
    DFS(  graph &G ) 
{
    vertex vn = G.size();
//  Initialize number of components/trees to 0
    component Tn = 0;
//  Label vertices as unvisited
    vector<bool> DFSl( vn, false );
    for( vertex rv=0; rv<vn; rv++) 
         if( !DFSl[rv] ){
		 //  New root found
		 //  Count new component
			 Tn++;
		 //  Label root vertex
			 DFSl[rv] = true;
		 //  Display component
             DFS( G, DFSl, rv );
         }
    return Tn;
}

 //
 //  Recursive function for Depth First Search from v
 //
 void
	 DFS_Trees(graph& G, index& DFSn, vector<index>& DFSind, vector<vertex>& DFSp,
		 vector<length>&DFSd, vertex v)
 {
	 vertex vn = G.size();
	 for (index i = 0; i < G[v].size(); i++)
		 if (DFSp[G[v][i]]==vn) {
			 //  Label adjacent vertex as visited
			 DFSp[G[v][i]] = v;
			 DFSind[G[v][i]] = DFSn++;
			 DFSd[G[v][i]] = DFSd[v]+1;
			 //  DFS recursive for non visited adjacent vertices   
			 DFS_Trees(G, DFSn, DFSind, DFSp, DFSd, G[v][i]);
		 }
 }
 //
 //  Depth First Search: returns components/trees number
 //
 component
	 DFS_Trees(graph& G, ofstream& fout)
 {
	 vertex vn = G.size();
	 //  Initialize number of components/trees to 0
	 component Tn = 0;
	 //  Label vertices as unvisited
	 vector<vertex> DFSp(vn, vn);
	 vector<index> DFSind(vn);
	 vector<length> DFSd(vn);
	 index DFSn = 0;
	 for (vertex rv = 0; rv < vn; rv++)
		 if (DFSp[rv]==vn) {
			 //  New root found
			 //  Count new component
			 Tn++;
			 //  Label root vertex
			 DFSp[rv] = rv;
			 DFSind[rv] = DFSn++;
			 DFSd[rv] = 0;
			 //  Display component
			 DFS_Trees(G, DFSn, DFSind, DFSp,DFSd,rv);
		 }

	 // ESCRIVIU A fout INFORMACIÓ ANÀLOGA A BFS_Trees

	 return Tn;
 }

 // CANVIEU LES CRIDES A LA FUNCIÓ main  DE BFS, DFS  A  BFS_Trees i DFS_Trees i repasseu resultats.





//
//  Minimal path lengths by Dijkstra's method to stream
//  - Distances to all vertices: lengths of minimal paths
//
 void
    Dijkstra(  graph &G,  vertex sv, ofstream& fout ) 
{
    vertex vn = G.size();
//  Inialize vertices as unlabeled
    vector<bool> Dl( vn, false );
//  Infinity for lengths
	length infty = UINT_MAX;
//  Inialitize distance to sv to infty for all vertices but sv
	vector<length> Dd( vn, infty );
	Dd[sv]=0;
//  Vertex mdv with minimum distance to starting vertex sv: sv
	vertex mdv = sv; 
	do {
	//  Label mdv and check distance from sv to its adjacents	
		Dl[mdv] = true;
		for( index i=0; i<G[mdv].size(); i++ ) 
			if( Dd[G[mdv][i]] > Dd[mdv]+1 )	
				Dd[G[mdv][i]] = Dd[mdv]+1; 
	//  Find new not labeled vertex mdv with minimum distance to sv
		length md = infty;
		mdv = vn;
		for( vertex v=0; v<vn; v++ )
			if( md > Dd[v] && !Dl[v] ) {
				md = Dd[v];
				mdv = v;
			}
	} while( mdv<vn );
    fout << "\nDistances from starting vertex " << sv << endl;
	for( vertex v=0; v<vn; v++ )
        if( Dd[v]<infty )
		    fout << v << "\t" << Dd[v]  << endl;
        else
            fout << v << "\tNot connected" << endl;
}