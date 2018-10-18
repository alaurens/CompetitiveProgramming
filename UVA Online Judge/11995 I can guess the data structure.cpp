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
    while(sci(n)!=EOF){
        int good = 7;
        stack<int> s;
        priority_queue<int> pq;
        queue<int> q;
        for(int i = 0;i<n;i++){
            int a,b;
            scii(a,b);
            if(a == 1){
                pq.push(b);
                q.push(b);
                s.push(b);
            }else{
                if(pq.empty() || pq.top() != b)
                    good = good & 0b110;
                if(q.empty() || q.front() != b)
                    good &= 0b101;
                if(s.empty() || s.top() != b)
                    good &= 0b011;
				if(!pq.empty())
                	pq.pop();
				if(!q.empty())
                	q.pop();
				if(!s.empty())
                s.pop();
            }
        }
        if(good == 0)
            printf("impossible\n");
        else if(good == 1)
            printf("priority queue\n");
        else if(good == 2)
            printf("queue\n");
        else if(good == 4)
            printf("stack\n");
        else
            printf("not sure\n");

    }
}
