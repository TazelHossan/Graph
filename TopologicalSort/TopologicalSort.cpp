///===============================================
/// Lab-7:
/// Problem-1:A C++ Program To Print Topological
/// Sorting Of A DAG(Directed Acyclic Graph)
///===============================================
/// ROLL: 1921
/// NAME: Md. Tazel Hossan
///===============================================
#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<stack>
#define WHITE -1
#define GRAY -2
int vertices;
using namespace std;

void topologicalSort(int v, int visited[], stack<int> &Stack,
                     vector<list<int>>adjacencyList)
{

    visited[v] = GRAY;

    list<int>::iterator itr;
    for (itr = adjacencyList[v].begin(); itr != adjacencyList[v].end(); itr++)
    {
        if (!visited[*itr])
        {
            topologicalSort(*itr, visited, Stack,adjacencyList);
        }
    }
    Stack.push(v);
}


void DFS(vector< list<int> > adjacencyList)
{


    /// Mark all the vertices , not visited
    int visited[vertices] ;
    for(int i = 0; i <= vertices; i++)
    {
        visited[i] = WHITE; /// Mark all the vertices as not visited
    }
    stack<int> Stack; ///create a stack

    for (int i = 0; i <= vertices; i++)
    {
        if (visited[i] == WHITE)
        {
            topologicalSort(i, visited, Stack, adjacencyList);
        }
    }




    while (!Stack.empty())
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}


int main()
{
    int  edges, v1, v2,flag[80];
    cout<<"\n Enter The Number Of Vertices::";
    cin>>vertices;

    cout<<"\n Enter The Number Of Edges::";
    cin>>edges;
    /// Adjacency List is a vector of lists.
    vector< list<int> > adjacencyList(vertices + 1);
    list<int>::iterator itr;

    cout<<"\n Enter The Edges(V1 -> V2)::\n";



    for (int i = 0; i < edges; i++)
    {
        cin>>v1>>v2;

        /// Adding Edges on a directed graph
        adjacencyList[v1].push_back(v2);
        flag[v1]=1;
        flag[v2]=1;
        //adjacencyList[v2].push_back(v1);
    }

    cout<<"\n The Adjacency List Is::\n";
    cout<<"===============================================\n\n";

    for (int i = 0; i < adjacencyList.size(); i++)
    {
        if(flag[i]==1)
        {
            cout<<" List["<<i<< "]";
            for(itr=adjacencyList[i].begin(); itr!=adjacencyList[i].end(); itr++)
            {
                cout<<" -> "<< *itr;
            }
            cout<<endl;
        }

    }

    cout<<"===============================================\n";
    cout << " Topological Sort Of The Given Graph:: \n";
    cout<<"===============================================\n";
    DFS(adjacencyList);
    cout<<"\n===============================================\n";
    return 0;
}
