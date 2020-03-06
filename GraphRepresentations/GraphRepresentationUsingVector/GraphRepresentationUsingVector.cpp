#include<bits/stdc++.h>
using namespace std;
int main()
{
    fstream file ;                   /// create a file object

    int v, e,v1,v2, w ;            /// v = #vertices ,e=#edges
                                  /// vertex v1 ,vertx v2

    file.open("sample.txt");    /// a txt file open

    file>>v;                  /// read the given #vertices from file
    cout<<v<<endl;

    file>>e ;               /// read the given #edges from file
    cout<<e<<endl;

    vector<int> G[v] ;                 /// create a graph using 2D vector
    vector<int >::iterator itr ;      /// create a iterator of type 2D vector

    for( int i =0 ; i < e ; i++ )   /// loop run till #edges(e)
    {
        file>>v1>>v2 ;            /// read two vertices v1 ,v2 from file
        G[v1].push_back (v2) ;   /// insert the vertices v1 ,v2 from file to G[] graph
    }

    cout<<"\nAdjacency List Of The Graph G:: "<<endl;
    cout<<"================================= "<<endl;

    for(int i = 0; i<=v; i++)                               ///outer loop run till #verices(v)
    {
        cout << i << "--->";
        for(itr = G[i].begin(); itr != G[i].end(); itr++)///inner loop run till
                                                        ///the size of each row of graph G[]
        {
            cout << *itr << " ";                      ///as itr is a pointer
                                                     ///so print the value by using dereferencing(*)
        }
        cout << endl;
    }
    file.close();                                 ///close the txt file


    return 0;
}
