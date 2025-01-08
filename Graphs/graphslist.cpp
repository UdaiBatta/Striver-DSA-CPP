#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i =0;i<m;i++){
        //u ---> v
        int u , v;
        cin>>u>>v;
        adj[u].push_back(v);
        //in case of directed graph we use dont write the  below line 
        // because we are not consuming 2 edges but only 1
        // adj[v].push_back(u);        
    }
}