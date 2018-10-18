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
    int n,nums[15];
    bool a = false;
    while(sci(n),n!=0){
        if(a)
            printf("\n");
        a = true;
        rep(i,n){
            sci(nums[i]);
        }
        for(int i1 = 0;i1<n+1-6;i1++){
            for(int i2 = i1+1;i2<n+1-5;i2++){
                for(int i3 = i2+1;i3<n+1-4;i3++){
                    for(int i4 = i3+1;i4<n+1-3;i4++){
                        for(int i5 = i4+1;i5<n+1-2;i5++){
                            for(int i6 = i5+1;i6<n+1-1; i6++){
                                printf("%d %d %d %d %d %d\n",nums[i1],nums[i2],nums[i3],nums[i4],nums[i5],nums[i6]);
                            }
                        }
                    }
                }
            }
        }
    }
}
