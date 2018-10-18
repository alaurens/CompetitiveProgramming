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

struct comparator{
public:
    bool operator() (const char& lhs,const char& rhs) const{
        if(tolower(lhs)==tolower(rhs)){
            return lhs<rhs;
        }
        return tolower(lhs) < tolower(rhs);
    }
} comparator;

int main() {

#ifndef ONLINE_JUDGE
    freopen("test.txt","r",stdin);
#endif
    string w,w1;
    int t;
    sci(t);
    while(t--){
        cin >> w;
        sort(ALL(w),comparator);
        w1 = w;
        cout << w << endl;
        next_permutation(ALL(w),comparator);
        while(w != w1){
            cout << w << endl;
            next_permutation(ALL(w),comparator);
        }
    }
}
