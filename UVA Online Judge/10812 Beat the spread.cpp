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
    int t,c,d,a,b;
    sci(t);
    while(t--){
        scii(c,d);
        if(d>c){
            printf("impossible\n");
            continue;
        }
        if(d%2^c%2){
            printf("impossible\n");
            continue;
        }
        a = c-(c-d)/2;
        b = (c-d)/2;
        if(a<=b)
            printf("%d %d\n",b,a);
        else
            printf("%d %d\n",a,b);

    }
}
