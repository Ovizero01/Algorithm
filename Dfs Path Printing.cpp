#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int> adj_list[1005];
bool vis[1005];
int parent[1005];
void dfs(int src)
{
    vis[src] = true;
    for(int child : adj_list[src]){
        if(!vis[child]){
            parent[child] = src;
            dfs(child);
        }
    }
}
int main() 
{
    int n, e; cin>>n>>e;
    while(e--){
        int a,b; cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    memset(parent,-1,sizeof(parent));
    int src, dst; cin>>src>>dst;
    dfs(src);
    int node = dst;
    vector<int>path;
    while(node != -1){
        path.push_back(node);
        node = parent[node];
    }
    reverse(path.begin(), path.end());
    for(auto x : path)
        cout<<x<<" ";
}
