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

void eraseRange(set<int>& sett,int minn,int maxx){
    repr(i,minn,maxx+1){
        sett.erase(i);
    }
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("test.txt","r",stdin);
#endif
    vi nums;
    int maxsec = 5*3600;
    set<int> poss;
    int period(0);
    while(sci(period),period){
        nums.clear();
        rep(i,maxsec){
            poss.insert(i+1);
        }
        do{
            nums.pb(period);
        }while(sci(period),period);
        sort(ALL(nums));
        repi(it,nums){
            int curr1;
            if(it == nums.begin())
                curr1 = 0;
            else
                curr1 = *it-5;
            int curr2 = *it*2-1;
            eraseRange(poss,curr1,curr2);
            while(curr2<maxsec){
                curr1 = curr2+*it-4;
                curr2 = curr2 + *it * 2 ;
                eraseRange(poss,curr1,curr2);
            }
        }
        if (poss.empty()){
            printf("Signals fail to synchronise in 5 hours\n");
        }else{
            int num = *poss.begin();
            printf("%.2d:%.2d:%.2d\n",num/3600,num/60%60,num%60);
        }
    }
}
