//	Accepted
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

    int n,k,m;
    double paid[300];
    string text;
    double cost = 0;;
    sci(n);
    while(n--){
        memset(paid,0,sizeof(paid));
        cost = 0;
        sci(k);
        char b;
        scc(b);
        int tmpk = k;
        while(tmpk--){
            int a;
            scc(b);
            sci(a);
            paid[b] = a;
            scc(b);
        }
        sci(m);
        scc(b);
        while(m--){
            while(scc(b),b!='\n'){
                cost += paid[b]/100.0;
            }
        }
        printf("%.2lf$\n",cost);
    }

}
