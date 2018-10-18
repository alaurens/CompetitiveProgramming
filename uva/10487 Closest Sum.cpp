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
    int nums[1010];
    int c = 0;
    while(sci(n),n!=0){
        printf("Case %d:\n",++c);
        rep(i,n){
            sci(nums[i]);
        }
        int m;
        sci(m);
        rep(i,m){
            int q;
            sci(q);
            int min = INF;
            int sum = 0;
            rep(j,n){
                for(int k = j+1;k<n;k++){
                    if(abs(nums[j]+nums[k]-q)<min){
                        min = abs(nums[j]+nums[k]-q);
                        sum = nums[j]+nums[k];
                    }
                }
            }
            printf("Closest sum to %d is %d.\n",q,sum);
        }
    }
}
