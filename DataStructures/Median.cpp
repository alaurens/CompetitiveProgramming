//
//  Median.cpp
//  competitve
//
//  Created by Antoine Laurens on 17.05.18.
//  Copyright © 2018 Antoine Laurens. All rights reserved.
// Allows to extract the median of a growing list of elementsx

#include "Median.hpp"
#include <queue>
#include <vector>
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
