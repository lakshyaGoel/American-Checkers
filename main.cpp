#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdlib.h>
#include "header.h"

struct ball *P;
struct board **B;

vector <int> a;
void Timer (int x);

using namespace std;
int chance = 1;

void play()
{	
	int x1;

	vector < vector <int> > list;
	if(chance == 1){
		int fromX, fromY, toX, toY;
		cout << "Input in row column - row column" << endl;
		cin >> fromX >> fromY >> toX >> toY ;
		a.push_back(fromX);
		a.push_back(fromY);
		a.push_back(toX);
		a.push_back(toY);
		domove(a,B,P);
		a.clear();
		cout << endl;
	}else if(chance == 0){
		makemovelist(P,B,list,chance);
		struct board **T;
		struct ball *C;
		vector<int> strength;
		int Pw;
		for(int i = 0 ; i < list.size() ; i++){
			T = new struct board*[8];
	        	C = new struct ball[24];
		
			for(int j = 0 ; j < 8 ; j++){
				T[j] = new struct board[8];
			}
			for(int j = 0 ; j < 24 ; j++){
				C[j] = P[j];
			}
			
			for(int j = 0 ; j < 8 ; j++){
				for(int k = 0 ; k < 8 ; k++){
					T[j][k] = B[j][k];
				}
			}
	
			domove(list[i],T,C); 
			Pw = alphabeta(T, C, 4, INT_MIN, INT_MAX, 1);
			strength.push_back(Pw);
		}
		
		int index;
		int max = INT_MIN;
		for(int i = 0 ; i < strength.size() ;i++){
			if(max < strength[i]){
				max = strength[i];
				index = i;
			}
		}
		domove(list[index],B,P);
		a.clear();
		list.clear();
	}
	if(chance == 0)
		chance = 1;
	else if(chance == 1)
		chance = 0;

}

void checkWin() {
	int c1 = 0;
	int c2 = 0;	
	for(int i = 0 ; i < 24 ; i++){
		if(P[i].col == 'b')
			c1++;
		if(P[i].col == 'w')
			c2++;
	}
	if(c1 == 0){
		getBoardStatus();	
		cout << "blue wins" << endl;
		exit (0);
	}
	if(c2 == 0){
		getBoardStatus();
		cout << "red wins" << endl;
		exit(0);
	}
}

void getBoardStatus(){
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if (B[i][j].c == 'n'){
				cout << "_" << "\t ";
			}
			else {
				cout << B[i][j].c << "\t ";
			} 
		}
		cout << endl;
	}
	cout << endl;
}

int main(int argc,char **argv) {
	B = new struct board*[8];
	P = new struct ball[24];
	int x1,y1,x2,y2;
	int n;
	vector <int> w;
	vector < vector <int> > list;

    for(int i = 0 ; i < 8 ; i++) {
		B[i] = new struct board[8];
	}

	for(int i = 0 ; i < 8 ; i++){
		for(int j = 0 ; j < 8 ; j++){
			B[j][i].c = 'n';
		}
	}

	int i = 0;
	for(int j = 0 ; j < 3 ; j = j+2){
		for(int k = 0 ; k < 7 ; k = k + 2){
			P[i].x = k;
			P[i].y = j;
			P[i].col = 'b';
			P[i].king = 0;
			B[j][k].c = 'b';
			i++;
		}
	}
	for(int k = 1 ; k <= 7 ; k = k+2){
		P[i].y = 1;
		P[i].x = k;
		P[i].col = 'b';
		P[i].king = 0;
		B[1][k].c = 'b';
		i++;
	}
	for(int j = 5 ; j < 8 ; j = j+2 ){
		for(int k = 1 ; k < 8 ; k= k+2){
			P[i].y = j;
			P[i].x = k;
			P[i].col = 'w';
			P[i].king = 0;
			B[j][k].c = 'w';
			i++;
		}
	}
	for(int k = 0; k <7 ; k = k+2){
		P[i].y = 6;
		P[i].x = k;
		P[i].col = 'w';
		P[i].king = 0;
		B[6][k].c = 'w';
		i++;
	}
	while(1){
		getBoardStatus();
		play();
		checkWin();
	}
	
	return 0;
}