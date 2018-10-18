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



int findSmallestAbove(int min,vi cards){
    repi(i,cards){
        if(*i>=min){
            return *i;
        }
    }
    return -1;
}


int main() {

#ifndef ONLINE_JUDGE
    freopen("test.txt","r",stdin);
#endif

    deque<int> prince;
    deque<int> princesse;
    int tmp;
    vi cardsLeft;
    int score = 0;

    while(sci(tmp),tmp){
        cardsLeft.clear();
        rep(i,52){cardsLeft.pb(i+1);}
        score =0;
        princesse.clear();
        prince.clear();
        princesse.pb(tmp);
        cardsLeft[tmp-1] = 0;
        rep(i,2){
            sci(tmp);
            cardsLeft[tmp-1] = 0;
            princesse.pb(tmp);
        }
        rep(i,2){
            sci(tmp);
            cardsLeft[tmp-1] = 0;
            prince.pb(tmp);
        }
        sort(ALL(prince));
        sort(ALL(princesse));
        if(prince.back() > princesse.back()){
            prince.pop_back();
            princesse.pop_front();
            score |=  1;
        }else{
            prince.pop_back();
            princesse.pop_back();
            score &= ~(1);
        }

        if(prince.back() > princesse.back()){
            score |=  (1<<1);
        }else{
            score &= ~(1<<1);
            if(score ==1){
                if(prince.back()>princesse.front())
                    princesse.pop_back();
            }
        }

        if(score == 0)
            printf("-1\n");
        if(score == 1 || score == 2){
            printf("%d\n",findSmallestAbove(princesse.back(),cardsLeft));
        }
        if(score == 3)
            printf("%d\n",findSmallestAbove(1,cardsLeft));
    }
}
