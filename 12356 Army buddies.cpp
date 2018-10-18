/
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

    int s,b;
    int left[100100];
    int right[100100];
    while(1){
        scii(s,b);
        if(s==0 && b ==0){
            break;
        }
        rep(i,s+1){
            left[i] = i-1;
            right[i] = i+1;
        }
        left[1] = -1;
        right[s] = -1;
        while(b--){
            int l,r;
            scii(l,r);

            left[right[r]] = left[l];
            if(left[l] == -1)
                printf("* ");
            else
                printf("%d ",left[l]);

            right[left[l]] = right[r];
            if(right[r] == -1)
                printf("*\n");
            else
                printf("%d\n",right[r]);
        }
        printf("-\n");
    }
}
