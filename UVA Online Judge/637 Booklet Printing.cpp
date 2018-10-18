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
    vi p;
    while(sci(n),n){
        int blank = (4-n%4)%4;
        bool front = true;
        int sheet = 1;
        p.clear();
        p.resize(n);
        iota(ALL(p),1);
        auto it1 = p.begin();
        auto it2 = p.end()-1;
        printf("Printing order for %d pages:\n",n);
        while(it1 <= it2){
            if(front){
                if(blank)
                    printf("Sheet %d, front: Blank, %d\n",sheet,*it1);
                else
                    printf("Sheet %d, front: %d, %d\n",sheet,*it2,*it1);
            }else{
                if(blank)
                    printf("Sheet %d, back : %d, Blank\n",sheet,*it1);
                else
                    printf("Sheet %d, back : %d, %d\n",sheet,*it1,*it2);
                sheet++;
            }
            front = !front;
            it1++;
            if(blank)
                blank--;
            else
                it2--;
        }
    }
}
