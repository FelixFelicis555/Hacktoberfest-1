/*
    This problem can be reduced to finding the articulation points(cut vertices) in a graph.
    We can calculate all articulation points using a single dfs.
*/
#include<bits/stdc++.h>
 
using namespace std;
 
#define vi vector<int>
#define vvi vector<vi>
 
vvi adj;//adjacency list representation of matrix
set<int> ans;//to store the answers
vi low,tin;
const int infI = 1e9;
int tt=0;
 
void dfs(int u,int p){
    tin[u] = tt++;
    low[u] = tin[u];
    for(auto x:adj[u]){
        if(x == p){//we came from this vertex, therefore we skip it.
            continue;
        }
        if(tin[x]!=-1){//we have already visited this vertex.
            low[u] = min(low[u],low[x]);
        }
        else{
            dfs(x,u);
            low[u] = min(low[u],low[x]);
            if(low[x]>tin[u]){// the edge x-u is a bridge, therefore x and u are critical planets.
                ans.insert(x);
                ans.insert(u);
            }
        }
    }
}
 
int main(){
    int m,n;
    cin>>m>>n;
    adj.resize(n+1);
    low.resize(n+1,infI);
    tin.resize(n+1,-1);
    for(int i= 0;i<m;i++){
        int s,d;
        cin>>s>>d;
        adj[s].push_back(d);
        adj[d].push_back(s);
    }
    dfs(0,-1);
    for(auto x:ans){
        cout<<x<<endl;
    }
    return 0;
}