//
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
    char c;
    int score = 0,totalScore=0;
    int spare = 0;
    int strike1(0),strike2(0);
    int bonus;
    int turn =1;
    int k = 1;
    int prevScore = 0;
    bool nobonus = false;
    while(scc(c),c !='G'){
        while(c!='\n'){
            if(turn>=10)
                nobonus = true;
            if(c==' '){
                scc(c);
                continue;
            }
            bonus = strike2+strike1+spare;
            strike1 = strike2;
            spare = 0;
            strike2 = 0;
            if(isdigit(c)){
                score = c - '0';
                prevScore = score;
                if(k == 2){
                    turn++;
                    k = 1;
                }else{
                    k++;
                }
            }
            else if(c=='/'){
                score = 10 - prevScore;
                if(!nobonus)
                    spare = 1;
                if(k == 2){
                    turn++;
                    k = 1;
                }else{
                    k++;
                }
            }
            else if(c == 'X'){
                score = 10;
                if(!nobonus)
                    strike2 = 1;
                turn++;
                k = 1;
            }

            totalScore += (score + score*bonus);
            scc(c);
        }
        printf("%d\n",totalScore);
        totalScore=0;
        strike1 =0;
        strike2 =0;
        spare = 0;
        turn = 1;
        k = 1;
        nobonus = false;
    }
}
