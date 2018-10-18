// Accepted
//  main.cpp
//  competitve
//
//  Created by Antoine Laurens on 13.03.18.
//  Copyright © 2018 Antoine Laurens. All rights reserved.
//



#include "competitive.hpp"
#include "Median.cpp"
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
    bitset<1000010> slots;
    bool con = false;
    int n,m;
    while(scii(n,m),n!=0 || m !=0){
        con = false;
        slots.reset();
        int a,b,c;
        rep(i,n){
            scii(a,b);
            for(int j = a;j<b;j++){
                if(slots[j])
                    con = true;
                slots[j] = 1;
            }
        }
        rep(i,m){
            sciii(a,b,c);
            while(a<=1000000){
                for(int j = a;j<b;j++){
                    if(j>1000000)
                        break;
                    if(slots[j])
                        con = true;
                    slots.set(j);
                }
                a += c;
                b += c;
            }
        }
        if(con){
            printf("CONFLICT\n");
        }else{
            printf("NO CONFLICT\n");
        }
    }
}
