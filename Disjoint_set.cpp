#include<bits/stdc++.h>
using namespace std;
int parent[1000];
int siz[1000];


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
   for(int i=1; i<=8 ; i++){
      make_set(i);
   }
   for(int i=1 ; i<=5 ; i++){
     int a,b;
     cin>>a>>b;
    union_sets(a,b);
   } 

    int cnt_component=0;
   for(int i=1 ; i<=8 ; i++){
     if(find_set(i)==i ) cnt_component++;
   }
   cout << endl;
   cout << "Ok" << endl;
   cout << cnt_component << endl;


}