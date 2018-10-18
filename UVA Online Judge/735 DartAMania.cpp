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
    int n;
    set<multiset<int>> possible;
    int ctr = 0;
    set<int> score_set;
    score_set.insert(0);
    for(int i = 1 ; i<=20 ; i++){
        score_set.insert(i);
        score_set.insert(i*2);
        score_set.insert(i*3);
    }

    score_set.insert(50);

    while(sci(n),n>0){
        possible.clear();
        ctr = 0;
        auto it = score_set.begin();
        int sz = (int)score_set.size();
        for(auto i = score_set.begin() ; i != score_set.end() ; i++){ if(*i <= n)
            for(auto j = score_set.begin() ; j != score_set.end() ; j++){ if(*i + *j <= n)
                for(auto k = score_set.begin() ; k != score_set.end() ; k++){
                    int a = *i, b = *j, c = *k;
                    if(a+b+c>n)
                        break;
                    if(a+b+c == n){
                        ctr++;
                        multiset<int> tmp;
                        tmp.insert(a);
                        tmp.insert(b);
                        tmp.insert(c);
                        possible.insert(tmp);
                    }

                }
            }
        }
        if(ctr == 0)
            printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n",n);
        else{
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n",n,(int)possible.size());
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n",n,ctr);
        }
        rep(i,70){
            printf("*");
        }
        printf("\n");
    }
    printf("END OF OUTPUT\n");
}
