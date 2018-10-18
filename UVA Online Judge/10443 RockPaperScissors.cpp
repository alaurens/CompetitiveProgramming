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


map<char,char> comp = {{'R','P'},{'P','S'},{'S','R'}};

int main() {

#ifndef ONLINE_JUDGE
    freopen("test.txt","r",stdin);
#endif
    int t,n,c,r;
    sci(t);
    char grid[110][110];
    char grid2[110][110];
    char trash;
    int cc = 0;
    while(t--){
        FILL(grid,'v');
        FILL(grid2,'v');
        if(cc>0){
            printf("\n");
        }
        cc++;
        sciii(r,c,n);
        for(int i = 1; i<r+1;i++){
            scc(trash);
            for(int j = 1; j<c+1;j++){
                scc(grid[i][j]);
                grid2[i][j] = grid[i][j];
            }
        }
        rep(k,n){
            for(int i = 1; i<r+1;i++){
                for(int j = 1; j<c+1;j++){
                    for(int ii = i-1;ii<=i+1;ii++){
                        for(int jj = j-1;jj<=j+1;jj++){
                            if((ii==i || jj==j) && grid[ii][jj]==comp[grid[i][j]]){
                                grid2[i][j] = grid[ii][jj];
                            }
                        }
                    }
                }
            }
            for(int i = 1; i<r+1;i++){
                for(int j = 1; j<c+1;j++){
                    grid[i][j] = grid2[i][j];
                }
            }
        }
        for(int i = 1; i<r+1;i++){
            for(int j = 1; j<c+1;j++){
                printf("%c",grid[i][j]);
            }
            printf("\n");
        }
    }
}
