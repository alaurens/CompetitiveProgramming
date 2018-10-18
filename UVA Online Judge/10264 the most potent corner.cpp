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
    int w[40000];
    int n;
    vi sum;
    int pot[40000];
    while(sci(n)!=EOF){
        sum.clear();
        memset(w,0,sizeof(w));
        memset(pot,0,sizeof(w));
        rep(i,pow(2,n)){
            sci(w[i]);
        }
        rep(i,pow(2,n)){
            rep(j,n){
                int idx = i XOR (1<<j);
                pot[i] += w[idx];
            }
        }
        rep(i,pow(2,n)){
            rep(j,n){
                int idx = i XOR (1<<j);
                sum.pb(pot[idx]+pot[i]);
            }
        }
        printf("%d\n",*(max_element(ALL(sum))));
    }
}
