// Accepted
//  main.cpp
//  competitve
//
//  Created by Antoine Laurens on 13.03.18.
//  Copyright © 2018 Antoine Laurens. All rights reserved.
//



#include "competitive.hpp"
#include "Median.cpp"
using namespace std;

typedef std::pair<int,int> ii;
typedef std::vector<int> vi;
typedef std::vector<ii> vii;
typedef std::vector< std::vector<int> > vvi;
typedef std::pair<int,ii> iii;
typedef long long ll;
typedef long l;

class UFDS{
private: std::vector<int> p,rank,sizeSet;

public:
    int numSets;

    UFDS(int size){
        rank.assign(size,0);
        p.assign(size,0);
        sizeSet.assign(size,1);
        std::iota(p.begin(),p.end(),0);
        numSets = size;
    }
    int findSet(int i){
        return (p[i]==i)? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int a,int b){
        return findSet(a) == findSet(b);
    }

    int numDisjointSets(){return numSets;}

    int sizeOfSet(int i){
        return sizeSet[findSet(i)];
    }

    void unionSet(int a,int b){
        if(!isSameSet(a,b)){
            numSets--;
            int x = findSet(a);
            int y = findSet(b);
            if(rank[x]>rank[y]) {
                p[y] = x;
                sizeSet[x] += sizeSet[y];
            }
            else {
                p[x] = y ;
                sizeSet[y] += sizeSet[x];
                if(rank[x]==rank[y])
                    rank[y]++;
            }
        }
    }
};


int main() {
#ifndef ONLINE_JUDGE
    freopen("test.txt","r",stdin);
#endif
    map<char,int> letters;
    int n,m;
    char tmp;
    int counter(1);
    vector<vector<int>> connections;
    queue<int> rise;
    while(scii(n,m)!=EOF){
        counter = 1;
        letters.clear();
        connections.clear();
        connections.resize(n+1);
        UFDS awake(n+1);
        scanf("\n");
        rep(i,3){
            scc(tmp);
            if(letters.find(tmp) == letters.end()){
                letters[tmp] = counter;
                counter++;
            }
            rise.push(letters[tmp]);
            awake.unionSet(letters[tmp],0);
        }
        scanf("\n");
        rep(i,m){
            char c1;
            char c2;
            scc(c1);
            scc(c2);
            scanf("\n");
            if(letters.find(c1) == letters.end()){
                letters[c1] = counter;
                counter++;
            }
            if(letters.find(c2) == letters.end()){
                letters[c2] = counter;
                counter++;
            }
            connections[letters[c1]].push_back(letters[c2]);
            connections[letters[c2]].push_back(letters[c1]);
        }
        int years = -1;
        while(!rise.empty()){
            years++;
            while(!rise.empty()){
                awake.unionSet(rise.front(),0);
                rise.pop();
            }
            rep(i,n){
                int idx = i+1;
                if(awake.isSameSet(idx,0))
                    continue;
                int wakeN = 0;
                rep(j,(int)connections[idx].size()){
                    if(awake.isSameSet(connections[idx][j],0))
                        wakeN++;
                }
                if(wakeN>=3)
                    rise.push(idx);
            }
        }
        if(awake.numSets == 1){
            printf("WAKE UP IN, %d, YEARS\n",years);
        }else{
            printf("THIS BRAIN NEVER WAKES UP\n");
        }
    }
}
