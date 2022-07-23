#include <bits/stdc++.h>
using namespace std;
class DSU{

    vector<int>parent;
    vector<int>rank;

    public:
     DSU(int  n){
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            rank[i]=0;
            parent[i]=i;
        }
    }

    int findPar(int n){
        if(parent[n]==n)return n;
        else return parent[n]=findPar(parent[n]);
    }
    void makeUnion(int v,int u){

        u =findPar(u);
        v = findPar(v);

        if(u==v)return;

        if(rank[u]<rank[v]){
            parent[u]=v;

        }
        else if(rank[v]<rank[u]){
            parent[v]=u;

        }
        else{
            parent[v]=u;
            rank[u]++;
        }


    }

};
