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

    int n;
    char input[3],direction[3];
    while(sci(n),n) {
        direction[0] = '+';direction[1] = 'x';

        while(--n){
            scanf("%s",input);
            if(input[0] == 'N')
                continue;

            if(direction[1] == 'x'){
                direction[1] = input[1];
                direction[0] = direction[0] == input[0] ? '+':'-';
            }

            else if (input[1] == 'z'){

                if(direction[1] == 'z') {
                    direction[1] = 'x';
                    direction[0] = direction[0] != input[0] ? '+':'-';
                }
            }

            else {
                if(direction[1] == 'y') {
                    direction[1] = 'x';
                    direction[0] = direction[0] != input[0] ? '+':'-';
                }
            }
        }
        direction[2] = '\0';
        printf("%s\n",direction);
    }
}
