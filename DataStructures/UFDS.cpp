//
//  UFDS.cpp
//  competitve
//
//  Created by Antoine Laurens on 01.06.18.
//  Copyright © 2018 Antoine Laurens. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <numeric>


class UFDS{
private:
	std::vector<int> p,rank,sizeSet;
	int numSets;

public:
    UFDS(int size){
        rank.assign(0,size);
        p.assign(0,size);
        sizeSet.assign(1,size);
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
