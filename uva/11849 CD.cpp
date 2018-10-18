// Accepted
//  main.cpp
//  competitve
//
//  Created by Antoine Laurens on 13.03.18.
//  Copyright © 2018 Antoine Laurens. All rights reserved.
//



#include "competitive.hpp"
#include "Median.cpp"
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
    unordered_set<int> cd;
    int n,m,cnt;
    while(scii(n,m),n!=0 || m!=0){
        cnt =0;
        cd.clear();
        for(int i =0;i<n;i++){
            int tmp;
            sci(tmp);
            cd.insert(tmp);
        }
        for(int i =0;i<m;i++){
            int tmp;
            sci(tmp);
            if(cd.find(tmp)!=cd.end())
                cnt++;
        }
        printf("%d\n",cnt);
    }
}
