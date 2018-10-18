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
    priority_queue<int> green,blue;
    vector<int> b_surv,g_surv;
    int t,b,sg,sb;
    sci(t);
    while(t--){
        while(!green.empty()){
            green.pop();
        }while(!blue.empty()){
            blue.pop();
        }
        sciii(b,sg,sb);
        int tmp;
        for(int i=0;i<sg;i++){
            sci(tmp);
            green.push(tmp);
        }
        for(int i=0;i<sb;i++){
            sci(tmp);
            blue.push(tmp);
        }
        while(!green.empty() && !blue.empty()){
            for(int i = 0;i<b && !green.empty() && !blue.empty() ;i++){
                if(green.top()>blue.top()){
                    g_surv.push_back(green.top()-blue.top());
                }else if(blue.top()>green.top()){
                    b_surv.push_back(blue.top()-green.top());
                }
                blue.pop();
                green.pop();
            }
            for(auto g:g_surv){
                green.push(g);
            }
            for(auto b:b_surv){
                blue.push(b);
            }
            g_surv.clear();
            b_surv.clear();
        }
        if(green.empty() && blue.empty()){
            printf("green and blue died\n");
        }else if(!green.empty()){
            printf("green wins\n");
            while(!green.empty()){
                printf("%d\n",green.top());
                green.pop();
            }
        }else{
            printf("blue wins\n");
            while(!blue.empty()){
                printf("%d\n",blue.top());
                blue.pop();
            }
        }
        if(t){
            printf("\n");
        }
    }

}
