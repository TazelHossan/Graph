#include<bits/stdc++.h>
int vertices;                             ///#vertices is a global variable
using namespace std;

void DFS( vector<int>G[],int source)
{
    bool visited[vertices] ;          /// check each vertex is visited or not ?

    for(int i = 0; i < vertices; i++)/// initialize the array 'visited'
    {
        visited[i] = false;        ///at first,consider all of the vertices are not visited
    }



    /// Create a stack for DFS
    /// DFS need a stack for performing its oerations
    stack<int> stk;          /// Create a stack for DFS

    visited[source] = true; /// now, Mark the source node is visited
    stk.push(source);      /// and push it into the stack

                         ///now, 'itr' will be used to get all adjacent
                        /// vertices of a current vertex
    vector<int>::iterator itr;

    while (!stk.empty())
    {
        /// Pop a vertex(top element) from the stack and print it
        int  v = stk.top();
        cout << v << " ";
        stk.pop();


        /// Get all adjacent vertices of the popped vertex v
        /// If an adjacent has not been visited, then push it
        /// to the stack.
        for (itr = G[v].begin(); itr != G[v].end(); itr++)
        {

            if (visited[*itr]==false)
            {
                visited[*itr]=true;
                stk.push(*itr);
            }

        }
    }
}

///=============Start The Main Program Here===============
int main()
{
    int e,v1,v2 ;

    cout<< "\n Enter The Number of vertices:";
    cin>>vertices;

    cout<<"\n Enter The Number Of Edges:";
    cin>>e;

    vector<int>G[vertices];       /// create an Adjacency List.it is a 2D vector.
    vector<int>::iterator itr;   ///create an iterator of type adjacencyList[]

    cout<<"\n Enter The Edges Like This( V1 -> V2 )::\n";

    for(int i =0 ; i<e; i++)          /// loop run till #edges(e)
    {
        cin>>v1>>v2;                ///input an edge(v1,v2)
                                   /// The Graph is directed
                                  /// that's why only v1->v2 is added

        G[v1].push_back(v2);    /// Adding an Edge v1->v2
    }

    cout<<"\n The Adjacency List Of The directed unweighted Grap G::\n";
    cout<<"\n ========================================================\n";

    for(int i = 0; i<vertices; i++)                    ///outer loop run till #verices(v)
    {
        cout<<i<< "-->";
        for(itr=G[i].begin(); itr!=G[i].end(); itr++)///inner loop run till
                                                    ///the size of each row of graph G[]
        {
            cout<< *itr<<" " ;                    ///as itr is a pointer
                                                 ///so,print the value of it, by using dereferencing(*)
        }
        cout<<endl;
    }

    int source;
    cout<< "\n Enter A Source Node::";
    cin>>source;

    DFS(G,source);                         ///call the DFS

    return 0;
}
