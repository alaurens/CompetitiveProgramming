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


void roll(char &a,char &b,char &c,char &d){
    char tmp = a;
    a = b;
    b = c;
    c = d;
    d = tmp;
}

void rotate(char table[1000][1000],int n){
    for(int i = 0;i<n/2;i++){
        for(int j = 0;j<(n+1)/2;j++){
            roll(table[i][j],table[n-1-j][i],table[n-1-i][n-1-j],table[j][n-1-i]);
        }
    }
}

int find(char tab1[1000][1000],char tab2[1000][1000],int n,int m){
    int counter = 0;
    for(int i = 0;i<n-m+1;i++){
        for(int j = 0;j<n-m+1;j++){
            bool good = true;
            for(int k = 0;k<m;k++){
                for(int l = 0;l<m;l++){
                    good &= tab1[i+k][j+l] == tab2[k][l];
                }
            }
            if(good)
                counter++;
            else
                good = true;
        }
    }
    return counter;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("test.txt","r",stdin);
#endif
    char bin;
    char tab1[1000][1000],tab2[1000][1000];
    int n,m;
    while(scii(n,m),n!=0){
        scc(bin);
        for(int i = 0;i<n;i++){
            for(int j=0;j<n;j++){
                scc(tab1[i][j]);
            }
            scc(bin);
        }
        for(int i = 0;i<m;i++){
            for(int j=0;j<m;j++){
                scc(tab2[i][j]);
            }
            scc(bin);
        }

        printf("%d ",find(tab1,tab2,n,m));
        rotate(tab2,m);
        printf("%d ",find(tab1,tab2,n,m));
        rotate(tab2,m);
        printf("%d ",find(tab1,tab2,n,m));
        rotate(tab2,m);
        printf("%d",find(tab1,tab2,n,m));

        printf("\n");
    }
}
