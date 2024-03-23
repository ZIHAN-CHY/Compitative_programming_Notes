            /*Prims Algorithm*/
/* 
(1) Initialize keys of all vertices as infinite and 
   parent of every vertex as -1.
(2) Create an empty priority_queue pq.  Every item
   of pq is a pair (weight, vertex). Weight (or 
   key) is used  as first item  of pair
   as first item is by default used to compare
   two pairs.
(3) Initialize all vertices as not part of MST yet.
   We use boolean array vis[] for this purpose.
   This array is required to make sure that an already
   considered vertex is not included in pq again. This
   is where Prim's implementation differs from Dijkstra.
   In Dijkstra's algorithm, we didn't need this array as
   distances always increase. We require this array here 
   because key value of a processed vertex may decrease
   if not checked.
(4) Insert source vertex into pq and make its key as 0.
(5) While either pq doesn't become empty 
    a) Extract minimum key vertex from pq. 
       Let the extracted vertex be u.
    b) if u isnot visited, Include u in MST using vis[u] = true. and
       also add the weight of this corresponding node
    c) Loop through all adjacent(child) of u and do 
       following for every vertex v.
          if childnode is not visited
               (1) Insert v and wt into the pq 
               (2) parent[v] = u
               
(6) Print MST edges using parent array.
*/

/***********************Implementation********************/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1000
vector<pair<int,int>>adj[1000];
vector<int>parent(1000,-1);
vector<bool>vis(1000,false);

void clr(){
     // memset(vis,false,sizeof(vis));
    // memset(parent,-1,sizeof(parent));
    for(int i=0 ; i<sz; i++){
        parent[i]=-1;
        vis[i]=false;
        adj[i].clear();
    }

}

int MST(int v){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
   
    pq.push({0,0}); // wt,node
    int sum=0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second;
        if(vis[node]) continue;
        vis[node]= true;
        sum+=wt;
        for(int i=0 ; i<adj[node].size(); i++){
            int childnode = adj[node][i].second;
            int wtc = adj[node][i].first;
            if(!vis[childnode]){
                pq.push({wtc,childnode});

            }
        }
    }
    return sum;
}


int main(){
   
    int e,v;
    cin>>e>>v;
    for(int i=0 ; i<e ; i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    cout << MST(v) << endl;
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

// Complexity O(E)