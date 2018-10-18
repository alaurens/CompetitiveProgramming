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

    ll s,p;
    scanf("%lld %lld",&s,&p);
    while(s!=0){
        ll n = 1;
        while(n*n<=p){
            n+=2;
        }
        n-=2;;
        ll curr = n*n;
        int l = (int)((s+1)/2+(n-1)/2);
        int c = (int)((s+1)/2+(n-1)/2);
        int max = (int)((s+1)/2+(n-1)/2) + 1;
        int min = (int)((s+1)/2-(n-1)/2) - 1;
        int direction = 1; //1 up 2 left 3 down 4 right
        while(curr!=p){
            switch (direction){
                case 1:
                    if(l<max){
                        l++;
                        curr++;
                    }else{
                        direction = 2;
                    }
                    break;

                case 2:
                    if(c>min){
                        c--;
                        curr++;
                    }else{
                        direction = 3;
                    }
                    break;
                case 3:
                    if(l>min){
                        l--;
                        curr++;
                    }else{
                        min--;
                        direction = 4;
                    }
                    break;
                case 4:
                    if(c<max){
                        c++;
                        curr++;
                    }else{
                        max++;
                        direction = 1;
                    }
                    break;
            }
        }
        printf("Line = %d, column = %d.\n",l,c);
        scanf("%lld %lld",&s,&p);
    }
}
