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
    fout  << "\nNumber of DFS components: "  << DFS_Trees( K10, fout )  << endl;
    fout  << "\nNumber of BFS components: "  << BFS( K10 )  << endl;
    Dijkstra( K10, 0, fout );
	fout.close();
//  Cycle graph C10 to adjacencies lists
    fout.open("C10.out");
    graph C10 = graph_cycle(10);
    graph_write(C10, fout);
    fout << "\nNumber of DFS components: " << DFS(C10) << endl;
    fout << "\nNumber of BFS components: " << BFS(C10) << endl;
    Dijkstra(C10, 0, fout);
    fout.close();
 // Star graph S10 to adjacencies lists
    fout.open("S10.out");
    graph S10 = graph_star(10);
    graph_write(S10, fout);
    fout << "\nNumber of DFS components: " << DFS(S10) << endl;
    fout << "\nNumber of BFS components: " << BFS(S10) << endl;
    Dijkstra(S10, 0, fout);
    fout.close();
 // Wheel graph W10 to adjacencies lists
    fout.open("W10.out");
    graph W10 = graph_wheel(10);
    graph_write(W10, fout);
    fout << "\nNumber of DFS components: " << DFS(W10) << endl;
    fout << "\nNumber of BFS components: " << BFS(W10) << endl;
    Dijkstra(W10, 0, fout);
    fout.close();
    //  COMPLETAR AMB K6,4  K4,6



//  Read graph from graph0.in to adjacencies lists G0
	fout.open( "graph0.out" );    
    graph G0 = graph_read( "graph0.in" );
	graph_write( G0, fout );
    fout  << "\nNumber of DFS components: "  << DFS( G0 )  << endl;
    fout  << "\nNumber of BFS components: "  << BFS( G0 )  << endl;
    Dijkstra( G0, 0, fout );
	fout.close();
  //  Read graph from graph1.in to adjacencies lists G1
    fout.open("graph1.out");
    graph G1 = graph_read("graph1.in");
    graph_write(G1, fout);
    fout << "\nNumber of DFS components: " << DFS(G1) << endl;
    fout << "\nNumber of BFS components: " << BFS(G1) << endl;
    Dijkstra(G1, 0, fout);
    fout.close();
//  COMPLETAR AMB graph2.in graph3.in




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
