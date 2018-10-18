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

int grid[5][5];
int tmp[3][3];
bool done(){
    rep(i,3)
        rep(j,3){
            if(grid[i+1][j+1]==1)
                return false;
        }
    return true;
}

int f(int l){
    if(done())
        return l-1;
    rep(i,3)
        rep(j,3){
            int cell = grid[i][j+1] + grid[i+1][j] + grid[i+2][j+1] + grid[i+1][j+2];
            tmp[i][j]= cell&1;
        }
    rep(i,3)
        rep(j,3){
            int cell = grid[i][j+1] + grid[i+1][j] + grid[i+2][j+1] + grid[i+1][j+2];
            grid[i+1][j+1]=tmp[i][j];
        }
    return f(++l);
}
int main() {

#ifndef ONLINE_JUDGE
    freopen("test.txt","r",stdin);
#endif


    memset(grid,0,sizeof(grid));
    int n;
    sci(n);
    scanf("\n");
    while(n--){
        memset(grid,0,sizeof(grid));
        rep(i,3){
            scanf("\n");
            rep(j,3){
                char a;
                scc(a);
                grid[i+1][j+1] = (int)(a-'0');
            }
        }
        printf("%d\n",f(0));
    }

}
