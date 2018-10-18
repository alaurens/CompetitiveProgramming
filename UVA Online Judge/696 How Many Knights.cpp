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
    int n,m;
    while(scii(m,n),m || n){
        int result;
        if(n== 1 || m == 1){result = m*n;}
        else if (n == 2) {result = floor(double(m)/4.0)*4 + miN(m%4*2,4);}
        else if (m == 2) {result = floor(double(n)/4.0)*4 + miN(n%4*2,4);}
        else{ result = ceil(double(n)*double(m)/2.0); }
        printf("%d knights may be placed on a %d row %d column board.\n",result,m,n);
    }
}
