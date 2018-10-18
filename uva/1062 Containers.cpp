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
    vector< stack<char> > st;
    stack<char> tmp;
    string C;
    getline(cin,C);
    int num = 0;
    while(C != "end"){
        num++;
        st.clear();
        for(auto c:C){
            if(st.empty()){
                tmp.push(c);
                st.push_back(tmp);
                tmp.pop();
            } else{
                bool found = false;
                for(auto s = st.begin();s!=st.end();s++){
                    if(c <= s->top()){
                        s->push(c);
                        found = true;
                        break;
                    }
                }
                if(!found){
                    tmp.push(c);
                    st.push_back(tmp);
                    tmp.pop();
                }
            }
        }
        printf("Case %d: %ld\n",num,st.size());
        getline(cin,C);
    }
}
