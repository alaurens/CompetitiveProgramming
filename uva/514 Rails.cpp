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
    int n;
    int tmp;
    stack<int> cars;
    vector<int> goal;
    while(sci(n),n!=0){
        while(sci(tmp),tmp!=0){
            goal.clear();
            goal.push_back(tmp);
            while(!cars.empty()){
                cars.pop();
            }
            for(int i=0;i<n-1;i++){
                sci(tmp);
                goal.push_back(tmp);
            }
            auto it = goal.begin();
            int num = 1;
            cars.push(num);
            while(1){
                if(cars.empty() && num<n){
                    num++;
                    cars.push(num);
                }else if(cars.empty() && num==n){
                    printf("Yes\n");
                    break;
                }else if(cars.top() == *it){
                    cars.pop();
                    it++;
                }else if(num < n){
                    num++;
                    cars.push(num);
                }else if(num == n){
                    printf("No\n");
                    break;
                }

            }
        }
        printf("\n");
    }
}
