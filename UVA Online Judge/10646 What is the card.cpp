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


    map<string,int> value;
    value["2C"] = 2;
    value["3C"] = 3;
    value["4C"] = 4;
    value["5C"] = 5;
    value["6C"] = 6;
    value["7C"] = 7;
    value["8C"] = 8;
    value["9C"] = 9;
    value["TC"] = 10;
    value["JC"] = 10;
    value["QC"] = 10;
    value["KC"] = 10;
    value["AC"] = 10;
    value["2S"] = 2;
    value["3S"] = 3;
    value["4S"] = 4;
    value["5S"] = 5;
    value["6S"] = 6;
    value["7S"] = 7;
    value["8S"] = 8;
    value["9S"] = 9;
    value["TS"] = 10;
    value["JS"] = 10;
    value["QS"] = 10;
    value["KS"] = 10;
    value["AS"] = 10;
    value["2D"] = 2;
    value["3D"] = 3;
    value["4D"] = 4;
    value["5D"] = 5;
    value["6D"] = 6;
    value["7D"] = 7;
    value["8D"] = 8;
    value["9D"] = 9;
    value["TD"] = 10;
    value["JD"] = 10;
    value["QD"] = 10;
    value["KD"] = 10;
    value["AD"] = 10;
    value["2H"] = 2;
    value["3H"] = 3;
    value["4H"] = 4;
    value["5H"] = 5;
    value["6H"] = 6;
    value["7H"] = 7;
    value["8H"] = 8;
    value["9H"] = 9;
    value["TH"] = 10;
    value["JH"] = 10;
    value["QH"] = 10;
    value["KH"] = 10;
    value["AH"] = 10;


    deque<string> pile;
    deque<string> pile2;

    int n;
    int y = 0;
    string tmp;
    sci(n);
    int c= 0;
    while(n--)
    {
        pile2.clear();
        pile.clear();
        y = 0;
        rep(i,27){
            cin >> tmp;
            pile.push_front(tmp);
        }
        rep(i,25){
            cin >> tmp;
            pile2.push_back(tmp);
        }

        rep(i,3){
            int tmp2;
            tmp2 = value[pile.front()];
            y += tmp2;
            rep(j, (10-tmp2+1)){
                pile.pop_front();
            }
        }
        while(!pile2.empty()){
            pile.push_front(pile2.front());
            pile2.pop_front();
        }
        rep(i,(y-1)){
            pile.pop_back();
        }
        printf("Case %d: ",++c);
        cout << pile.back() << endl;
    }


}
