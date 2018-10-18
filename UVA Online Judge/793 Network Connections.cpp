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
private: std::vector<int> p,rank,sizeSet;int numSets;

public:
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
    int t;
    sci(t);
    string in;
    std::stringstream ss;
    int good,wrong,n;
    while(t--){
        sci(n);
        UFDS comp(n);
        scanf("\n");
        good = wrong = 0;
        while(1){
            getline(cin,in);
            if(in.empty()){
                printf("%d,%d\n",good,wrong);
                break;
            }
            int t1,t2;
            ss.clear();
            ss << in.substr(1,in.size()-1);
            if(in[0] == 'c'){
                ss >> t1 >> t2;
                comp.unionSet(--t1,--t2);
            }
            if(in[0] == 'q'){
                ss >> t1 >> t2;
                if(comp.isSameSet(--t1,--t2))
                    good++;
                else
                    wrong++;
            }
        }
        if(t){
            printf("\n");
        }
    }
}
