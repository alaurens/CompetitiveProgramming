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
    set<int> snow;
    queue<int> arr;
    int t,n;
    sci(t);
    int max;
    int tmp;
    while(t--){
        max = 0;
        snow.clear();
        while(!arr.empty()){
            arr.pop();
        }
        sci(n);
        for(int i = 0;i<n;i++){
            sci(tmp);
            if(snow.find(tmp)!=snow.end()){
                while(arr.front()!=tmp){
                    snow.erase(arr.front());
                    arr.pop();
                }
                arr.pop();
                arr.push(tmp);
            }else{
                arr.push(tmp);
                snow.insert(tmp);
            }
            if(arr.size()>max){
                max = (int)arr.size();
            }
        }
        printf("%d\n",max);
    }

}
