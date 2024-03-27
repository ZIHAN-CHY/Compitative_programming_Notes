            /************************Dijkstra Algorithm*********************/
/*

1.  We would be using a min-heap/set and a distance array of size N initialized with infinity (indicating that at present n
    one of the nodes are reachable from the source node) and initialize the distance to source node as 0.
2.  We push the source node to the queue.
3.  For every node at the top of the queue we pop that element out and look out for its adjacent nodes. 
    If the current reachable distance is better than the previous distance indicated by the 
    distance array, we update the distance and push it in the queue.
4.  A node with a lower distance would be at the top of the priority queue as opposed to a node 
    with a higher distance. By following the steps 3, until our queue becomes empty, we would get the 
    minimum distance from the source node to all other nodes.


*/








            /***************Implementationj*************/
#include<bits/stdc++.h>
using namespace std;
const int sz= 1e5+10;
vector<pair<int,int>>adj[sz];
vector<bool>vis(sz,false);
vector<int>dis(sz, INT_MAX);
int parent[sz];


void clr(){
    for(int i=0 ; i<sz ; i++){
        vis[i]= false;
        dis[i]= INT_MAX;
        adj[i].clear();
        parent[i]= -1;
    }
}


void dijkstra(int source,int v){
    set<pair<int,int>>st;
    st.insert({0,source});
    dis[source]=0;
    // for(int i=1 ; i<=v ; i++) parent[i]=i;
    
    while(st.size()>0){
        auto node = *st.begin();
        int wt = node.first;
        int prnt = node.second;
        st.erase(st.begin());
        if(vis[prnt]) continue; // Already relaxed
        vis[prnt]=true;
        
        for(int i=0 ; i<adj[prnt].size(); i++){
            int child_n = adj[prnt][i].first;
            int child_w = adj[prnt][i].second;
            if(dis[prnt]+child_w < dis[child_n]){
              dis[child_n]= dis[prnt]+child_w ;
              st.insert({dis[child_n],child_n});
              parent[child_n]= prnt;
            }
        }      
    }
    

}


int main(){
    
    int n,e;
    cin>>e>>n;
    for(int i=0 ; i<e ; i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        // adj[v].push_back({u,w});
        
    }
    int s,en;
    cout << " Enter Starting vartex and Ending vartex :" << endl; 
    cin>>s>>en;
     dijkstra(s,n);
     cout << "Cost : " <<dis[en] << endl;
     stack<int>st;
     st.push(en);
     for(int i = en ; i>s ; ){
        st.push(parent[i]);
        i = parent[i];
     }

    while(!st.empty()){
        cout << st.top() <<  " ";
        st.pop();
    }
    // cout << parent[en] << endl;
    cout << endl;

}

/*
9 6
1 2 1
1 3 5
2 3 2
2 5 1
2 4 2
3 5 2
4 5 3
4 6 1
5 6 2
1 4
*/