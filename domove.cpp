#include "header.h"
#include "imageloader.h"


void domove(vector<int> l,struct board **T,struct ball *C){

	if(fabs(l[0] - l[2]) == 2){
		int y1 = l[0];
		int x1 = l[1];
		int x2 = l.size() - 1;
		int y2 = x2 - 1;
		T[y1][x1].c = 'n';
		for(int j = 0 ; j < 24 ; j++){
			if(C[j].y == y1 && C[j].x == x1){
				C[j].y = l[y2];
				C[j].x = l[x2];
//				cout << C[j].col << endl;
				if(C[j].col == 'w'){
					if(C[j].y == 0){
						C[j].king = 1;
					}
				}
				else if(C[j].col == 'b'){
//					cout << "yahan aaya" << C[j].y <<  endl;
					if(C[j].y == 7){
//						cout << "king" << endl;
						C[j].king = 1;
					}
				}
				T[C[j].y][C[j].x].c = C[j].col;
			}
		}
		
		for(int j = 0 ; j+2 < l.size() ; j = j+2){
			int a = (l[j+2] + l[j])/2;
			int b = (l[j+3] + l[j+1])/2;
			T[a][b].c = 'n';
			for(int k = 0 ; k < 24 ; k++){
				if(C[k].y == a && C[k].x == b){
					C[k].col = 'n';
					T[C[k].y][C[k].x].c = 'n';
				}
			}
		}
	}
		
	else if(fabs(l[0] - l[2]) == 1){
	//	cout << "aaaaaaaaaaaaaa" << endl;
		int y1 = l[0];
		int x1 = l[1];
		int y2 = l[2];
		int x2 = l[3];
		for(int j = 0 ; j < 24 ; j++){
			if(C[j].y == y1 && C[j].x == x1){
				C[j].y = y2;
				C[j].x = x2;
				if(C[j].col == 'w'){
					if(C[j].y == 0){
						C[j].king = 1;
					}
				}
				else if(C[j].col == 'b'){
					if(C[j].y == 7){
						C[j].king = 1;
					}
				}
				T[y1][x1].c = 'n';
				T[y2][x2].c = C[j].col;
			}
		}
	}
}
