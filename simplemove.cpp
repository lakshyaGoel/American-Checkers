#include "header.h"
#include "imageloader.h"



void simplemove(struct ball A, vector< vector<int> > &list,struct board **B){

	int x1,y1;
	vector<int> temp;
	struct board **T = new struct board*[8];

	for(int j = 0 ; j < 8 ; j++){
		T[j] = new struct board[8];
 	 }

	for(int j = 0 ; j < 8 ; j++){
		for(int k = 0 ; k < 8 ; k++){
			T[j][k] = B[j][k];
		}
	}

//	struct ball G;
//	G = A;
	
	cout << "yeah....yeah....." << endl;
	if(A.king == 1){
		x1 = A.x - 1;
		y1 = A.y - 1;
		cout << "apple/////////// " << x1 <<" " << y1 << endl;
		if(x1 >=0 && y1 <= 7 && x1 <= 7 && y1 >= 0){
			if(B[y1][x1].c == 'n'){
				temp.push_back(A.y);
				temp.push_back(A.x);
				temp.push_back(y1);
				temp.push_back(x1);
				list.push_back(temp);
				temp.clear();
			}
		}
		x1 = A.x + 1;
		y1 = A.y - 1;
		cout << "]]]]]]]]]]]]]]]]]]]]]]]]]]]]]] " << x1 << " " << y1 << endl;
		if(x1 >=0 && y1 <= 7 && x1 <= 7 && y1 >= 0){
			if(B[y1][x1].c == 'n'){
				temp.push_back(A.y);
				temp.push_back(A.x);
				temp.push_back(y1);
				temp.push_back(x1);
				list.push_back(temp);
				temp.clear();
			}
		}	
		cout << "++++++++++++++=" << endl;
	}
	x1 = A.x - 1;
	y1 = A.y + 1;
	cout << "hello world" << endl;
	if(x1 >=0 && y1 <= 7 && x1 <= 7 && y1 >= 0){
		if(B[y1][x1].c == 'n'){
			temp.push_back(A.y);
			temp.push_back(A.x);
			temp.push_back(y1);
			temp.push_back(x1);
			list.push_back(temp);
			temp.clear();
		}
	}

	x1 = A.x + 1;
	y1 = A.y + 1;
	cout << "bas bahut ho gaya" << endl;
	if(x1 >=0 && y1 <= 7 && x1 <= 7 && y1 >= 0){
		if(B[y1][x1].c == 'n'){
			temp.push_back(A.y);
			temp.push_back(A.x);
			temp.push_back(y1);
			temp.push_back(x1);
			list.push_back(temp);
			temp.clear();
		}
	}
}			
		

