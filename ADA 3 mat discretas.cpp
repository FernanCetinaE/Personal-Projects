#include <iostream>
#include <math.h>
#include <string.h>

int main(){
	int variables, rows, columns,groupsSize,saveColumns, groupEvenness,onesCounter=0,onesCounterSave=0;
	
	//entry of data
	variables=4;
	
	//we set our matrix dimensions
	rows=pow(2,variables);	
	columns=variables;
	int matrix[rows][columns+1];
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
	
	//we fill the last column with the results
	for(int i=0; i < rows;i++){
		int w = matrix[i][0];
		int x = matrix[i][1];
		int y = matrix[i][2];
		int z= matrix[i][3];
		matrix[i][columns] = (w && y && not(z)) || (not(w)&&not(x)&&y) || (x&&not(y)&&z)|| (not(w)&&y) || (x&&not(z));
		
		if (matrix[i][columns]==1){ //we save the amount of ones, to help the Disjunctive form
			onesCounter++;
			onesCounterSave++;
		}
	}
	
	
	//we print the matrix
	printf("Expression: (w && y && not(z)) || (not(w)&&not(x)&&y) || (x&&not(y)&&z)|| (not(w)&&y) || (x&&not(z))\n\n"); //wyz’+w’x’y+xy’z+w’y+xz’
	
	printf("w x y z Result\n");
		for(int i=0; i<rows; i++){
		for(int j=0; j<columns+1; j++){
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	//we print the Disjunctive normal form
	printf("Disjunctive normal form: \n");
	for(int i=0;i<rows;i++){
		if(matrix[i][columns]==1){
				
			if(matrix[i][0]==1){
					printf("(w)");
				}else{
					printf("(-w)");
			}
				
				if(matrix[i][1]==1){
					printf("(x)");
				}else{
					printf("(-x)");
		}
				if(matrix[i][2]==1){
					printf("(y)");
				}else{
					printf("(-y)");	
			}
			
			onesCounterSave--;
			
			if (onesCounterSave!=0){ //when we get to the last 'one' we stop adding with '+'
				if(matrix[i][3]==1){
					printf("(z) + ");
				}else{
					printf("(-z) + ");
			}
				}
			else{
				if(matrix[i][3]==1){
				printf("(z)");
				}else{
					printf("(-z)");	
			}
		}	
		}
	}
	
	
	//we print the Conjunctive  normal form
	printf("\n\nConjunctive normal form: \n");
	for(int i=0;i<rows;i++){
		if(matrix[i][columns]==0){
				
			if(matrix[i][0]==1){
					printf("[(-w)+");
				}else{
					printf("[(w)+");
			}
				
				if(matrix[i][1]==1){
					printf("(-x)+");
				}else{
					printf("(x)+");
		}
				if(matrix[i][2]==1){
					printf("(-y)+");
				}else{
					printf("(y)+");	
			}
				if(matrix[i][3]==1){
					printf("(-z)] ");
				}else{
					printf("(z)] ");
			}
				
		}
	}
	
	//We create the Karnaugh Map and print it
	printf("\n\n\n");
	printf("Karnaugh's Map:\n\n");
	printf("   00    01   11   10\n");
	int arrayComparison[8]={0,0,0,1,1,1,1,0}; //every two elements we have a pair of combinations
	int Karnaugh[variables*2][variables*2];
	
	for(int p=0;p<7;p+=2){
	printf("%d%d ",arrayComparison[p], arrayComparison[p+1]);
	for(int q=0;q<7;q+=2){
	for(int i=0;i<rows;i++){
		int j=0;
			
		if(matrix[i][j]==arrayComparison[p] && matrix[i][j+1]==arrayComparison[p+1] && matrix[i][j+2]==arrayComparison[q] && matrix[i][j+3]==arrayComparison[q+1]){
			Karnaugh[p][q]=matrix[i][columns];
			printf(" %d   ",Karnaugh[p][q]);
				
			}
				
			}
	}
	printf("\n");
	}
	
return 0;
}
