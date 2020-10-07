#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
 using namespace std;
//
//  Complete graph to adjacency matrix
//
 vector<vector<int> >
    graphM_complete( int n )
 {
//  Initialize adjacency matrix	to 0
    vector<vector<int> > KnM( n, vector<int>( n, 0 ) );
//  Fill adjacency matrix taking into account all the possible edges i-k
    for( int i=0; i<n; i++ )
		for (int k = i+1; k<n; k++)
			KnM[i][k] = KnM[k][i]=1;
    return KnM;
}
 //
//  Cycle graph to adjacency matrix
//
 vector<vector<int> >
	 graphM_cycle(int n)
 {
	 //  Initialize adjacency matrix	to 0
	 vector<vector<int> > CnM(n, vector<int>(n, 0));
	 //  Fill adjacency matrix taking into account all the possible edges i-k
	 for (int i = 0; i < n-1; i++)
		 CnM[i][i+1] = CnM[i+1][i] = 1;
	 CnM[n - 1][0] = CnM[0][n - 1] = 1;
	 return CnM;
 }
//
//   COMPLETEU-HO AMB ELS ALTRES GRAFS:
//   cycle( int n ) n
//   bipartite_complete( int n1, int n2)  K_n1_n2
//   star  S_n (int n)  (n+1 vertexs!!)
//   wheel W_n (int n) (n+1 vertexs!!)
//   ...
//
//  Read SIMPLE graph from file fname of edges to adjacency matrix
//
//  IMPORTANT: This function should be adapted to multigraphs
 vector<vector<int> >
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
    vector<vector<int> > M( n, vector<int> (n, 0) );
 // Fill adjacency matrix taking into account all the edges u-v
    for( int j=0; j<m; j++ ) {
         int u, v;
         fin >> u >> v;
	//  NOM�S V�LID PER A GRAFS. NO PER A MULTIGRAFS.
	//  CORRECCI� PER A MULTIGRAFS: ALERTA QUE ELS LLA�OS COMPTEN DOBLE!!
		 M[u][v]++; M[v][u]++;
    //
    }
    return M;
}
//
//  Write SIMPLE graph from adjacency matrix to file stream
//  - vertices and edges numbers
//  - adjacency matrix
//  - edges
//
//  IMPORTANT: This function has a bug that must be corrected
//  IMPORTANT: This function should be adapted to multigraphs
  void
	graphM_write( vector<vector<int> >& M, ofstream& fout )
 {
//  Vertices number
	int n = M.size();
//  Count edges number from adajacency matrix
//  CORREGIR QUAN HI HA LLA�OS
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


//  REPETIU ARESTES M�LTIPLES I ESCRIVIU LLA�OS CORRECTAMENT
//  CORREGIR...
	fout << "Edges" << endl;
    for( int i = 0; i < n; i++ )
        for( int k = i+1; k < n; k++ )
							//  ESCRIVIA TOTES LES ARESTES DEL GRAF COMPLET!!!
			if( M[i][k] )  // AIX� NOM�S ESCRIU LES DEL GRAF...
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
    vector<vector<int> > M0 = graphM_read( "graph0.in" );
    graphM_write( M0, fout );
	fout.close();
//  graph1.in
	fout.open("graph1.out");
	vector<vector<int> > M1 = graphM_read("graph1.in");
	graphM_write(M1, fout);
	fout.close();

//  K10
	fout.open("K10.out");
    vector<vector<int> > MK10 = graphM_complete( 10 );
    graphM_write( MK10, fout );
    fout.close();
//  C10
	fout.open("C10.out");
	vector<vector<int> > MC10 = graphM_cycle(10);
	graphM_write(MC10, fout);
	fout.close();
//   COMPLETEU-HO AMB ELS ALTRES GRAFS:
//   K6_4 K4_6, S10, W10, ...
//



//  Finish
	cout << endl << "Press enter to finish... ";
    cin.get();
}
