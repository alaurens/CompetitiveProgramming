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
    map<string,int> ana;
    map<string,string> words;
    string w,w2;;
    cin >> w;
    while(w != "#"){
        w2 = w;
        repi(i,w){
            *i=tolower(*i);
        }
        sort(ALL(w));
        words.insert(mp(w2,w));
        if(ana.find(w)==ana.end())
            ana[w] = 1;
        else
            ana[w]++;
        cin >> w;
    }
    repi(it,words){
        if(ana[(*it).se]==1)
            cout << (*it).fi << endl;
    }
}
