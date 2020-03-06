#include<bits/stdc++.h>
int V; /// globally declared ,number of vertices

using namespace std;

void sortestPath(vector<pair<int,int>>adj[],int src)
{
    priority_queue< pair<int, int>,
                    vector< pair<int,int> >,
                    greater< pair<int,int> > > pq;

    /// Create a vector for distances and initialize all
    /// distances as infinite (INF)
    vector<int> dist(V, INT_MAX);

    /// Insert source itself in priority queue and initialize
    /// its distance as 0.
    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {
        /// The first vertex in pair is the minimum distance
        /// vertex, extract it from priority queue.
        /// vertex label is stored in second of pair (it
        /// has to be done this way to keep the vertices
        /// sorted distance (distance must be first item
        /// in pair)
        int u = pq.top().second;
        pq.pop();

        /// 'i' is used to get all adjacent vertices of a vertex
        vector< pair<int, int> >::iterator itr;
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++)
        {
            /// Get vertex label and weight of current adjacent
            /// of u.
            int v = (*itr).first;
            int weight = (*itr).second;

            ///  If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                /// Updating distance of v
                dist[v] = dist[u] + weight;

                pq.push(make_pair(dist[v], v));
            }
        }
    }
    cout<<"Sortest Distance from Source vertex(0) to:\n";
    for (int i = 0; i <= V; i++)
    {
        cout<<i<<"\t\t"<<dist[i]<<endl;
    }


}

///=============Start The Main Program Here===============
int main()
{
    int e, w,v1,v2;
    cin>>V>>e;

    vector< pair<int,int> >Graph[V+1];
    vector< pair<int,int> >::iterator itr;
    for(int i = 0 ; i<e ; i++)
    {
        cin>>v1>>v2>>w ;

        Graph[v1].push_back(make_pair(v2,w));

    }

    for(int i = 0 ; i<=V ; i++)
    {
        for(itr=Graph[i].begin(); itr!=Graph[i].end() ; itr++)
        {

            cout<<i<<"-->"<< itr->first<< " "<<itr->second<<endl ;
        }
        cout<<"=========================================="<<endl;

    }
    sortestPath(Graph,0);


    return 0;
}
