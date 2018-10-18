// Accpeted
//  main.cpp
//  competitve
//
//  Created by Antoine Laurens on 13.03.18.
//  Copyright © 2018 Antoine Laurens. All rights reserved.
//



#include "competitive.hpp"
using namespace std;

typedef std::pair<int,int> ii;
typedef std::vector<int> vi;
typedef std::vector<ii> vii;
typedef std::vector< std::vector<int> > vvi;
typedef std::pair<int,ii> iii;
typedef long long ll;
typedef long l;

int main() {
#ifndef ONLINE_JUDGE
    freopen("test.txt","r",stdin);
#endif
    int f,r;
    int front[12],rear[12];
    multiset<double> ratios;
    while(scii(f,r),f!=0){
        ratios.clear();
        rep(i,f){
            sci(front[i]);
        }
        rep(i,r){
            sci(rear[i]);
        }

        rep(i,f){
            rep(j,r){
                ratios.insert((double)front[i]/(double)rear[j]);
            }
        }
        double maxSpread = 0;
        for (std::set<double>::iterator it = ratios.begin();it != std::prev(ratios.end());it++){
            if(*next(it)/(*it) > maxSpread)
                maxSpread = (*next(it))/(*it);
        }
        printf("%.2f\n",maxSpread);
    }
}
