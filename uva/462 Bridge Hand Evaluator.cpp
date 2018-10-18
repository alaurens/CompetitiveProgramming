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

    char c[2];
    vector<bitset<13>> cards(4);
    map<char,int> ranks;
    map<char,int> suits;
    map<int,char> revsuits;
    ranks['A'] = 12;
    ranks['2'] = 0;
    ranks['3'] = 1;
    ranks['4'] = 2;
    ranks['5'] = 3;
    ranks['6'] = 4;
    ranks['7'] = 5;
    ranks['8'] = 6;
    ranks['9'] = 7;
    ranks['T'] = 8;
    ranks['J'] = 9;
    ranks['Q'] = 10;
    ranks['K'] = 11;
    suits['S'] = 0;
    suits['H'] = 1;
    suits['D'] = 2;
    suits['C'] = 3;
    revsuits[0] ='S';
    revsuits[1] = 'H';
    revsuits[2] = 'D';
    revsuits[3] = 'C';

    while(scs(c)!=EOF){
        // load cards
        cards[0].reset();
        cards[1].reset();
        cards[2].reset();
        cards[3].reset();
        cards[suits[c[1]]].set(ranks[c[0]]);
        rep(i,12){
            scs(c);
            cards[suits[c[1]]].set(ranks[c[0]]);
        }
        // count points
        int points = 0;
        int points2 = 0;
        bool stop = true;
        int max = 0;
        int idx = 0;
        rep(i,4){
            bool tmpstop = false;
            points  += cards[i][12]*4 + cards[i][11]*3 + cards[i][10]*2 + cards[i][9];
            points2 += cards[i][12]*4 + cards[i][11]*3 + cards[i][10]*2 + cards[i][9];
            if(cards[i].test(11) && cards[i].count() == 1)
            {
                points -=1;
                points2 -= 1;
            }
            if(cards[i].test(10) && cards[i].count() <= 2){
                points -= 1;
                points2 -= 1;
            }
            if(cards[i].test(9) && cards[i].count() <= 3){
                points -=1;
                points2 -= 1;
            }

            if(cards[i].test(12))
                tmpstop = true;
            if(cards[i].test(11) && cards[i].count() > 1)
                tmpstop = true;
            if(cards[i].test(10) && cards[i].count() > 2)
                tmpstop = true;

            stop = stop && tmpstop;

            if(cards[i].count() == 2)
                points +=1;
            if(cards[i].count() == 1)
                points +=2;
            if(cards[i].count() == 0)
                points +=2;

            if(cards[i].count()>max){
                max = int(cards[i].count());
                idx = i;
            }
        }
        if(points < 14)
            printf("PASS\n");
        else if(stop && points2 >15)
            printf("BID NO-TRUMP\n");
        else
            printf("BID %c\n",revsuits[idx]);
    }
}
