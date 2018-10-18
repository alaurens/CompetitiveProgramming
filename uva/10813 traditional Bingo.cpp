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


bool checkIfWon(bool nums[5][5]){
    bool diag1 = true;
    bool diag2 = true;
    rep(i,5){
        bool row = true;
        bool col = true;
        rep(j,5){
            col &= nums[i][j];
            row &= nums[j][i];
        }
        if(row || col)
            return true;
        diag1 &= nums[i][i];
        diag2 &= nums[i][4-i];
    }
    if(diag1 || diag2)
        return true;
    return false;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("test.txt","r",stdin);
#endif
    int n,pick,grid[7][7],c(0);
    bool bingo = false;
    bool num[5][5];

    sci(n);
    while(n--){
        bingo = false;
        c = 0;
        FILL(num,false);
        num[2][2]= true;
        rep(i,2){
            rep(j,5)
            sci(grid[i][j]);
        }
        rep(i,2){
            sci(grid[2][i]);
        }
        rep(i,2){
            sci(grid[2][i+3]);
        }
        rep(i,2){
            rep(j,5){
                sci(grid[i+3][j]);
            }
        }
        grid[2][2] = 0;
        rep(k,75){
            c++;
            sci(pick);
            rep(i,5){
                rep(j,5){
                    if(grid[i][j] == pick)
                        num[i][j] = true;
                    if(checkIfWon(num) && !bingo){
                        printf("BINGO after %d numbers announced\n",c);
                        bingo = true;
                    }
                }
            }
        }
    }
}
