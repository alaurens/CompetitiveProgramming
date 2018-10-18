//
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
    map<string,int> siz;
    int sizes[9];
    int newSizes[9];
    siz.insert(mp("M",0));
    siz.insert(mp("L",1));
    siz.insert(mp("S",2));
    siz.insert(mp("XS",3));
    siz.insert(mp("XXS",4));
    siz.insert(mp("XXXS",5));
    siz.insert(mp("XL",6));
    siz.insert(mp("XXL",7));
    siz.insert(mp("XXXL",8));

    memset(sizes,0,sizeof(sizes));
    memset(newSizes,0,sizeof(sizes));

    int n;
    string tmp;
    sci(n);
    rep(i,n){
        cin >> tmp;
        sizes[siz[tmp]]++;
    }
    rep(i,n){
        cin >> tmp;
        newSizes[siz[tmp]]++;
    }

    int t1 = abs(sizes[siz["XL"]]-newSizes[siz["XL"]]);
    int t2 = abs(sizes[siz["XXL"]]-newSizes[siz["XXL"]]);
    int t3 = abs(sizes[siz["XXXL"]]-newSizes[siz["XXXL"]]);

    int t4 = sizes[siz["L"]]-newSizes[siz["L"]];
    int t5 = sizes[siz["M"]]-newSizes[siz["M"]];
    int t6 = sizes[siz["S"]]-newSizes[siz["S"]];
    t4 = t4 > 0 ? t4:0;
    t5 = t5 > 0 ? t5:0;
    t6 = t6 > 0 ? t6:0;

    int sum = t1 + t2 + t3 + t4 + t5 + t6;

    printf("%d\n",sum);
}
