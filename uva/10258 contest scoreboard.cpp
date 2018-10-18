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


struct Contestant{
    int number;
    bitset<10> solved;
    int penalty;
    int tried[10];
    Contestant (): penalty(0){
        solved.reset();
        memset(tried,0,sizeof(tried));
    }
    bool operator<(const Contestant &rhs) const{
        if( this->solved.count() > rhs.solved.count())
            return true;
        else if(this->solved.count() < rhs.solved.count())
            return false;
        else if (this->penalty < rhs.penalty)
            return true;
        else if (this->penalty > rhs.penalty)
            return false;
        else
            return this->number < rhs.number;
    }

    void attempt(int prob,string good,int time){
        if (solved[prob])
            return;
        if(good == "C"){
            solved.set(prob);
            penalty += time;
            penalty += tried[prob];
        }else if(good == "I"){
             tried[prob] += 20;
        }
    }

    friend ostream& operator<<(ostream& os, const Contestant& c);
};

ostream& operator<<(ostream& os, const Contestant& c)
{
    os << c.number<<" " <<c.solved.count() << " " << c.penalty;
    return os;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("test.txt","r",stdin);
#endif
    map<int,Contestant> stu;
    set<Contestant> fin;
    stringstream ss;
    string str;
    string l;
    int n,te,p,t;
    scanf("%d",&n);
    getline(cin,str);
    getline(cin,str);
    while(n--){
        stu.clear();
        fin.clear();
        while(getline(cin,str)){
            if(str.empty()) break;
            ss.clear();
            ss << str;
            ss >> te >> p >> t >> l;
            if (stu.find(te) != stu.end()){
                stu[te].attempt(p,l,t);
                stu[te].number = te;
            } else{
                stu.insert(make_pair(te,Contestant()));
                stu[te].number = te;
                stu[te].attempt(p,l,t);
            }
        }
        for(auto student:stu){
            fin.insert(student.second);
        }

        for(auto student:fin){
            cout << student << endl;
        }
        if(n!=0)
            cout << endl;
    }
}
