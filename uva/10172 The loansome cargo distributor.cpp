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
    int t,n,s,q;
    vector<queue<int>> stations;
    stack<int> cargo;
    sci(t);
    int pos;
    int numBox;
    while(t--){
        pos = 1;
        numBox = 0;
        stations.clear();
        while(!cargo.empty()){
            cargo.pop();
        }
        sciii(n,s,q);
        for(int i=0;i<n;i++){
            queue<int> tmp;
            int qi(0);
            sci(qi);
            while(qi--){
                int tmp2;
                sci(tmp2);
                tmp.push(tmp2);
                numBox++;
            }
            stations.push_back(tmp);
        }
        int time = 0;
        while(1){
            while(!cargo.empty()){
                if(cargo.top() == pos){
                    numBox--;
                    cargo.pop();
                    time++;
                }else if(stations[pos-1].size() < q){
                    stations[pos-1].push(cargo.top());
                    cargo.pop();
                    time++;
                }else{
                    break;
                }
            }
            while(!stations[pos-1].empty() && cargo.size() < s){
                cargo.push(stations[pos-1].front());
                stations[pos-1].pop();
                time++;
            }
            if(numBox == 0){
                break;
            }
            if(pos==n)
                pos=1;
            else
                pos++;
            time+=2;
        }
        printf("%d\n",time);
    }
}
