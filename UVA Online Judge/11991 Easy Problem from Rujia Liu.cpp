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
    map<int, vector< int > > graph;

    int n,m;
    while(scii(n,m)!=EOF){
        graph.clear();
        rep(i,n){
            int tmp;
            sci(tmp);
            if(graph.find(tmp) != graph.end())
                graph[tmp].push_back(i+1);
            else{
                vector<int> tmp2;
                tmp2.push_back(i+1);
                graph[tmp] = tmp2;
            }
        }
        rep(i,m){
            int t1,t2;
            scii(t1,t2);
            if(graph.find(t2) != graph.end()){
                if(graph[t2].size()<t1){
                    printf("0\n");
                }else{
                    printf("%d\n",graph[t2][--t1]);
                }
            }else{
                printf("0\n");
            }
        }
    }
}
