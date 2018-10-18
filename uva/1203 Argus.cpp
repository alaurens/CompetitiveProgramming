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

class CompPair{
public:
    bool operator()(pair<int,int> n1,pair<int,int> n2){
        if(n1.second==n2.second)
            return n1.first>n2.first;
        return n1.second>n2.second;
    }
};
int main() {

#ifndef ONLINE_JUDGE
    freopen("test.txt","r",stdin);
#endif
    priority_queue<pair<int,int>,vector<pair<int,int>>,CompPair> task;
    map<int,int> delays;
    string in;
    int k;
    while(1){
        cin >> in;
        if(in=="#")
            break;
        int q,t;
        scii(q,t);
        delays[q] = t;
        task.push(make_pair(q,t));
    }
    sci(k);
    while(k--){
        auto top = task.top();
        task.pop();
        printf("%d\n",top.first);
        int newtime = top.second + delays[top.first];
        task.push(make_pair(top.first,newtime));
    }
}
