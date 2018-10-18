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
    map<string,int> people;
    string p1,p2;
    int t,f;
    sci(t);
    while(t--){
		people.clear();
        int counter = 0;
        UFDS friends(200010);
        sci(f);
        rep(i,f){
            cin >> p1 >> p2;
            if(people.find(p1) == people.end()){
                people[p1] = counter;
                counter ++;
            }
            if(people.find(p2) == people.end()){
                people[p2] = counter;
                counter ++;
            }
            int n1 = people[p1];
            int n2 = people[p2];
            friends.unionSet(n1,n2);
            printf("%d\n",friends.sizeOfSet(n1));
        }
    }

}
