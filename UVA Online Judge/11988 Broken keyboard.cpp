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
    list<char> text;
    char c = '0';
    list<char>::iterator pos = text.begin();
    bool begin = true;
    bool first = true;
    while(scc(c)!=EOF){
        if(c == '\n'){
            for(auto i = text.begin();i!= text.end();i++){
                printf("%c",*i);
            }
			printf("\n");
            text.clear();
            pos = text.begin();
            begin = true;
            continue;
        }
        if(c == '['){
            begin = true;
            pos = text.begin();
        }else if(c == ']'){
            begin = false;
        }else{
            if(begin){
                text.insert(pos,c);
            }else{
                text.push_back(c);
            }
        }
    }
}
