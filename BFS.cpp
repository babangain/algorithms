#include<bits/stdc++.h>
#define  int long long
using namespace std;

vector<bool > visited;
vector<vector<int >> graph;
void add_edge(int a, int b)
{
    graph[a].push_back(b);
    graph[b].push_back(a);
}
vector<int> BFS(int startNode)
{
    vector<int> result;
    queue<int > q;
    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty())
    {
        // Visit all nodes adjacent to first node in queue;
        int front = q.front();
        q.pop();
        result.push_back(front);
        for(auto node : graph[front])
        {
            // Node contain address. *node for value
            if(!visited[node])
            {
                q.push(node);
                visited[node] = true;
            }
        }
    }
    return result;
}

int32_t main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nodes,edges;
        cin>>nodes>>edges;
        // Initialize visited to false
        visited.assign(nodes,false);
        // Initialize graph
        graph.assign(nodes, vector<int>());
        for(int x=0; x<edges; x++)
        {
            int a,b;
            cin>>a>>b;
            add_edge(a,b);
        }
        /* For connected graph
        vector<int> result = BFS(0);
        for(int i=0; i< nodes; i++)
        {
            cout<<result[i];
        }
         */

        /*For disconnected graph */

        for(int i=0; i< nodes; i++)
        {
            if(visited[i] == false)
            {
                vector<int> result = BFS(i);
                for(int i=0; i< result.size(); i++)
                {
                    cout<<result[i];
                }
            }
        }

    }

}
