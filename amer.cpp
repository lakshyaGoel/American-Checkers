#include "header.h"
		
void daa()
{
	struct ball *P;
	struct board **B;
	B = new struct board*[8];
	P = new struct ball[24];
	int x1,y1,x2,y2;
	int n;
	vector <int> w;
	vector < vector <int> > list;

       	for(int i = 0 ; i < 8 ; i++){
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

	cout << "enter your move" << endl;
	cin >> x1 >> y1 >> x2 >> y2;

	display(B);
	w.push_back(x1);
	w.push_back(y1);
	w.push_back(x2);
	w.push_back(y2);

//	board();
//	movement(P);

	cout << endl;
	for(int i = 12 ; i < 24 ; i++){
		if(P[i].col == 'w'){
			if(P[i].y == x1 && P[i].x == y1){
				P[i].y = x2;
				P[i].x = y2;
				B[x1][y1].c = 'n';
				B[x2][y2].c = 'w';
			}
		}
	}
//	board();
//	movement(P);


	while(1){
		makemovelist(P,B,list,1);

		struct board **T;
		struct ball *C;
		vector<int> strength;
		int pw;

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
			pw = alphabeta(T, C, 4, INT_MIN, INT_MAX, 1);
			strength.push_back(pw);
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
		list.clear();
		display(B);
//		board();
//		movement(P);
		cout << endl;
		int flag = 0;
		for(int i = 12 ; i < 24 ; i++){
			if(P[i].col == 'w'){
				flag = 1;
			}
		}
		if(flag == 0)
			break;
 		
		vector <int> a;
		cout << "enter your move" << endl;

		for(int i = 0 ; i < 4 ; i++){
			cin >> x1 ;
			a.push_back(x1);
		}
		domove(a,B,P);

//		board();
//		movement(P);

		flag = 0;
		for(int i = 0 ; i < 12 ; i++){
			if(P[i].col == 'b'){
				flag = 1;
			}
		}
		if(flag == 0)
			break;

		display(B);
		cout << endl;
	}
	
}

