/**8-Queens Problem
 * @author Patrick Lebold
 * 
 * The code below is a solution to the 8-Queens problem which is discussed at:
 * 		-http://en.wikipedia.org/wiki/Eight_queens_puzzle
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 
 #define EMPTY_VALUE 0
 #define QUEEN_VALUE 1
 
 //prototypes:
 void constructBoard( int **board, int );
 void set( int **board, int, int, int );
 int get( int **board, int, int );
 int canPlaceQueen( int **board, int, int );
 int safe( int **board, int, int, int );
 void printBoard( int **board, int );
 
 int main( void ){
	
	int dimension;
	int success;
	
	printf("What is the dimension of the board? ");
	scanf("%d",&dimension);
	printf("\n\n");
	
	int sizeOfInt = 0;
	int **board = malloc(sizeof(int*)*dimension);
	constructBoard(board,dimension);
	success = canPlaceQueen(board, dimension, 0);
	if(success){
		printf("Placement was successful.\n\n");
		printBoard(board, dimension);
	}
	else
		printf("Placement was unsuccessful.\n\n");
 }
 
 /**.constructBoard(int **, int) creates an empty instance of a board
  * @param board - The board that we are constructing
  * @param dimension - The dimension of the board
  * @return void
  */
 void constructBoard( int **board, int dimension ){
	int i,j;
	for(i=0;i<dimension;i++){
		*(board+i) = malloc(sizeof(int)*dimension);
		for(j=0;j<dimension;j++){
			set(board,EMPTY_VALUE,i,j);
		}
	}
 }
 
 /**.set(int **, int, int, int) sets a location on the board to a value
  * @param board - The board that is being modified
  * @param value - The value we are placing on the board
  * @param row - The row we are placing the value on
  * @param col - The column we are placing the value on
  * @return void
  */
 void set(int **board, int value, int row, int col){
	board[row][col] = value;
 }
 
  /**.get(int **, int, int) retrieves a value at a certain location on the board
  * @param board - The board that we are retrieving data from
  * @param row - The row we are accessing
  * @param col - The column we are accessing
  * @return value - The value retrieved
  */
 int get(int **board, int row, int col){
	return board[row][col];
 }
 
 /**.canPlaceQueen(int **, int, int) Fills a board with queens
  * @param board - The board that we are modifying
  * @param dimension - The size of the board
  * @param col - The column we are currently modifying
  * @return value - The value retrieved
  */
 int canPlaceQueen(int **board, int dimension, int col){
	int row;
	//start from top of board
	for(row=0;row<dimension;row++){
		//if (row,col) is a safe position
		if(safe(board, dimension, row, col)){
			//place a queen at (row,col)
			set(board, QUEEN_VALUE, row, col);
			
			//if the queen we placed was placed in the final column
			if(col==dimension-1){
				//then we have completed the board
				return 1;
			}
			
			//otherwise:
			else{
				//recurse to the next column
				if(canPlaceQueen(board, dimension, col+1)){
					
					return 1;
				}
				else{
					/*if we can not place any more queens, then remove
					 *the queen placed this round of the for-loop
					 */
					set(board,EMPTY_VALUE,row,col);
				}
			}
		}
	}
	
	/*if the board has not been filled after all slots have been checked,
	 *then the board cannot place queens safely.
	 */
	return 0;
 }
 
  /**.safe(int **, int, int, int) Fills a board with queens
  * @param board - The board that we are viewing
  * @param dimension - The size of the board
  * @param row - The row of the queen we are currently placing
  * @param col - The column of the queen we are currently placing
  * @return value - Is the board safe for the queen we are placing?
  */
 int safe(int **board, int dimension, int row, int col){
	int n;
	//Since we are moving from left to right, check all columns to the left
	for(n=0;n<=col;n++){
		//check row for queens
		if(get(board,row,n))
			return 0;
		
		int tempRow = row;
		int tempCol = col;
		
		//check for Top-Left to Bottom-Right diagonals
		while(tempRow>=0&&tempCol>=0){
			if(get(board,tempRow,tempCol))
				return 0;
			else{
				tempRow--;
				tempCol--;
			}
		}
		tempRow = row;
		tempCol = col;
		
		//check for Bottom-Left to Top-Right diagonals
		while(tempRow<=dimension-1&&tempCol>=0){
			if(get(board,tempRow,tempCol))
				return 0;
			else{
				tempRow++;
				tempCol--;
			}
		}
	}
	return 1;
 }
 
 /**.printBoard(int **,int) prints the board
  * @param board - the board we are printing
  * @param dimension - the size of the board
  * @return void
  */
 void printBoard(int **board, int dimension){
	int i,j;
	for(i=0;i<=dimension;i++){
		printf("--");
	}
	printf("\n");
	for(i=0;i<dimension;i++){
		printf("|");
		for(j=0;j<dimension;j++){
			int value = get(board,i,j);
			if(value==EMPTY_VALUE){
				printf(" .");
			}
			else if(value==QUEEN_VALUE){
				printf(" Q");
			}
		}
		printf("|\n");
	}
	for(i=0;i<=dimension;i++){
		printf("--");
	}
	printf("\n");
}
