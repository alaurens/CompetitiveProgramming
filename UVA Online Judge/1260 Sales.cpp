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

int main() {
#ifndef ONLINE_JUDGE
    freopen("test.txt","r",stdin);
#endif
    int tc;
    sci(tc);

    while(tc--){
        int sales[1010];
        int n;
        sci(n);
        int sum(0);
        rep(i,n){
            sci(sales[i]);
            rep(j,i){
                if(sales[i]>=sales[j])
                    sum++;
            }
        }
        printf("%d\n",sum);
    }
}
