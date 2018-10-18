// Accepted
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

int c[30] ,k,d,tc,deg, n ; ll a;
int main() {
#ifndef ONLINE_JUDGE
    freopen("test.txt","r",stdin);
#endif
    sci(tc);
    while(tc--){
        a = 0;
        sci(deg);
        rep(i,deg+1){
            sci(c[i]);
        }
        scii(d,k);
        n = 1;
        while(n*d*(n+1)/2<k){
            n++;
        }
        rep(i,deg+1){
            a += (ll)c[i]*(ll)pow(n,i);
        }
        printf("%lld\n",a);
    }
}
