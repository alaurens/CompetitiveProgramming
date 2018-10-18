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

struct Path{
public:
    int minLifeForPath;
    int lifeOnLastCell;
};
using namespace std;
int max(int x, int y);
int computeMinLifeForPath(Path &path,Path origin,int cost);

int minLife(vector<vector<int> >& cost, int m, int n)
{
    if(DEBUG)
    cout << "on entre dans minLife" << endl;
    if(DEBUG)
    cout << "crash" << endl;
    int i, j;
    // Instead of following line, we can use int tc[m+1][n+1] or
    // dynamically allocate memoery to save space. The following line is
    // used to keep te program simple and make it working on all compilers.
    vector <vector<Path>> paths(m,vector<Path>(n)) ;

    paths[0][0].minLifeForPath = 1;
    paths[0][0].lifeOnLastCell = 1;


    /* Initialize first column of total cost(tc) array */
    for (i = 1; i < m; i++){
        computeMinLifeForPath(paths[i][0],paths[i-1][0],cost[i][0]);
    }
    //
    /* Initialize first row of tc array */
    for (j = 1; j < n; j++){
        computeMinLifeForPath(paths[0][j],paths[0][j-1],cost[0][j]);
    }

        /* Construct rest of the tc array */
        Path dummyPath = Path();
        for (i = 1; i < m; i++){
            for (j = 1; j < n; j++){
                 if(computeMinLifeForPath(dummyPath,paths[i-1][j],cost[i][j]) <= computeMinLifeForPath(dummyPath,paths[i][j-1],cost[i][j])){
                     computeMinLifeForPath(paths[i][j],paths[i-1][j],cost[i][j]);
                 }else{
                     computeMinLifeForPath(paths[i][j],paths[i][j-1],cost[i][j]);
                 }
            }
        }
         return paths[m-1][n-1].minLifeForPath;
}

int computeMinLifeForPath(Path &path,Path origin,int cost){
    //when we have a potion we just take the life of previous cell
    if(cost >= 0){
        path.minLifeForPath = origin.minLifeForPath;
        path.lifeOnLastCell = origin.lifeOnLastCell + cost;
        //if the previous path doesn't need extra life
    }else{
        if(DEBUG)
            cout << "here" << endl;
        //if no potion check if we have enough life to go on cell
        //if we have enough life simply move to it and update life available
        if(origin.lifeOnLastCell> -cost){
            path.minLifeForPath = origin.minLifeForPath;
            path.lifeOnLastCell = origin.lifeOnLastCell + cost;
            //otherwise add enough life based on life from last cell
        }else{
            path.minLifeForPath = origin.lifeOnLastCell + 1 -(cost + origin.lifeOnLastCell);
            path.lifeOnLastCell = 1;
        }
    }
    return path.minLifeForPath;

}

/* A utility function that returns max of 3 integers */
int max(int x, int y)
{
    if (x > y)
    return x;
    else
    return y;
}

/* Driver program to test above functions */
int main()
{
    int r,c;
    std::cin >> r >> c ;
    vector<vector<int> > cost(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> cost[i][j];
        }
    }
    if(DEBUG)
        cout << "crash"<<endl;
    cout << minLife(cost,r,c) << endl;
    return 0;
}
