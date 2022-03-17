#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10
#define M 10

void printMatrix(int A[][M], int C[][M]){
	
	int i, j;
	
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			if (A[i][j] == 1){
				printf("%3d", A[i][j]);		
			}else{
				printf(" . ");
			}
		}	
		printf("\n");
	}
}

int main() {
	
	int i, j, l, k, mine, a, b;
	
	int A[N][M];
	int C[N][M];
	
	
	//This is for the random
	srand(time(NULL));
	
	//Add the mines
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			//Get a random number between 0 - 2			
			mine = rand() % 3;
			//Put the mine in the random choosen place
			if (mine == 1){
				A[i][j] = -1;
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
	
	printMatrix(A, C);
	
	return 0;
}

