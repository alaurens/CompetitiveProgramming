// Accepted
//  main.cpp
//  competitve
//
//  Created by Antoine Laurens on 13.03.18.
//  Copyright © 2018 Antoine Laurens. All rights reserved.
//



#include "competitive.hpp"

using namespace std;

typedef std::pair<int,int> ii;
typedef std::vector<int> vi;
typedef std::vector<ii> vii;
typedef std::vector< std::vector<int> > vvi;
typedef std::pair<int,ii> iii;
typedef long long ll;
typedef long l;


void checkR(int i,int j,bool attackable[8][8],char board[8][8]){
    int k = 1;
    while(LINR(i+k,0,7)){
        if(board[i+k][j] != '0')
            break;
        attackable[i+k][j] = true;
        k++;
    }
    k = 1;
    while(LINR(i-k,0,7)){
        if(board[i-k][j] != '0')
            break;
        attackable[i-k][j] = true;
        k++;
    }
    k = 1;
    while(LINR(j+k,0,7)){
        if(board[i][j+k] != '0')
            break;
        attackable[i][j+k] = true;
        k++;
    }
    k = 1;
    while(LINR(j-k,0,7)){
        if(board[i][j-k] != '0')
            break;
        attackable[i][j-k] = true;
        k++;
    }

}

void checkN(int i,int j,bool attackable[8][8],char board[8][8]){
    if(LINR(i+1,0,7) && LINR(j+2,0,7))
        attackable[i+1][j+2] = true;
    if(LINR(i+2,0,7) && LINR(j+1,0,7))
        attackable[i+2][j+1] = true;
    if(LINR(i-1,0,7) && LINR(j+2,0,7))
        attackable[i-1][j+2] = true;
    if(LINR(i-2,0,7) && LINR(j+1,0,7))
        attackable[i-2][j+1] = true;
    if(LINR(i+1,0,7) && LINR(j-2,0,7))
        attackable[i+1][j-2] = true;
    if(LINR(i+2,0,7) && LINR(j-1,0,7))
        attackable[i+2][j-1] = true;
    if(LINR(i-1,0,7) && LINR(j-2,0,7))
        attackable[i-1][j-2] = true;
    if(LINR(i-2,0,7) && LINR(j-1,0,7))
        attackable[i-2][j-1] = true;

}

void checkB(int i,int j,bool attackable[8][8],char board[8][8]){
    int k = 1;
    while(LINR(i+k,0,7) && LINR(j+k,0,7)){
        if(board[i+k][j+k] != '0')
            break;
        attackable[i+k][j+k] = true;
        k++;
    }
    k = 1;
    while(LINR(i+k,0,7) && LINR(j-k,0,7)){
        if(board[i+k][j-k] != '0')
            break;
        attackable[i+k][j-k] = true;
        k++;
    }
    k = 1;
    while(LINR(i-k,0,7) && LINR(j+k,0,7)){
        if(board[i-k][j+k] != '0')
            break;
        attackable[i-k][j+k] = true;
        k++;
    }
    k = 1;
    while(LINR(i-k,0,7) && LINR(j-k,0,7)){
        if(board[i-k][j-k] != '0')
            break;
        attackable[i-k][j-k] = true;
        k++;
    }
}

void checkK(int i,int j,bool attackable[8][8],char board[8][8]){
    repr(ii,-1,2){
        repr(jj,-1,2){
            if(LINR(i+ii,0,7) && LINR(j+jj,0,7))
                attackable[i+ii][j+jj] = true;
        }
    }
}

void checkP(int i,int j,bool attackable[8][8],char board[8][8],int p){
    if(LINR(i+p,0,7) && LINR(j+1,0,7))
        attackable[i+p][j+1] = true;
    if(LINR(i+p,0,7) && LINR(j-1,0,7))
        attackable[i+p][j-1] = true;

}




int main() {

#ifndef ONLINE_JUDGE
    freopen("test.txt","r",stdin);
#endif

    char curr[100];
    bool attackable[8][8] = {false};
    char board[8][8];
        FILL(board,'0');
    while(gets(curr) != NULL){
        FILL(board,'0');
        FILL(attackable,false);
        int j = 0,i=0;
        FILL(board,'0');
        rep(k,int (strlen(curr))){
            if(isdigit(curr[k])){
                 j += int(curr[k])-48;
            }
            else if (curr[k] == '/'){
                i++;
                j = 0;
            }
            else {
                if(curr[k] != 'P')
                    board[i][j] = tolower(curr[k]);
                else
                     board[i][j] = curr[k];
                attackable[i][j] = true;
                j++;
            }
        }
        rep(ii,8){
            rep(jj,8){
                switch (board[ii][jj]) {
                    case 'P':{checkP(ii,jj,attackable,board,-1);break;}
                    case 'p':{checkP(ii,jj,attackable,board,1);break;}
                    case 'r':{checkR(ii,jj,attackable,board);break;}
                    case 'q':{checkR(ii,jj,attackable,board);checkB(ii,jj,attackable,board);break;}
                    case 'k':{checkK(ii,jj,attackable,board);break;}
                    case 'b':{checkB(ii,jj,attackable,board);break;}
                    case 'n':{checkN(ii,jj,attackable,board);break;}
                }
            }
        }
        int counter = 0;
        rep(ii,8){
            rep(jj,8){
                if(!attackable[ii][jj])
                    counter++;
            }
        }
        printf("%d\n",counter);
    }
}
