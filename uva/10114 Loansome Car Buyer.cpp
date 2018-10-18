// Accepted
//  main.cpp
//  competitve
//
//  Created by Antoine Laurens on 13.03.18.
//  Copyright © 2018 Antoine Laurens. All rights reserved.
//

// easy problem but be careful when coding

#include "competitive.hpp"

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("test.txt","r",stdin);
#endif

    double price,owes(0.0);
    double n,m;
    int a;
    double b;
    double down;
    vector<pair<int,double>> rates;

    while(scd(n),n>0){
        scd(down);
        scd(owes);
        price = owes+down;
        scd(m);
        double monthPay = owes /(n);
        rates.clear();
        rep(i,m){
            sci(a);
            scd(b);
            rates.pb(mp(a,b));
        }
        int i = 1;
        int currpay = 0;
        price =price - price * rates[0].se;
        while(price<=owes){
            if(sz(rates)>currpay+1) {
                if(i==rates[currpay+1].fi)
                    currpay += 1;
            }
            price =price - price * rates[currpay].se;
            owes -=monthPay;

            i++;
        }
        if(i == 2)
            printf("%d month\n",1);
        else
            printf("%d months\n",i-=1);
    }
}
