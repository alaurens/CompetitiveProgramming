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
    int m;
    while(sci(m)!=EOF){
        int cont1 = 0;
        int cont3 = 0;
        char square[100][100];
        int pos1[10000][2];
        int pos3[10000][2];
        for(int i = 0;i<m;i++){
            scanf("%s\n",square[i]);
        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<m;j++){
                if(square[i][j] == '1'){
                    pos1[cont1][0] = i;
                    pos1[cont1][1] = j;
                    cont1++;
                }
                if(square[i][j] == '3'){
                    pos3[cont3][0] = i;
                    pos3[cont3][1] = j;
                    cont3++;
                }
            }
        }
        int mn = 0;
        for(int i = 0;i<cont1;i++){
            int mini = INF;
            for(int j = 0;j<cont3;j++){
                int dist = abs(pos1[i][0] - pos3[j][0]) + abs(pos1[i][1] - pos3[j][1]);
                mini = min(mini,dist);
            }
            mn = max(mn,mini);
        }
        printf("%d\n",mn);
    }
}
