#include "header.h"

void domove(vector<int> move, struct board **BRD, struct ball *Pieces){
	// If jump over other pieces  #####################
	if(fabs(move[0] - move[2]) == 2){
		int y1 = move[0];
		int x1 = move[1];
		int x2 = move.size() - 1;
		int y2 = x2 - 1;
		BRD[y1][x1].c = 'n';
		for(int j = 0 ; j < 24 ; j++){
			if(Pieces[j].y == y1 && Pieces[j].x == x1){
				Pieces[j].y = move[y2];
				Pieces[j].x = move[x2];
				if(Pieces[j].col == 'w'){
					if(Pieces[j].y == 0){
						Pieces[j].king = 1;
					}
				}
				else if(Pieces[j].col == 'b'){
					if(Pieces[j].y == 7){
						Pieces[j].king = 1;
					}
				}
				BRD[Pieces[j].y][Pieces[j].x].c = Pieces[j].col;
			}
		}
		
		for(int j = 0 ; j+2 < move.size() ; j = j+2){
			int a = (move[j+2] + move[j])/2;
			int b = (move[j+3] + move[j+1])/2;
			BRD[a][b].c = 'n';
			for(int k = 0 ; k < 24 ; k++){
				if(Pieces[k].y == a && Pieces[k].x == b){
					Pieces[k].col = 'n';
					BRD[Pieces[k].y][Pieces[k].x].c = 'n';
				}
			}
		}
	}
	// Simple move ##############
	else if(fabs(move[0] - move[2]) == 1){
		int y1 = move[0];
		int x1 = move[1];
		int y2 = move[2];
		int x2 = move[3];
		for(int j = 0 ; j < 24 ; j++){
			if(Pieces[j].y == y1 && Pieces[j].x == x1){
				Pieces[j].y = y2;
				Pieces[j].x = x2;
				if(Pieces[j].col == 'w'){
					if(Pieces[j].y == 0){
						Pieces[j].king = 1;
					}
				}
				else if(Pieces[j].col == 'b'){
					if(Pieces[j].y == 7){
						Pieces[j].king = 1;
					}
				}
				BRD[y1][x1].c = 'n';
				BRD[y2][x2].c = Pieces[j].col;
			}
		}
	}
	// #############
}
