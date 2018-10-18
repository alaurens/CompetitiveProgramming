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

    int n(0);
    string in,trash;
    string guess;
    unordered_set<char> guesses;
    unordered_map<char,int> letters;
    while(sci(n),n!=-1){
        guesses.clear();
        letters.clear();
        getline(cin,trash);
        getline(cin,in);
        getline(cin,guess);
        int counter = 0;
        int wrong  = 0;
        rep(i,sz(in)){
            if(letters.find(in[i]) == letters.end())
                letters[in[i]] = 1;
            else
                letters[in[i]]++;
        }
        rep(i,sz(guess)){
            if(letters.find(guess[i]) == letters.end())
            {
                if(guesses.find(guess[i]) == guesses.end()){
                    wrong++;
                    guesses.insert(guess[i]);
                }
                if (wrong == 7)
                    break;
            }
            else {
                if(guesses.find(guess[i]) == guesses.end()){
                    counter += letters[guess[i]];
                    guesses.insert(guess[i]);
                }
                if (counter == sz(in))
                    break;
            }
        }
        printf("Round %d\n",n);
        if(counter == sz(in))
            printf("You win.\n");
        else if(wrong == 7)
            printf("You lose.\n");
        else
            printf("You chickened out.\n");
    }
}
