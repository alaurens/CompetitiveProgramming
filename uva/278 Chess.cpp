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
    int n,m,t;
    char c;
    sci(t);

    while(t--){
        scc(c);
        scc(c);
        scii(n,m);
        switch (c) {
            case 'Q':
            case 'r': {
                printf("%d\n",miN(n,m));
                break;
            }
            case 'k':
            {
                int result;
                if(bit(n,1) || bit(m,1)) { result = n*m/2; }
                else{ result = miN(n,m) * (maX(n,m)>>1); }
                printf("%d\n",result);
                break;
            }
            case 'K':
            {
                int result = ceil(double(m)/2.0) * ceil(double(n)/2.0);
                printf("%d\n",result);
                break;
            }
        }

    }
}
