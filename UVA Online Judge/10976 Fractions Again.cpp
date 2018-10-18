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
    int k;

    while(sci(k)!=EOF){
        vector<ii> sols;
        for(int y = k+1;y<=2*k;y++){
            if(k*y % (y-k) == 0)
                sols.pb(mp(k*y/(y-k),y));
        }
        printf("%d\n",(int)sols.size());
        for(auto sol:sols){
            printf("1/%d = 1/%d + 1/%d\n",k,sol.first,sol.second);
        }
    }
}
