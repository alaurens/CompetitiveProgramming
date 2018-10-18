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
    multiset<int> bills;

    int n,k,tmp;
    ll sum;
    while(sci(n),n!=0){
        bills.clear();
        sum =0;
        for(int i = 0;i<n;i++){
            sci(k);
            while(k--){
                sci(tmp);
                bills.insert(tmp);
            }
            sum+= *(bills.rbegin())-*(bills.begin());
            bills.erase(prev(bills.end()));
            bills.erase(bills.begin());
        }
        printf("%lld\n",sum);
    }
}
