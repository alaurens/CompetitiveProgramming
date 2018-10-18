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
    map<char,char> reverse;

    reverse['A'] = 'A';
    reverse['H'] = 'H';
    reverse['E'] = '3';
    reverse['I'] = 'I';
    reverse['J'] = 'L';
    reverse['L'] = 'J';
    reverse['M'] = 'M';
    reverse['O'] = 'O';
    reverse['S'] = '2';
    reverse['T'] = 'T';
    reverse['U'] = 'U';
    reverse['V'] = 'V';
    reverse['W'] = 'W';
    reverse['X'] = 'X';
    reverse['Y'] = 'Y';
    reverse['Z'] = '5';
    reverse['1'] = '1';
    reverse['2'] = 'S';
    reverse['3'] = 'E';
    reverse['5'] = 'Z';
    reverse['8'] = '8';

    string cand;
    int check = 0;
    int c = 0;
    while(getline(cin,cand)){
        check = 3;
        rep(i,sz(cand)){
            if(!(cand[i]==cand[sz(cand)-1-i]))
                check &= ~(1);
            if(!(cand[i]==reverse[cand[sz(cand)-1-i]]))
                check &= ~(1<<1);
        }
        switch(check){
            case 0:{
                cout << cand;
                printf(" -- is not a palindrome.\n");
                break;
            }
            case 1:{
                cout << cand;
                printf(" -- is a regular palindrome.\n");
                break;
            }
            case 2:{
                cout << cand;
                printf(" -- is a mirrored string.\n");
                break;
            }
            case 3:{
                cout << cand;
                printf(" -- is a mirrored palindrome.\n");
                break;
            }
        }
        printf("\n");
    }
}
