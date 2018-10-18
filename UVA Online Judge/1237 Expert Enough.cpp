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
    map<string,ii> cars;
    string temp;
    int tc;
    sci(tc);
    while(tc--){
        cars.clear();
        int n;
        sci(n);
        rep(i,n){
            int l,h;
            cin >> temp;
            scii(l,h);
            cars.insert(mp(temp,mp(l,h)));
        }
        int q;
        sci(q);
        rep(i,q){
            int p;
            sci(p);
            int ctr(0);
            string sol;
            for(auto car:cars){
                if(car.second.first <= p && car.second.second >= p){
                    if(ctr == 1){
                        ctr++;
                        break;
                    }
                    sol = car.first;
                    ctr ++;
                }
            }
            if(ctr == 0 || ctr == 2)
                printf("UNDETERMINED\n");
            else
                cout << sol << endl;
        }
        if(tc)
            printf("\n");
    }


}
