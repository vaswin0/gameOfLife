#include <iostream>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

void game( );

int main(){
	cout << "in main ";
	game();

	return 0 ;
}
void game(){


//cout << "in game() " ;

int n = 70000;
int rows = 100, cols = 100;
int counter, neighbours, random, sum = 1;
int currentgen[rows][cols];
int nextgen[rows][cols];


for( int i = 1 ; i < rows ; ++i){

	for (int j = 1; j < cols; ++j) {

		random =  rand();
		if ( random%2 == 0) currentgen[i][j] =1 ;
		else currentgen[i][j] = 0;
		
		}

	}


while(sum!=0){  
	cout << "i am in while loop" << endl;
	printf("\033[H\033[J"); //clearing the screen



  for(int i=1;i<rows-1;i++){    
  	
		for(int j=1;j<cols-1;j++){

			neighbours= currentgen[i][j-1] + currentgen[i][j+1] + currentgen[i-1][j-1] + currentgen[i-1][j] + currentgen[i-1][j+1]  + currentgen[i+1][j-1] + currentgen[i+1][j] + currentgen[i+1][j+1] ;
	      
		  if         (currentgen[i][j] == 1 && neighbours < 2) nextgen[i][j]=0;   //underpopulation
		  else if    (currentgen[i][j] == 1 && neighbours > 3) nextgen[i][j]=0;   //overpopulation
		  else if    (currentgen[i][j] == 0 && neighbours == 3) nextgen[i][j]=1;   //regeneration
                  else  nextgen[i][j] = currentgen[i][j];                           //stasis
}

          }

  printf("\033[H\033[J"); //clearing the screen


for(int i=0;i<rows;i++) {

	counter = 0;
	for(int j=0;j<cols;j++){

    	if(nextgen[i][j]==1)  cout<<"\033[07m  \033[m";
		else cout<<"  ";	  //printf("\t%d",next[i][j]);
		counter++;
		if (counter == cols){ cout <<"\n";}  // printf("\n");printf("\n");}
		  }



                      
 }

usleep(n);

sum = 0;



for(int i = 0; i < rows; i++){    
	for(int j = 0; j < cols; j++){

		sum = sum + nextgen[i][j];
		currentgen[i][j] = nextgen[i][j];

        }
 
    }




 }	 
	  
	 	  
 }
