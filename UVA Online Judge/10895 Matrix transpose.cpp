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
    vector< vector< pair<int,int> > > graph;
    int m,n,r;
    while(scii(m,n)!=EOF){
        graph.clear();
        graph.resize(n);
        rep(i,m){
            sci(r);
            vector<int> idx;
            rep(j,r){
                int tmp;
                sci(tmp);
                idx.push_back(tmp-1);
            }
            rep(j,r){
                int tmp;
                sci(tmp);
                graph[idx[j]].push_back(make_pair(i+1,tmp));
            }
        }
        printf("%d %d\n",n,m);
        rep(i,n){
            printf("%d",(int)graph[i].size());
            if((int)graph[i].size()==0){
                printf("\n\n");
                continue;
            }
            rep(j,(int)graph[i].size()){
                printf(" %d",graph[i][j].first);
            }
            printf("\n");
            rep(j,(int)graph[i].size()){
                if(j!=0){
                    printf(" ");
                }
                printf("%d",graph[i][j].second);
            }
            printf("\n");
        }
    }
}
