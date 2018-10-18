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
    int t;
    string in;
    sci(t);
    int c(0);
    scanf("%*c");
    while(t--){
        getline(cin,in);
        repi(it,in){
            if(ispunct(*it) || isspace(*it)){
                in.erase(it);
                it--;
            }
        }
        if(sqrt(double(sz(in))) != floor(sqrt(double(sz(in))))){
            printf("Case #%d:\nNo magic :(\n",++c);
            continue;
        }
        vector<string> square;
        int sizes = sqrt(sz(in));
        for(int i = 0;i<sz(in);i+=sizes){
            square.pb(in.substr(i,sizes));
        }
        bool magic = true;
        rep(i,sizes){
            rep(j,sizes){
                if (square[i][j] != square[sizes-i-1][sizes-j-1])
                    magic = false;
                if (square[i][j] != square[j][i])
                    magic = false;
                if (square[i][j] != square[sizes-j-1][sizes-i-1])
                    magic = false;
            }
        }
            printf("Case #%d:\n",++c);
            if(magic)
                printf("%d\n",sizes);
            else
                printf("No magic :(\n");
    }

}
