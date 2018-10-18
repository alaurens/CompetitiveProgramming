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

    int n,b,h,w;
    int tmp,tmp2;
    int min = INF;
    bool found = false;

    while(sci(n)!= EOF){
        min = INF;
        found = false;
        sciii(b,h,w);
        rep(i,h){
            sci(tmp);
            tmp = tmp*n;
            rep(j,w){
                sci(tmp2);
                if(tmp2>=n && tmp<=b && tmp<min){
                    min = tmp;
                    found = true;
                }
            }
        }
        if (found)
            printf("%d\n",min);
        else
            printf("stay home\n");
    }



}
