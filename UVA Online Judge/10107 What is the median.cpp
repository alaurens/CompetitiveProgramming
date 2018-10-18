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


template<class T>
class Median{

public:
    Median(){}

    void push(T value){
        if (minHeap.empty()){
            minHeap.push(value);
        }
        else if(maxHeap.empty()){
            if(value<minHeap.top()){
                maxHeap.push(value);
            }
            else{
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(value);
            }
        }
        else{
            if(minHeap.size()<maxHeap.size()){
                if(value>maxHeap.top()){
                    minHeap.push(value);
                }else{
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(value);
                }
            }else{
                if(value<minHeap.top()){
                    maxHeap.push(value);
                }else{
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(value);
                }
            }
        }
    }

    T median(){
        if (minHeap.empty() && maxHeap.empty())
            return 0;
        if (maxHeap.empty() && !minHeap.empty())
            return minHeap.top();
        if(minHeap.size()<maxHeap.size())
            return maxHeap.top();
        else if(minHeap.size()>maxHeap.size())
            return minHeap.top();
        else
            return (minHeap.top()+maxHeap.top()) / 2;
    }

private:

    class LessThan{
    public:
        LessThan(){};
        bool operator()(const int &left,const int &right){return left>right;}
    };

    class GreaterThan{
    public:
        GreaterThan(){};
        bool operator()(const int &left,const int &right){return left<right;}
    };

    std::priority_queue<T,std::vector<T>,LessThan> minHeap;
    std::priority_queue<T,std::vector<T>,GreaterThan> maxHeap;

};



int main() {

#ifndef ONLINE_JUDGE
    freopen("test.txt","r",stdin);
#endif
    Median<int> medFinder;
    int n;
    while(sci(n) != EOF){
        medFinder.push(n);
        cout << medFinder.median()<<endl;
    }
}
