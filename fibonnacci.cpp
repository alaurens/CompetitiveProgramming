/* Dynamic Programming implementation of MCP problem */
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <set>
#include <assert.h>
#include<limits.h>

#define DEBUG 0
#define END 1000000000
#define REP 50
using namespace std;
uint8_t getFib(int n,vector<uint8_t>& seq);

int main()
{
    vector<int> sequence;
    sequence.push_back(1);
    sequence.push_back(1);
    int fib1(1);
    int fib2(1);
    int fib3;
    bool found = false;
    int counter = 2;
    for(int loop = counter - 1; loop < END; ++loop)
    {
        fib3 = fib2;
        fib2 = fib1;
        fib1 = (fib2 + fib3)%10;
        sequence.push_back(fib1);
        if(counter > 35 && fib1 == sequence[30] && fib2 == sequence[29] ){
            found = true;
        }
        if(found)
            break;
        ++counter;
    }
    int t;
    cin >> t ;
    int n(0);
    for(int i=0;i<t;i++){
        cin >> n ;
        if(n<29){
            cout << sequence[n] << endl;
        }else{
            cout << sequence[(n-29)%60+29] << endl;
        }
    }

   return 0;
}
