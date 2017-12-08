#include "header.h"

int alphabeta(struct board **B,struct ball *P,int depth,int alpha,int beta,int turn){
	int n,value;
	int localalpha = alpha;
	int bestvalue = INT_MIN;
	vector<vector<int> > list;

	struct board **BD = new struct board*[8];
	struct ball *BL = new struct ball[24];

	for(int i = 0 ; i < 8 ; i++){
		BD[i] = new struct board[8];
	}

        for(int j = 0 ; j < 24 ; j++){
                BL[j] = P[j];
        }

	for(int j = 0 ; j < 8 ; j++){
	        for(int k = 0 ; k < 8 ; k++){
	                BD[j][k] = B[j][k];
	        }
	}
//	cout << "depth = " << depth << endl;
/*	if(depth == 0){
		return evaluation(BD);
	}
*/
	if(turn == 0)
		turn = 1;
	else if(turn == 1)
		turn = 0;

	makemovelist(BL,BD,list,turn);
	n = list.size();

	if(n == 0){
		if(turn == 0){
			return INT_MAX;
		}
		if(turn == 1){
			return INT_MIN;
		}
	}
	if(depth == 0){
		return evaluation(BD);
	}
/*	cout << "possible moves" << endl;
	for(int i = 0 ; i <list.size() ; i++){
		for(int j = 0 ; j < list[i].size() ; j++){
			cout << list[i][j] << " ";
		}
		cout << endl;
	}
*/
	for(int i = 0 ; i < n ; i++){
		domove(list[i],BD,BL);
		value = -alphabeta(BD,BL,depth-1,-beta,-localalpha,turn);
		for(int j = 0 ; j < 24 ;j++){
			BL[j] = P[j];
		}
		for(int j = 0 ; j < 8 ; j++){
			for(int k = 0 ; k < 8 ; k++){
				BD[j][k] = B[j][k];
			}
		}
		int temp;
		if(bestvalue < value){
			temp = value;
			value = bestvalue;
			bestvalue = temp;
		}
		if(bestvalue >= beta)
			break;
		if(bestvalue > localalpha)
			localalpha = bestvalue;
	}
	return bestvalue;
}
