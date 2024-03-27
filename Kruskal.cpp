/***********Kruskal Algorithm************/
/* 1)Sort all the edges in non-decreasing order of their weight. 
   2)Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If the cycle is not formed, include this edge. Else, discard it. 
   3)Repeat step#2 until there are (V-1) edges in the spanning tree.
*/



/******Implementation_Using Disjoint_set_Union*********/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1000
vector<pair<int,pair<int,int>>>adj;
vector<int>parent(1000,-1);
vector<bool>vis(1000,false);
int siz[1000];

void clr(){
     // memset(vis,false,sizeof(vis));
    // memset(parent,-1,sizeof(parent));
    for(int i=0 ; i<sz; i++){
        parent[i]=-1;
        vis[i]=false;
        
    }

}


void make_set(int v) {
    parent[v] = v;
    siz[v]=1;
}
int find_set(int v){
    if(parent[v]==v) return v;
    return parent[v]=find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (siz[a] < siz[b])
            swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
    }
}



int main(){
    int n,e;
    cin>>e>>n;
    for(int i=0 ; i<e ; i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj.push_back({w,{u,v}});
    }
    sort(adj.begin(),adj.end());
    for(int i=0 ; i<n ; i++){
        make_set(i);
    }
    int cost=0;
    cout << "Path :" << endl;
    for(int i=0; i<adj.size(); i++){
        int wt = adj[i].first;
        int u = adj[i].second.first;
        int v = adj[i].second.second;
        if(find_set(u) == find_set(v)) continue;
        union_sets(u,v);
        cout << u << " " << v << endl;
        cost+=wt;
    }
    cout << "Cost : "<< cost << endl;

}

/*
6 5
0 2 1
0 1 2
2 1 1
2 4 2
2 3 2
3 4 1
*/