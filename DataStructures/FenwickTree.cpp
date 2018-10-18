//
//  FenwickTree.cpp
//  competitve
//
//  Created by Antoine Laurens on 08.06.18.
//  Copyright © 2018 Antoine Laurens. All rights reserved.
//

#include <stdio.h>
#include <vector>
#define LSOne(i) ((i)&(-(i)))

class FenwickTree{
private:
    std::vector<int> ft;
public:

    FenwickTree(int n){
        ft.assign(n+1,0);
    }

    int rsq(int a){
        int sum = 0;
        for(;a;a -= LSOne(a))
            sum += ft[a];
        return sum;
    }

    int rsq(int a,int b){
        return rsq(a) - (a==1? 0 : rsq(a-1));
    }

    void adjust(int k,int val){
        for(; k < (int)ft.size();k += LSOne(k))
            ft[k] += val;
    }
};
