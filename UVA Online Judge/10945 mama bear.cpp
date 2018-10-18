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

bool checkPalindrom(string in){
    auto it1 = in.begin();
    auto it2 = in.end()-1 ;

    while(1){
        if(distance(it1,it2) <-1){
            return true;
        }
        while(ispunct(*it1)||isspace(*it1)){
            it1++;
        }
        while(ispunct(*it2)||isspace(*it2)){
            it2--;
        }
        if(tolower(*it1) != tolower(*it2))
            break;
        it1++;
        it2--;
    }
    return false;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("test.txt","r",stdin);
#endif
    string in;
    getline(cin,in);
    while(in != "DONE")
    {
        if(checkPalindrom(in)){
            printf("You won't be eaten!\n");
        }else{
            printf("Uh oh..\n");
        }
        getline(cin,in);
    }

}
