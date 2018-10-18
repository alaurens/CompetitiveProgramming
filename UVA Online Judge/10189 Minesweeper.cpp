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

char getgoodchar(int i,int j,char field[110][110]){
    if(field[i][j]== '*')
        return '*';
    int counter = '0';
    repr(ii,-1,2){
        repr(jj,-1,2){
            if(ii == 0 && jj ==0)
                continue;
            if(field[i+ii][j+jj] == '*')
                counter++;
        }
    }
    return counter;
}


int main() {

#ifndef ONLINE_JUDGE
    freopen("test.txt","r",stdin);
#endif

    char field [110][110];
    int n,m,c(0);

    while(scii(n,m),n){
        FILL(field,'0');
        repr(i,1,n+1){
            getchar();
            repr(j,1,m+1){
                field[i][j] = getchar();
            }
        }
        if(c!=0)
            printf("\n");
        printf("Field #%d:\n",++c);
        repr(i,1,n+1){
            repr(j,1,m+1){
                printf("%c",getgoodchar(i,j,field));
            }
            printf("\n");
        }
    }
}
