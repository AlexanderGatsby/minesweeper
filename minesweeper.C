#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	
	int n, m, i, j, l, k, mine;
	n = m = 10;
	
	int A[n][m];
	
	
	//This is for the random
	srand(time(NULL));
	
	//Add the mines
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			//Get a random number between 0 - 2			
			mine = rand() % 3;
			//Put the mine in the random choosen place
			if (mine == 1){
				A[i][j] = -1;
			}else{
				A[i][j] = 0;
			}
			
		}
	}
	
	
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			printf("%3d", A[i][j]);
		}	
		printf("\n");
	}
	
	
	
	return 0;
}

