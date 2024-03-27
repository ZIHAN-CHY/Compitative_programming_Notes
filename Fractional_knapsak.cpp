            /**************Algorithm***********/
/*
1)  Calculate the ratio (profit/weight) for each item.
2)  Sort all the items in decreasing order of the ratio.
3)  let sumw =0 , sump=0;
4)  start a loop to iterate all the profit of items 
        i) include the pr0fit and the weight in sumw and sump for each corresponfing items;
        ii) if sumw>w then break this loop 
5)  if there is any option to add an items by fracing this , then add the profit and weight of the
    fraction part of this corresponding item. 
*/



            /***********Fractional Knapsak Implementation***********/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n ; cin>>n;
    int w; cin>>w;
    int val[n],wt[n];
    for(int i=0 ; i<n ; i++) cin>>wt[i];
    for(int i=0 ; i<n ; i++) cin>>val[i];
    // cout <<"OK" << endl;
    vector<pair<double,pair<int,int>>>pr;
    for(int i=0 ; i<n ; i++){
        pr.push_back({(double)(val[i])/(double)(wt[i]),{val[i],wt[i]}});
    }
    //  cout <<"OK" << endl;
    sort(pr.begin(),pr.end());
    double sumw=0,sump=0;
    int i;
    for( i=n-1 ; i>=0 ; i--){
        sumw+=pr[i].second.second;
        sump +=pr[i].second.first;
        if(sumw>w) break;
        
    }
   
    sumw -=pr[i].second.second;
    sump -=pr[i].second.first;
    sump+= (double)((w-sumw)*(double)pr[i].second.first)/(double)pr[i].second.second;
    cout << sump << endl;
}