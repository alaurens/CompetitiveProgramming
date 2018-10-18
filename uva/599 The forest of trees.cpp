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
private:
    std::vector<int> p,rank,sizeSet;


public:
    int numSets;
    int numAcorn;
    UFDS(int size){
        rank.assign(size,0);
        p.assign(size,0);
        sizeSet.assign(size,1);
        std::iota(p.begin(),p.end(),0);
        numSets = size;
        numAcorn = size;
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
            if(sizeSet[x] == 1)
                numAcorn--;
            if(sizeSet[y] == 1)
                numAcorn--;
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
    int t;
    sci(t);
    string in;
    scanf("\n");
    while(t--){
        UFDS tree(26);
        while(1){
            getline(cin,in);
            if(in[0] == '*')
                break;
            tree.unionSet(in[1]-'A',in[3]-'A');
        }
        getline(cin,in);
        int numNodes = ((int)in.size()+1)/2;
        int acorn = numNodes - (26 - tree.numAcorn);
        int trees = tree.numSets-tree.numAcorn;
        printf("There are %d tree(s) and %d acorn(s).\n",trees,acorn);
    }
}
