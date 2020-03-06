#include<bits/stdc++.h>

int vertices;
using namespace std;

void BreadthFirstSearch( vector< int > adjacencyList[], int source)
{
    bool visited[vertices] ;          /// check each vertex is visited or not ?
    for(int i = 0; i < vertices; i++)/// initialize the array 'visited' is not visited
    {
        visited[i] = false;        ///at first consider all of the vertices as not visited
    }


                               /// BFS need a queue for performing its oerations
    queue<int> q;             /// Create a queue for BFS

    visited[source] = true; /// now, Mark the source node is visited
    q.push(source);        /// and enqueue it(push into the queue)

                         /// 'itr' will be used to get all adjacent
                        /// vertices of a current vertex
    vector<int>::iterator itr;

    while(!q.empty())           /// loop run until empty of the queue
    {
                              /// Dequeue(delete) a vertex from the queue and print it
        int v = q.front();   /// front() is queue's funtion unlike stack, has top()
        cout << v << " ";
        q.pop();

        /// Get all adjacent vertices of the dequeued(deleted v vertex)
        /// If an adjacent of source has not been visited,
        /// then mark it visited and then enqueue it(push it onto the queue)

        for (itr=adjacencyList[v].begin(); itr!=adjacencyList[v].end(); itr++)
        {
            if (visited[*itr]==false)
            {
                visited[*itr] = true;
                q.push(*itr);
            }
        }
    }
}
///=============Start The Main Program Here===============

int main()
{
    int  edges, v1, v2;

    cout<<"\n Enter The Number Of Vertices::";
    cin>>vertices;

    cout<<"\n Enter The Number Of Edges::";
    cin>>edges;

    vector< int > adjacencyList[vertices];/// Adjacency List is a 2D vector.

    vector<int>::iterator itr;           ///create an iterator of type adjacencyList[]

    cout<<"\n Enter The Edges Like This( V1 -> V2 )::\n";

    for (int i = 0; i < edges; i++)    /// loop run till #edges(e)
    {
        cin>>v1>>v2;                 ///input an edge(v1,v2)
                                    /// The Graph is undirected
                                   /// that's why v1->v2 equivalent v2->v1

        adjacencyList[v1].push_back(v2);  /// Adding an Edge v1->v2
        adjacencyList[v2].push_back(v1); ///equivalently,Adding an Edge v2->v1
    }

    cout<<"\n The Adjacency List Of The Undirected unweighted Grap G::\n";
    cout<<"\n ========================================================\n";

    for (int i =0; i <vertices; i++)         ///outer loop run till #verices(v)
    {
        cout<<"adjacencyList["<<i<< "]";

        for(itr=adjacencyList[i].begin(); itr!=adjacencyList[i].end(); itr++)///inner loop run till
                                                                            ///the size of each row of graph G[]
        {
            cout<<" -> "<< *itr;         ///as itr is a pointer
                                        ///so, print the value of it, by using dereferencing(*)
        }
        cout<<endl;
    }

    int source;
    cout<< "\n Enter A Source Node::";
    cin>>source;

    BreadthFirstSearch(adjacencyList,source);  ///call the BFS



    return 0;
}
