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
    string w1,w2;
    map<string,set<string>> anagrams;
    map<string,string> words;
    int t;
    sci(t);
    getline(cin,w1);
    getline(cin,w1);
    int c = 0;
    while(t--){
        anagrams.clear();
        words.clear();
        if(c!=0)
            printf("\n");
        c++;
        getline(cin,w1);
        w2 = w1;
        while(w2!=""){
			w1.erase(remove(w1.begin(),w1.end(),' '),w1.end());
            sort(ALL(w1));
            if(anagrams.find(w1)!=anagrams.end()){
                anagrams[w1].insert(w2);
            }else{
                anagrams[w1] = set<string>();
                anagrams[w1].insert(w2);
            }
            words[w2]=w1;
            getline(cin,w1);
            w2 = w1;
        }
        repi(i,words){
            string code = (*i).se;
            string wo = (*i).fi;
            for(auto j = anagrams[code].find(wo);j!=anagrams[code].end();j++){
                if (*j != wo)
                    cout << wo<<" = " << *j << endl;
            }
        }
    }
}
