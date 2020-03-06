///====================================================
/// Lab-7:
/// Problem-2:A C++ Program To Print All Paths Of A
/// Given Source To All Nodes In A Given Directed Graph
///====================================================
/// ROLL: 1921
/// NAME: Md. Tazel Hossan
///====================================================

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/// the found path in graph
void printpath(vector<int>& path)
{
    int size = path.size();
    for (int i = 0; i < size; i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;
}


int isNotVisited(int x, vector<int>& path)
{
    int size = path.size();
    for (int i = 0; i < size; i++)
        //{
        if (path[i] == x)
            //{
            return 0;
    //}

    //}
    return 1;
}

// utility function for finding paths in graph
// from source to destination
void FindAllPaths(vector< vector<int> > &g, int src,
                  int* dst, int v)
{
    /// create a queue which stores
    /// the paths
    queue<vector<int> > q;

    /// path vector to store the current path
    vector<int> path;
    path.push_back(src);
    q.push(path);
    while (!q.empty())
    {
        path = q.front();
        q.pop();
        int last = path[path.size() - 1];

        /// if last vertex is the desired destination
        /// then print the path
        for(int i = 0 ; i<=v; i++)
        {
            if (last == dst[i])
            {
                printpath(path);
            }
        }



        /// traverse to all the nodes connected to
        /// current vertex and push new path to queue
        for (int i = 0; i < g[last].size(); i++)
        {
            if (isNotVisited(g[last][i], path))
            {
                vector<int> newpath(path);
                newpath.push_back(g[last][i]);
                q.push(newpath);
            }
        }
    }
}

int main()
{
    int  vertices,edges, v1, v2,vertex[80];

    cout<<"\n Enter The Number Of Vertices::";
    cin>>vertices;
    cout<<"\n Store The Vertices::";
    for(int i = 0 ; i<vertices; i++)
    {
        cin>>vertex[i];
    }
    cout<<"\n Enter The Number Of Edges::";
    cin>>edges;

    /// Adjacency List is a vector of lists.
    vector<vector<int> >adjacencyList ;
    adjacencyList.resize(vertices);
    vector<int>::iterator itr;

    cout<<"\n Enter The Edges(V1 -> V2)::\n";
    for (int i = 0; i < edges; i++)
    {
        cin>>v1>>v2;

        /// Adding Edges on a undirected graph
        adjacencyList[v1].push_back(v2);
        //adjacencyList[v2].push_back(v1);
    }

    cout<<"\n The Adjacency List Is::\n";
    cout<<"===============================================\n\n";
    for (int i = 1; i < adjacencyList.size(); i++)
    {
        cout<<"List["<<i<< "]";
        for(itr=adjacencyList[i].begin(); itr!=adjacencyList[i].end(); itr++)
        {
            cout<<" -> "<< *itr;
        }
        cout<<endl;
    }

    int source;
    cout<< "\n Enter A Source Node::";
    cin>>source;
    cout<<"===============================================\n";
    cout << "\n All Paths From The Given Source "<<source<<"::"<<endl;
    cout<<"===============================================\n";

    /// function for finding the paths
    for (int i = 0; i <vertices; i++)
    {
        FindAllPaths(adjacencyList, source, vertex, vertices);

    }
    cout<<"\n===============================================\n";

    return 0;
}
