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

struct State{
    int numIn,numOut;
    vector<char> moves;
    int posOrig,posGoal;
    stack<char> letters;
};


int main() {

#ifndef ONLINE_JUDGE
    freopen("test.txt","r",stdin);
#endif
    int n;
    stack<State> tree;
    string word,goal;
    while(getline(cin,word)){

        getline(cin,goal);
        printf("[\n");

        n = (int)word.size();
        if(n!=(int)goal.size()){
            printf("]\n");
            continue;
        }
        State tmp;
        tmp.letters.push(word[0]);
        tmp.numIn = 1;
        tmp.moves.clear();
        tmp.moves.push_back('i');
        tmp.numOut = 0;
        tmp.posGoal = 0;
        tmp.posOrig = 1;
        tree.push(tmp);
        auto print = [](const int& n) { printf(" %c",n); };
        while(!tree.empty()){
            tmp = tree.top();
            State newState = tmp;
            tree.pop();
            if(tmp.numIn > tmp.numOut && tmp.letters.top() == goal[tmp.posGoal]){
                tmp.letters.pop();
                tmp.posGoal++;
                tmp.moves.push_back('o');
                tmp.numOut++;
                if(tmp.numOut == n){
                    printf("%c",tmp.moves[0]);
                    for_each(tmp.moves.begin()+1,tmp.moves.end(),print);
                    printf("\n");
                }else{
                    tree.push(tmp);
                }
            }
            if(tmp.numIn<n){
                newState.moves.push_back('i');
                newState.numIn++;
                newState.posOrig++;
                newState.letters.push(word[tmp.posOrig]);
                tree.push(newState);
            }
        }
        printf("]\n");
    }
}
