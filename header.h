#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>
#include<string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

struct ball{
	int x,y;
	char col;
	int king;
};

struct board{
	char c;
};

void getBoardStatus();
void moves(struct ball A,vector <int> &temp,struct board **);
void simplemove(struct ball A, vector< vector<int> > &list,struct board **B);
int alphabeta(struct board **B,struct ball *P,int depth,int alpha,int beta,int);
void domove(vector<int> l,struct board **T,struct ball *C);
void display(struct board **B);
int evaluation(struct board **B);
void makemovelist(struct ball *BL,struct board **D,vector<vector<int> > &list,int turn);
void daa();

char * mainget(vector<int>);
vector<int> mainsend(char * r);



