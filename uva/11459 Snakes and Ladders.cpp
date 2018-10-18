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

    unordered_map<int,int> snakeLadders;
    vi players;
    int t,a,b,c,tmp1,tmp2;
    bool end = false;
    sci(t);
    while(t--){
        end = false;
        snakeLadders.clear();
        players.clear();
        sciii(a,b,c);
        players.resize(a);
        fill(ALL(players),1);
        rep(i,b){
            scii(tmp1,tmp2);
            snakeLadders[tmp1] = tmp2- tmp1;
        }
        rep(i,c){
            int idx = i%a;
            sci(tmp1);
            if(end)
                continue;
            players[idx] += tmp1;
            if(snakeLadders.find(players[idx]) != snakeLadders.end()){
                players[idx] += snakeLadders[players[idx]];
            }
            if(players[idx] >= 100)
                end = true;
        }
        rep(i,a){
            printf("Position of player %d is %d.\n",i+1,players[i]);
        }
    }
}
