#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 4
#define M 4

void printMatrix(int C[][M], int A[][M], int *ptr){
	
	int i, j;
	
	
	printf("  Mines: %d ", *ptr);
	printf("\n     ");
	
	for (i = 0; i < M; i++)
		printf(" %d ", i);
		
	printf("\n");
	
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			
			if (j == 0)
			printf("  %d: ", i);
			
			if (C[i][j] == 0)
			printf(" . ");
			else
			printf(" %d ", A[i][j]);
		}
		printf("\n");
	}
}


void endGame(int A[][M], int a, int b){
	
	int i, j;
	
	printf("\n");
	
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			if (i == a && b == j)
			printf("  X", A[i][j]);
			else if (A[i][j] == -1)
			printf("  *", A[i][j]);
			else
			printf("%3d", A[i][j]);
		}
		printf("\n");
	}
}


int main() {
	
	int i, j, l, k, mine, a, b, mines, win;
		
	int A[N][M];
	int C[N][M];
	
	win = 0;
	mines = 0;
	
	int *minesaptr = &mines;
	
	
	
	//This is for the random
	srand(time(NULL));
	
	//Add the mines
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			//Get a random number between 0 - 5	
			mine = rand() % 6;
			//Put the mine in the random choosen place
			if (mine == 1){
				A[i][j] = -1;
				++mines;
			}else{
				A[i][j] = 0;
			}
			C[i][j] = 0;
		}
	}
	
	//Count the mines adjoining each box
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			
			if (A[i][j] == -1){
				
				for(l = -1; l <= 1; l++){
					for(k = -1; k <= 1; k++){
																
						if ((i+l) >= 0 && (i+l) <= N-1 && (j+k) >= 0 && (j+k) <= M-1){
							if (A[i+l][j+k] != -1)
							++A[i+l][j+k];
						}
						
					}
				}
			}
		}
	}
	
	
	do{
		printMatrix(C, A, minesaptr);
		printf("x: ", A[i][j]);
		scanf("%d", &a);
		printf("y: ", A[i][j]);
		scanf("%d", &b);
		
		
		//Check that is an unopened box
		if (C[a][b] == 0){
			C[a][b]= 1;	
			++win;
		}
		
		
		
		if (A[a][b] == -1){
			endGame(A, a, b);
			a = -1;
		}else {
			if (win == (N*M)-mines){
				printMatrix(C, A, minesaptr);
				printf("\nYou win!");
				a = -1;
			}
			
		}
		
	}while(a != -1);
	
	
	
	return 0;
}

