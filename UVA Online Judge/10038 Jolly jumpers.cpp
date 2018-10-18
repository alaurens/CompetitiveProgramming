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
    int n;
    int nums[3100];
    FILL(nums,0);
    int tmp1,tmp2,diff;
    while(sci(n) != EOF){
        FILL(nums,0);
        sci(tmp1);
        rep(i,n-1){
            tmp2 = tmp1;
            sci(tmp1);
            diff = abs(tmp1-tmp2);
            if(INR(diff,0,3100))
                nums[diff-1] = 1;
        }
        bool jolly = true;
        rep(i,n-1){
            jolly = jolly && nums[i];
        }
        if(n <=0)
            printf("Not jolly\n");
        else if(jolly)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }
}
