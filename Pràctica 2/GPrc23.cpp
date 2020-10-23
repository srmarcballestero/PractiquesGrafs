#include <ctime>
#include "graph.h"
#include "wgraph.h"

 int 
	main()
{
    ofstream fout;
//  Seed rand()
    srand( (unsigned int) time( NULL ) ) ;
//  Complete graph K10 to adjacencies lists
	fout.open( "K10.out" );    
    graph K10 = graph_complete( 10 );
	graph_write( K10, fout );
    fout  << "\nNumber of DFS components: "  << DFS( K10 )  << endl;
    fout  << "\nNumber of BFS components: "  << BFS( K10 )  << endl;
    Dijkstra( K10, 0, fout );
	fout.close();
//  Read graph from graph0.in to adjacencies lists G0
	fout.open( "graph0.out" );    
    graph G0 = graph_read( "graph0.in" );
	graph_write( G0, fout );
    fout  << "\nNumber of DFS components: "  << DFS( G0 )  << endl;
    fout  << "\nNumber of BFS components: "  << BFS( G0 )  << endl;
    Dijkstra( G0, 0, fout );
	fout.close();
//  Random weighted complete graph WK10 with weights 1-10 to weighted adjacencies lists 
	fout.open( "WK10.out" );    
    wgraph WK10 = wgraph_complete( 10, 9 );
	wgraph_write( WK10, fout );
	fout.close();
//  Read weighted graph from wgraph0.in to weighted adjacencies lists WG0
	fout.open( "wgraph0.out");    
    wgraph WG0 = wgraph_read( "wgraph0.in" );
	wgraph_write( WG0, fout );
	fout.close();
//
//  Ending
//
    cout << "Press enter to finish..." << endl;
    cin.get();
}
