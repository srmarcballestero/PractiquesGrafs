#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
 using namespace std;
// 
//  Complete graph to adjacency matrix
//
 vector<vector<int>>
    graphM_complete( int n )
 {    
//  Initialize adjacency matrix	to 0
    vector<vector<int>> KnM( n, vector<int>( n, 0 ) );
//  Fill adjacency matrix taking into account all the possible edges i-k
    for( int i=0; i<n; i++ ) 
		for (int k = i+1; k<n; k++)
			KnM[i][k] = KnM[k][i]=1;
    return KnM;
}
// 
//  Read SIMPLE graph from file fname of edges to adjacency matrix
//
//  IMPORTANT: This function should be adapted to multigraphs
 vector<vector<int>>
    graphM_read( string fname )
 {    
	ifstream fin;
    fin.open( fname.c_str() );    
    if( fin.fail() ) {
        cerr << "unable to open file " << fname.c_str() << " for reading" << endl;
        exit( 1 );
    }
 // Read vertices and edges numbers
	int n, m;
	fin >> n >> m;
 // Initialize adjacency matrix	to 0
    vector<vector<int>> M( n, vector<int> (n, 0) );
 // Fill adjacency matrix taking into account all the edges u-v
    for( int j=0; j<m; j++ ) {
         int u, v;
         fin >> u >> v;
		 M[u][v] = M[v][u] = 1;
    }    
    return M;
}
// 
//  Write SIMPLE graph from adjacency matrix to file stream
//  - vertices and edges numbers
//  - adjacency matrix
//  - edges
//  - sorted degrees
//
//  IMPORTANT: This function has a bug that must be corrected
//  IMPORTANT: This function should be adapted to multigraphs
  void 
	graphM_write( vector<vector<int>>& M, ofstream& fout )
 {    
//  Vertices number 
	int n = M.size();
//  Count edges number from adajacency matrix
    int m = 0; 
    for( int i = 0; i < n; i++ ) 
        for( int k = 0; k <= i; k++ ) 
            m = m + M[i][k];
//  Write vertices and edges numbers
    fout << "Graph with " << n << " vertices and " << m << " edges " << endl;
//  Write adjacency matrix
    fout << "Adjacency matrix" << endl;
    for( int i=0; i<n; i++ )  {
        for( int k=0; k<n; k++ ) 
            fout << "\t" << M[i][k];
        fout << endl;
    }
//  Write edges         
	fout << "Edges" << endl;
    for( int i = 0; i < n; i++ ) 
        for( int k = i+1; k < n; k++ ) 
             fout << i << " " << k << endl;
    fout << endl;
}
//
//	Main program:
//  - read graph in file graph0.in and construct graph K10
//  - write to graph0.out and K10.out
 int 
	main()
{
    ofstream fout;
//  graph0.in
	fout.open("graph0.out");
    vector<vector<int>> M0 = graphM_read( "graph0.in" );
    graphM_write( M0, fout );
	fout.close();
//  K8
	fout.open("K10.out");
    vector<vector<int>> MK10 = graphM_complete( 10 );
    graphM_write( MK10, fout );
    fout.close();
//  Finish
	cout << endl << "Press enter to finish... ";
    cin.get();
}
