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
    int n,a,b,tmp,nn;
    while(sci(n),n!=0){
        nn = n;
        a = b = 0;
        bool aNow = true;
        for(int i =0;i<32 && n!=0;i++){
            tmp = n & (-n);
            if(aNow){
                a = a + tmp;
            }
            aNow = ! aNow;
            n = n - tmp;
        }
        b = nn ^ a;
        printf("%d %d\n",a,b);
    }
}
