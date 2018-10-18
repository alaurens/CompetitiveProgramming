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

    double n,p;
    double tmpn,price;

    string company,chosenCompany,trash;
    double compliance = 0;
    double minPrice = double(INF);
    int c = 0;
    while(scd(n),n){
        if(c != 0)
            printf("\n");
        double compliance = 0;
        minPrice = double(INF);
        scd(p);
        getline(cin, trash);
        rep(i,n){
            getline(cin, trash);
        }
        rep(i,p){
            getline(cin, company);
            scd(price);
            scd(tmpn);
            if(compliance <tmpn/n){
                minPrice = price;
                compliance = tmpn/n;
                chosenCompany = company;
            }
            if(compliance == tmpn/n){
                if(price<minPrice){
                    minPrice = price;
                    compliance = tmpn/n;
                    chosenCompany = company;
                }
            }
            getline(cin, trash);
            rep(i,tmpn){
                cin.ignore(200,'\n');
            }
        }
        printf("RFP #%d\n",++c);
        cout << chosenCompany << endl;
    }
}
