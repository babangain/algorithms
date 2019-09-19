// Author - Yash Deshpande
// (yvdyash)
// Dijkstra copied from https://raw.githubusercontent.com/matthewsamuel95/ACM-ICPC-Algorithms/master/Graph/DijkstrasSPT/Dihkstras-using-STL.cpp
#include<bits/stdc++.h>
using namespace std;
#define  int long
vector<vector<pair<int,double > > > g(100005);
//vector<bool> vis(100005);
vector<double > dist(100005,LLONG_MAX);

void shortestpath(int src)
{
    set<pair<long long,int > > s;
    s.insert({0,src});
    dist[src]=0;
    while(!s.empty())
    {
        pair<long long,int> cur_node=*(s.begin());
        s.erase(s.begin());
        int parent=cur_node.second;
        for(int i=0;i<g[parent].size();i++)
        {
            int child=g[parent][i].first;
            double weight=g[parent][i].second;
            if(dist[child]>dist[parent]+weight)
            {
                if(dist[child]!=LLONG_MAX)
                    s.erase(s.find({dist[child],child}));

                dist[child]=dist[parent]+weight;
                s.insert({dist[child],child});
            }
        }
    }
}

int32_t main()
{
    int tc;cin>>tc;
    while(tc--){
        int n,e,src,dest;
        cin>>n>>e>>src>>dest;
        for(int i=0;i<=n;i++){
            g[i].clear();
            dist[i]=LLONG_MAX;
        }

        while(e--)
        {
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            g[a].push_back({b,c/(double )d});
            g[b].push_back({a,c/(double)d});
        }
        shortestpath(src);
        if(dist[dest] < LLONG_MAX)
            cout<<fixed<<setprecision(8)<<dist[dest];
        else
            cout<<-1;
        cout<<"\n";
    }
}
