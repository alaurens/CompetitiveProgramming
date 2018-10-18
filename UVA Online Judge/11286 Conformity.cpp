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
    map<set<int>,int> freqs;
    set<int> frosh;
    int n;
    int tmp;
    int max = 0;
    while(sci(n),n!=0){
        max = 0;
        freqs.clear();
        for(int i = 0;i<n;i++){
            frosh.clear();
            for(int j =0;j<5;j++){
                sci(tmp);
                frosh.insert(tmp);
            }
            if(freqs.find(frosh) == freqs.end()){
                freqs[frosh] = 1;
            }else{
                freqs[frosh]++;
            }
        }
        for(auto fr:freqs){
            if(fr.second>max){
                max = fr.second;
            }
        }
        int stu =0;
        for(auto fr:freqs){
            if(fr.second==max){
                stu += max;
            }
        }
        printf("%d\n",stu);
    }
}
