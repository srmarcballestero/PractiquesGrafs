#include "graph.hpp"
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
