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
    int n;
    while(sci(n),n){
        priority_queue<int,vector<int>,greater<int>> que;
        for(int i =0;i<n;i++){
            int t;
            sci(t);
            que.push(t);
        }
        ll cost = 0;
        int sum = 0;
        while(que.size()>1){
            sum = que.top();
            que.pop();
            sum +=que.top();
            que.pop();
            cost = cost+sum;
            que.push(sum);
        }
        printf("%lld\n",cost);
    }
}
