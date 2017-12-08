#include "header.h"

int evaluation(struct board **B){
	
	int val1 = 0;
	int val2 = 0;
	int val;

	struct board **T = new struct board*[8];
	for(int i = 0 ; i < 8 ; i++){
		T[i] = new struct board[8];
	}
	for(int i = 0 ; i < 8 ; i++){
		for(int j = 0 ; j < 8 ;j++){
			T[i][j] = B[i][j];
		}
	}
	for(int i = 0 ; i < 8 ; i++){
		for(int j = 0 ; j < 8 ; j++){
			if(B[i][j].c == 'w')
				val1++;
			if(B[i][j].c == 'b')
				val2++;
		}
	}
	val = val2-val1;
	return val;
}