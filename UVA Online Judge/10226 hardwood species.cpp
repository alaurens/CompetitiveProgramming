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
    map<string,double> trees;
    string tree;
    double totTree;
    int t;
    sci(t);
    scanf("\n\n");
    bool first = true;
    while(t--){
        if(!first)
            printf("\n");
        first = false;
        totTree = 0;
        trees.clear();
        while(1){
            getline(cin,tree);
            if(tree.empty())
                break;
            totTree++;
            if(trees.find(tree) == trees.end())
                trees[tree] = 1;
            else{
                trees[tree]++;
            }
        }
        for(auto tr:trees){
            cout << tr.first;
            printf(" %.4lf\n",tr.second/totTree*100);
        }
    }

}
