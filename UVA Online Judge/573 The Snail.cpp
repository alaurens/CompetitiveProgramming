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
    double h,u,d,f;
    double loss;
    double currh = 0;
    double up = 0;
    int day = 0;
    while(scd(h),h){
        day = 0;
        currh = 0;
        scd(u);scd(d);scd(f);
        loss = u*f/100;
        while(1){
            up = (u - day*loss);
            up = up>0?up:0;
            currh = currh + up;
            if(currh>h){
                printf("success on day %d\n",++day);
                break;
            }
            currh -= d;
            if(currh< 0){
                printf("failure on day %d\n",++day);
                break;
            }
            day++;
        }

    }
}
