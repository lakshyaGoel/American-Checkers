#include "header.h"

vector<vector<int> > v;

// All multiple moves for ball A for boad B
void moves(struct ball A,vector<int> &temp,struct board **B){
	int x1,y1;
	struct board **T = new struct board*[8];
	// Copy
	for(int j = 0 ; j < 8 ; j++){
		T[j] = new struct board[8];
 	}
	for(int j = 0 ; j < 8 ; j++){
		for(int k = 0 ; k < 8 ; k++){
			T[j][k] = B[j][k];
		}
	}

	struct ball G;
	G = A;

	if(A.x == 0 ){
		if(A.king == 1){
			x1 = A.x + 1;
			y1 = A.y - 1;
			if(y1 - 1 >= 0){
				if(B[y1][x1].c == 'w' && B[y1-1][x1+1].c == 'n'){
					temp.push_back(A.y);
					temp.push_back(A.x);
					temp.push_back(y1-1);
					temp.push_back(x1+1);
					T[A.y][A.x].c = 'n';
					G.x = x1+1;
					G.y = y1 - 1;
					T[y1][x1].c = 'n';
					T[y1-1][x1+1].c = 'b';
					moves(G,temp,T);
                    v.push_back(temp);
					temp.clear();
				}
			}
		}
		x1 = A.x + 1;
		y1 = A.y + 1;
		if(y1+1 < 8){
			if(B[y1][x1].c == 'w' && B[y1+1][x1+1].c == 'n'){
				temp.push_back(A.y);
				temp.push_back(A.x);
				temp.push_back(y1+1);
				temp.push_back(x1+1);
				
				T = new struct board*[8];
				for(int j = 0 ; j < 8 ; j++){
					T[j] = new struct board[8];
			 	 }
				for(int j = 0 ; j < 8 ; j++){
					for(int k = 0 ; k < 8 ; k++){
						T[j][k] = B[j][k];
					}
				}

                T[A.y][A.x].c = 'n';
                T[y1][x1].c = 'n';
                T[y1+1][x1+1].c = 'b';
				G.x = x1 + 1;
				G.y = y1 + 1;
				if(y1+1 == 7 && A.king != 1){
					v.push_back(temp);
					temp.clear();
				}
				else{
	                moves(G,temp,T);
					v.push_back(temp);	
					temp.clear();
				}	
			}
		}
	}

	if(A.x == 7){
		if(A.king == 1){
			x1 = A.x - 1;
			y1 = A.y - 1;
			if(y1 - 1 >= 0){
				if(B[y1][x1].c == 'w' && B[y1-1][x1-1].c == 'n'){
					temp.push_back(A.y);
					temp.push_back(A.x);
					temp.push_back(y1-1);
					temp.push_back(x1-1);

					T[A.y][A.x].c = 'n';
					T[y1][x1].c = 'n';
					T[y1-1][x1-1].c = 'b';
					G.x = x1-1;
					G.y = y1 - 1;
					moves(G,temp,T);
					v.push_back(temp);
					temp.clear();
				}
			}
		}
		x1 = A.x - 1;
		y1 = A.y + 1;
		if(y1+1 < 8){
			if(B[y1][x1].c == 'w' && B[y1+1][x1-1].c == 'n'){
				temp.push_back(A.y);
				temp.push_back(A.x);
				temp.push_back(y1+1);
				temp.push_back(x1-1);
				
				T = new struct board*[8];
				for(int j = 0 ; j < 8 ; j++){
					T[j] = new struct board[8];
			 	 }
				for(int j = 0 ; j < 8 ; j++){
					for(int k = 0 ; k < 8 ; k++){
						T[j][k] = B[j][k];
					}
				}

        	    T[A.y][A.x].c = 'n';
       	        T[y1][x1].c = 'n';
       	        T[y1+1][x1-1].c = 'b';
				G.x = x1 - 1;
				G.y = y1 + 1;
				if(y1+1 == 7 && A.king != 1){
					v.push_back(temp);
					temp.clear();
				}
				else{
				   moves(G,temp,T); 
				   v.push_back(temp);
				   temp.clear();
				}
			}
		}
	}
	if(A.x != 0 && A.x != 7){
		if(A.king == 1){
			x1 = A.x + 1;
			y1 = A.y - 1;
			if(x1 + 1 < 8 && y1-1 >= 0){
				if(B[y1][x1].c == 'w' && B[y1-1][x1+1].c == 'n'){
					temp.push_back(A.y);
					temp.push_back(A.x);
					temp.push_back(y1-1);
					temp.push_back(x1+1);

					T[A.y][A.x].c = 'n';
					T[y1][x1].c = 'n';
					T[y1-1][x1+1].c = 'b';
					G.x = x1+1;
					G.y = y1-1;
					moves(G,temp,T);
					v.push_back(temp);
					temp.clear();
				}
			}
			x1 = A.x - 1;
			y1 = A.y - 1;
			if(x1 - 1 >=0 && y1-1 >= 0){
				if(B[y1][x1].c == 'w' && B[y1-1][x1-1].c == 'n'){
					temp.push_back(A.y);
					temp.push_back(A.x);
					temp.push_back(y1-1);
					temp.push_back(x1-1);

					T = new struct board*[8];
					for(int j = 0 ; j < 8 ; j++){
						T[j] = new struct board[8];
				 	 }
					for(int j = 0 ; j < 8 ; j++){
						for(int k = 0 ; k < 8 ; k++){
							T[j][k] = B[j][k];
						}
					}

					T[A.y][A.x].c = 'n';
					T[y1][x1].c = 'n';
					T[y1-1][x1-1].c = 'b';
					G.x = x1 - 1;
					G.y = y1 - 1;
					moves(G,temp,T);
					v.push_back(temp);
					temp.clear();
				}
			}
		}

		x1 = A.x + 1;
		y1 = A.y + 1;
		if(x1 + 1 < 8 && y1+1 < 8){
			if(B[y1][x1].c == 'w' && B[y1+1][x1+1].c == 'n'){
				temp.push_back(A.y);
				temp.push_back(A.x);
				temp.push_back(y1+1);
				temp.push_back(x1+1);

				T = new struct board*[8];
				for(int j = 0 ; j < 8 ; j++){
					T[j] = new struct board[8];
			 	 }
				for(int j = 0 ; j < 8 ; j++){
					for(int k = 0 ; k < 8 ; k++){
						T[j][k] = B[j][k];
					}
				}

				T[A.y][A.x].c = 'n';
				T[y1][x1].c = 'n';
				T[y1+1][x1+1].c = 'b';
				G.x = x1+1;
				G.y = y1+1;
				if(y1+1 == 7 && A.king != 1){
					v.push_back(temp);
					temp.clear();
				}
				else{
					moves(G,temp,T);
					v.push_back(temp);
					temp.clear();
				}
			}
		}
		x1 = A.x - 1;
		y1 = A.y + 1;
		if(x1 - 1 >=0 && y1+1 < 8){
			if(B[y1][x1].c == 'w' && B[y1+1][x1-1].c == 'n'){
				temp.push_back(A.y);
				temp.push_back(A.x);
				temp.push_back(y1+1);
				temp.push_back(x1-1);

				T = new struct board*[8];
				for(int j = 0 ; j < 8 ; j++){
					T[j] = new struct board[8];
			 	 }
				for(int j = 0 ; j < 8 ; j++){
					for(int k = 0 ; k < 8 ; k++){
						T[j][k] = B[j][k];
					}
				}

				T[A.y][A.x].c = 'n';
				T[y1][x1].c = 'n';
				T[y1+1][x1-1].c = 'b';
				G.x = x1-1;
				G.y = y1+1;
				if(y1+1 == 7 && A.king != 1){
					v.push_back(temp);
					temp.clear();
				}
				else{
					moves(G,temp,T);
					v.push_back(temp);
					temp.clear();
				}
			}
		}
	}
}

void makemovelist(struct ball *BL,struct board **D,vector<vector<int> > &list,int turn){
	vector<int> temp;
	struct board **T ;
	struct board **W;
	struct ball T1;
	struct ball *P = new struct ball[24];

	for(int i = 0 ; i < 24 ; i++){
		P[i] = BL[i];
	}
	
	W = new struct board *[8];
	for(int j = 0 ; j < 8 ; j++){
		W[j] = new struct board[8];
	}

	if(turn == 0){
		// Inverting board for passing in moves
		for(int i = 0 ; i < 8 ; i++){
			for(int j = 0 ; j < 8 ; j++){
				W[i][j] = D[7-i][7-j];
				if(W[i][j].c == 'b')
					W[i][j].c = 'w';
				else if(W[i][j].c == 'w')
					W[i][j].c = 'b';
			}
		}
		for(int i = 0 ; i < 24 ; i++){
			if(P[i].col != 'n'){
				P[i].x = 7 - P[i].x;
				P[i].y = 7 - P[i].y;
				if(P[i].col == 'w')
					P[i].col = 'b';
				else if(P[i].col == 'b')
					P[i].col = 'w';
			}
		}
	}
	else if(turn == 1){
		// Copy
		for(int i = 0 ; i < 8 ; i++){
			for(int j = 0 ; j < 8 ; j++){
				W[i][j] = D[i][j];
			}
		}
	}

	for(int i = 0 ; i < 24   ; i++){
		if(P[i].col == 'b'){
		    T = new struct board*[8];
			for(int j = 0 ; j < 8 ; j++){
		        T[j] = new struct board[8];
		    }
			for(int j = 0 ; j < 8 ; j++){
				for(int k = 0 ; k < 8 ; k++){
					T[j][k] = W[j][k];
				}
			}

			T1 = P[i];
			temp.clear();
			moves(T1,temp,T);
			vector <vector<int> > l;

			for(int j = 0 ; j < v.size() ; j++){
				if(v[j].size() > 0){
					temp.push_back(v[j][0]);
					temp.push_back(v[j][1]);
				}
				// Make row col pair
				for(int k = 2 ; k < v[j].size() ; k = k+4){
					temp.push_back(v[j][k]);
					temp.push_back(v[j][k+1]);
				}
				if(temp.size() != 0)
					l.push_back(temp);
				temp.clear();
			}		
			if(l.size() != 0){
				for(int j = 0 ; j < l[0].size() ; j++){
					temp.push_back(l[0][j]);
				}
				list.push_back(temp);
				temp.clear();

				for(int j = 1 ; j < l.size() ; j++){
					int a = 2;
					temp.push_back(list[j-1][0]);
					temp.push_back(list[j-1][1]);
					for(int k = 2 ; k < list[j-1].size() ; k=k+2){
						if(list[j-1][k] != l[j][0] || list[j-1][k+1] != l[j][1]){
							temp.push_back(list[j-1][k]);
							temp.push_back(list[j-1][k+1]);
						}
						else{
							break;
						}
						a = a+2;
					}
					if(a == list[j-1].size())
						temp.clear();
					for(int k = 0 ; k < l[j].size() ; k++){
						temp.push_back(l[j][k]);
					}
					list.push_back(temp);
					temp.clear();
				}
			}
			v.clear();
		}
	}
	if(list.size() == 0){
		for(int i = 0 ; i < 24 ; i++){
			if(P[i].col == 'b'){
				T = new struct board*[8];
				for(int j = 0 ; j < 8 ; j++){
			                T[j] = new struct board[8];
			        }
				for(int j = 0 ; j < 8 ; j++){
					for(int k = 0 ; k < 8 ; k++){
						T[j][k] = W[j][k];
					}
				}
	
				T1 = P[i];
				temp.clear();
				simplemove(T1,list,T);
			}
		}
	}

	if(turn == 0){
		vector<vector<int> > l;
		vector<int> z;
		for(int i = 0 ; i < list.size() ; i++){
			for(int j = 0 ; j < list[i].size();j++){
				z.push_back(7-list[i][j]);
			}
			l.push_back(z);
			z.clear();
		}
		list = l;
	}

}
