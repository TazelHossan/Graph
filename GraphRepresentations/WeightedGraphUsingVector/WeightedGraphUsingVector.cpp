#include<bits/stdc++.h>
using namespace std;
int main()
{
    fstream file ;                     /// create a file object

    int v, e,v1,v2, w ;               /// v = #vertices ,e=#edges
                                     /// vertex v1 ,vertx v2 and weight between them w

    file.open("sample.txt");       /// open the txt file

    file>>v;                     /// read the given #vertices from file
    cout<<v<<endl;

    file>>e ;                 /// read the given #edges from file
    cout<<e<<endl;

    vector< pair<int, int> > G[v]; /// create a weighted graph using #2D vector
                                  /// and using a pair<> for inserting
                                 /// weight between two vertices v1 and v2

    vector< pair<int, int> >::iterator itr ; /// create an iterator of type G[v]

    for( int i =0 ; i < e ; i++ )          /// loop run till #edges(e)
    {
        file>>v1>>v2>>w ;                 /// read two vertices v1 ,v2 and weight w from file

        G[v1].push_back(make_pair(v2, w));     ///using make_pair() for inserting vertex and weight
        ///G[v2].push_back(make_pair(v1, w)); ///for undirected graph

    }

    cout<<"\nAdjacency List Of An Underected Weighted Graph G::  "<<endl;
    cout<<"===================================================== "<<endl;

    for(int i = 0; i<v; i++)                                ///outer loop run till #verices(v)
    {
        cout <<"node ("<< i << ") connected with :"<<endl;

        for(itr = G[i].begin(); itr != G[i].end(); itr++)///inner loop run till
                                                        ///the size of each row of graph G[]
        {
            cout << itr->first <<" and weight is = "<<itr->second<<endl;///as itr is a pointer
                                                                       ///so, print two values of pair<> by using aro sign(->)
                                                                      /// here,first and second are two build in objects of pair<>
        }
        cout << endl;
    }
    file.close();                                                  ///close the txt file


    return 0;
}
