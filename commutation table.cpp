#include <iostream>
#include <math.h>
int main(){
	int variables, rows, columns,groupsSize,saveColumns, groupEvenness;
	
	//entry of data
	printf("How many variables?");
	printf("\n");
	scanf("%d", &variables);
	printf("\n");
	
	//we set our matrix dimensions
	rows=pow(2,variables);	
	columns=variables;
	int matrix[rows][columns];
	saveColumns=columns;
	
	//we fill the matrix
	for(int j=0;j<columns;j++){
		saveColumns--;
		groupsSize=pow(2,saveColumns);
		groupEvenness=0;
	
	for(int i=0; i<rows; i++){
		
		//we check if the group is even or odd; even fills 1, odds fills 0
		if(groupEvenness%2==0){
			matrix[i][j]=1;
		}else{
			matrix[i][j]=0;
		}
		
		if((i+1)%groupsSize==0){ //every cicle the evenness changes
		groupEvenness++;
		}
	}
}

	//we print the matrix
		for(int i=0; i<rows; i++){
		for(int j=0; j<columns; j++){
			printf("%d", matrix[i][j]);
		}
		printf("\n");
	}

return 0;
}
