//***************************************************
// Filename: othello.c
//
// Author: Nandigam
// @version Winter 2019
// @author Atone Joryman
//***************************************************

#include "othello.h"

/******************************************************
 *
 *  Displays the board (as SIZE x SIZE grid) on console
 * @param board to print (2x2 array)
 ******************************************************/
void displayBoard(char board[][SIZE])
{
	printf("\n");
	for (int i = 0; i < SIZE; i++) {
		printf((i == 0 ? "%5d" : "%3d"), i+1);
	}
	printf("\n");

	for (int i = 0; i < SIZE; i++) {
		printf("%2d", i+1);
		for (int j = 0; j < SIZE; j++) {
			printf("%3c", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/*********************************************************************
 * Initializes the board with start configuration of discs 
 * (see project specs)
 *
 * @param board to intialize (2x2 array)
 *  ******************************************************************/
void initializeBoard(char board[][SIZE])
{
	// COMPLETE THIS FUNCTION
	// i - row, j = col
	//

	//board[1][1] = EMPTY;
	//
	if(SIZE % 2 != 0){
		printf("Size should not be an odd number. Othello won't play center initially");
	}
	for (int i = 0; i < SIZE; i++) {
		for (int j=0; j < SIZE; j++) {

			//conditionals to initialize the game of othello
			if(i == ((SIZE-1)/2) && j == ((SIZE-1)/2)){
				board[i][j] = BLACK;
			}

			else if (i == ((SIZE-1)/2) && j == (SIZE/2)){
				board[i][j] = WHITE;
			}

			else if (i == (SIZE/2) && j == ((SIZE-1)/2)){
				board[i][j] = WHITE;
			}

			else if (i == (SIZE/2) && j == (SIZE/2)){
				board[i][j] = BLACK;
			}
			//after placing intial disc do empty tile too
			else{
				board[i][j] = EMPTY;
			}
		}
	}

}

/*******************************************************************
 * Returns true if moving the disc to location row,col is valid; 
 * else returns false
 *
 * @param board to check for a valid move
 * @param which row
 * @param which column
 * @param what disc are we looking at
 * @return 0 or 1 if valid
 * ****************************************************************/
bool isValidMove(char board[][SIZE], int row, int col, char disc)
{
	// 012
	// ---
	//3-B-4 //visual of how imagine to look at surroundings
	// ---
	// 567

	//row and column to adjust
	int rowA = row, colA = col;
	//keep up with whose the opponent
	char opponent = ' ';
	int count = 0;

	//printf("Player: %c\n", disc);
	//choose which character to be using
	if(disc == WHITE){
		opponent = BLACK;
	}

	else{
		opponent = WHITE;
	}
	//place eight different ways to place disc
	char move0 = board[rowA-1][colA-1];
	char move1 = board[rowA-1][colA];
	char move2 = board[rowA-1][colA+1];
	char move3 = board[rowA][colA-1];
	char move4 = board[rowA][colA+1];
	char move5 = board[rowA+1][colA-1];
	char move6 = board[rowA+1][colA];
	char move7 = board[rowA+1][colA+1];

	//check valid, check which move, then proceed
	if(board[rowA][colA] != EMPTY){
		return false;									


	}
	else {
		if(opponent == move0){
			//decrement first
			rowA--;
			colA--;
			//check out for rules and stay in bounds when checking
			while(board[rowA][colA] !=  disc && board[rowA][colA] != EMPTY && (rowA <=SIZE && rowA >= 0) && (colA <= SIZE && colA>=0)){
				rowA--;
				colA--;
				count++;

			}
			//printf("%d\n", count);
			//printf("%c, row: %d, col: %d \n" , board[rowA][colA], rowA+1, colA);
			//check if between the size of the board and board is at disc
			if(count >=1 && count < SIZE && board[rowA][colA] == disc){
				//printf("here0");
				return true;
			}

		}
		//restore values if changed
		rowA = row;
		colA = col;
		count = 0;

		if(opponent == move1){
			rowA--;
			while(board[rowA][colA] !=  disc && board[rowA][colA] != EMPTY && (rowA <=SIZE && rowA >= 0) && (colA <= SIZE && colA>=0)){
				rowA--;
				count++;

				//return true;
			}
			if(count >=1 && count < SIZE && board[rowA][colA] == disc){
				//printf("here1");
				return true;
			}


		}
		rowA = row;
		colA = col;
		count = 0;

		if(opponent == move2){
			rowA--;
			colA++;
			while(board[rowA][colA] !=  disc && board[rowA][colA] != EMPTY && (rowA <=SIZE && rowA >= 0) && (colA <= SIZE && colA>=0)){
				rowA--;
				colA++;
				count++;

				//return true;
			}
			if(count >=1 && count < SIZE && board[rowA][colA] == disc){
				//printf("here2");
				return true;
			}

		}
		rowA = row;
		colA = col;
		count = 0;

		if(opponent == move3){
			colA--;

			while(board[rowA][colA] !=  disc && board[rowA][colA] != EMPTY && (rowA <=SIZE && rowA >= 0) && (colA <= SIZE && colA>=0)){
				//printf("%c, row: %d, col: %d \n" , board[rowA][colA], rowA+1, colA+1);

				colA--;
				count++;

				//return true;
			}
			//printf("Move 3\n");
			//printf("%d\n", count);
			//printf("%c, row: %d, col: %d \n" , board[rowA][colA], rowA, colA);

			if(count >=1 && count < SIZE && board[rowA][colA] == disc){
				//printf("here3");
				return true;
			}

		}
		rowA = row;
		colA = col;
		count = 0;

		if(opponent == move4){
			colA++;
			while(board[rowA][colA] !=  disc && board[rowA][colA] != EMPTY && (rowA <=SIZE && rowA >= 0) && (colA <= SIZE && colA>=0)){
				colA++;
				count++;

				//return true;
			}
			if(count >=1 && count < SIZE && board[rowA][colA] == disc){
				//printf("here4");
				return true;
			}

		}
		rowA = row;
		colA = col;
		count = 0;


		if(opponent == move5){
			rowA++;
			colA--;
			while(board[rowA][colA] !=  disc && board[rowA][colA] != EMPTY && (rowA <=SIZE && rowA >= 0) && (colA <= SIZE && colA>=0)){
				rowA++;
				colA--;
				count++;

				//return true;
			}
			if(count >=1 && count < SIZE && board[rowA][colA] == disc){
				//printf("here5");
				return true;
			}

		}
		rowA = row;
		colA = col;
		count = 0;

		if(opponent == move6){
			rowA++;
			while(board[rowA][colA] !=  disc && board[rowA][colA] != EMPTY && (rowA <=SIZE && rowA >= 0) && (colA <= SIZE && colA>=0)){
				rowA++;
				count++;

				//return true;
			}
			if(count >=1 && count < SIZE && board[rowA][colA] == disc){
				//printf("here6");
				return true;
			}

		}
		rowA = row;
		colA = col;
		count = 0;

		if(opponent == move7){
			rowA++;
			colA++;
			while(board[rowA][colA] !=  disc && board[rowA][colA] != EMPTY && (rowA <=SIZE && rowA >= 0) && (colA <= SIZE && colA>=0)){
				rowA++;
				colA++;
				count++;

				//return true;
			}
			if(count >=1 && count < SIZE && board[rowA][colA] == disc){
				//printf("here7");
				return true;
			}

		}
		rowA = row;
		colA = col;
		count = 0;
	}
	//other return false
	return false;	
}

/*****************************************************************
 * Places the disc at location row,col and flips the opponent 
 * discs as needed
 *
 * @param board to place disc on
 * @param which row
 * @param which column
 * @param which disc we are on
 * @throws check bounds in order to continue placement
 *****************************************************************/
void placeDiscAt(char board[][SIZE], int row, int col, char disc)
{
	// 012
	// ---
	//3-B-4
	// ---
	// 567


	//int checkMark[SIZE][SIZE];

	//flag whether or not to keep searching through disc placement
	bool discCont = true;

	//keep up with opponent
	char opponent = ' ';

	//count through the size of direction, should not pass the board
	int count = 0;

	//printf("Player: %c\n", disc);
	//choose which character to be using
	if(disc == WHITE){
		opponent = BLACK;
	}

	else{
		opponent = WHITE;
	}
	//since wasn't able to check valid move each time had to repeat logic in this function
	//bool valid = isValidMove(board, row, col, disc);
	//for(int i = 0; i < SIZE; i++){
	//for(int j = 0; j < SIZE; j++){

	//adjust row and col
	int rowA = row, colA = col;

	//place eight different ways to place disc	
	char move0 = board[rowA-1][colA-1];
	char move1 = board[rowA-1][colA];
	char move2 = board[rowA-1][colA+1];
	char move3 = board[rowA][colA-1];	
	char move4 = board[rowA][colA+1];
	char move5 = board[rowA+1][colA-1];
	char move6 = board[rowA+1][colA];
	char move7 = board[rowA+1][colA+1];

	//keep up with what I am looking at
	//printf("%c", move0);
	//printf("%c", move1);
	//printf("%c\n", move2);
	//printf("%c", move3);
	//printf("%c", board[row][col]);
	//printf("%c\n", move4);
	//printf("%c", move5);
	//printf("%c", move6);
	//printf("%c\n", move7);


	//check valid, check which move, then recurse
	//if(valid){
	//printf("Opposing: %c\n",opponent); 
	//switch(opponent){
	//check bounds to see if to continue
	if(row < 0 || col < 0){  
		exit(-1);
	}
	// 012
	// []--
	//3-B-4 //highlighted what to look at with brackets
	// ---
	// 567
	//repeated valid function here since we can't check multiple moves
	if (opponent ==  move0){
		rowA--;
		colA--;
		//continue while board is not on current player and not empty
		while(board[rowA][colA] !=  disc && board[rowA][colA] != EMPTY && (rowA <=SIZE && rowA >= 0) && (colA <= SIZE && colA>=0)){
			rowA--;
			colA--;
			count++;

		}
		//printf("%d\n", count);
		//printf("%c, row: %d, col: %d \n" , board[rowA][colA], rowA+1, colA);
		//if not able to find that disc is same as the board location discontinue!
		if(!(count >=1 && count < SIZE && board[rowA][colA] == disc)){

			discCont = false;
		}

		//return value
		rowA = row;
		colA = col;
		count = 0;

		//if moves were valid now start placing
		//this is good for checking multiple directions
		if(discCont){
			while(board[rowA-1][colA-1] != disc && (rowA <=SIZE && rowA >= 0) && (colA <= SIZE && colA>=0)){


				rowA--;
				colA--;
				//adjust board after moving from initial position
				board[rowA][colA] = disc;

				move0 = board[rowA][colA-1];
				//if(board[rowA-2][colA-2] != disc){
				//	break;
				//}
				//printf("yes0\n");
				count++;				
			}

			//return values to check another direction
			//printf("Row: %d, Col: %d\n", rowA, colA);
		}

		//return to continue for next direction
		else {
			discCont = true;
		}
	}
	//}
	// 012
	// -[]-
	//3-B-4
	// ---
	// 567

	if (opponent ==  move1){
		rowA--;
		while(board[rowA][colA] !=  disc && board[rowA][colA] != EMPTY && (rowA <=SIZE && rowA >= 0) && (colA <= SIZE && colA>=0)){
			rowA--;
			count++;

		}
		//printf("%d\n", count);
		//printf("%c, row: %d, col: %d \n" , board[rowA][colA], rowA+1, colA);
		if(!(count >=1 && count < SIZE && board[rowA][colA] == disc)){

			discCont = false;
		}


		rowA = row;
		colA = col;

		count = 0;
		if(discCont){

			//printf("%d\n", count);
			//printf("%c, row: %d, col: %d \n" , board[rowA][colA], rowA+1, colA+1);

			while(board[rowA-1][colA] != disc && (rowA <=SIZE && rowA >= 0) && (colA <= SIZE && colA>=0)){
				//printf("Yes\n");

				rowA--;
				board[rowA][colA] = disc;

				//printf("yes1\n");
				count++;				
			}

		}
		else {
			discCont = true;
		}


	}

	// 012
	// --[]
	//3-B-4
	// ---
	// 567

	if (opponent ==  move2){
		rowA--;
		colA++;
		while(board[rowA][colA] !=  disc && board[rowA][colA] != EMPTY && (rowA <=SIZE && rowA >= 0) && (colA <= SIZE && colA>=0)){
			rowA--;
			colA++;
			count++;

		}
		if(!(count >=1 && count < SIZE && board[rowA][colA] == disc)){

			discCont = false;
		}


		rowA = row;
		colA = col;
		count = 0;
		if(discCont){

			while(board[rowA-1][colA+1] != disc && (rowA <=SIZE && rowA >= 0) && (colA <= SIZE && colA>=0)){
				rowA--;
				colA++;
				board[rowA][colA] = disc;
				//displayBoard(board);
				//printf("Position: %c\n", board[rowA][colA]);
				//printf("yes2\n");
				count++;				
			}

		}
		else {
			discCont = true;
		}

	}
	//}
	// 012
	// ---
	//3[]B-4
	// ---
	// 567

	if (opponent ==  move3 ){
		colA--;
		while(board[rowA][colA] !=  disc && board[rowA][colA] != EMPTY && (rowA <=SIZE && rowA >= 0) && (colA <= SIZE && colA>=0)){
			colA--;
			count++;

		}
		if(!(count >=1 && count < SIZE && board[rowA][colA] == disc)){

			discCont = false;
		}


		rowA = row;
		colA = col;

		count = 0;
		if(discCont){

			while(board[rowA][colA-1] != disc && (rowA <=SIZE && rowA >= 0) && (colA <= SIZE && colA>=0)){
				//printf("%d\n", count);
				//printf("%c, row: %d, col: %d \n" , board[rowA][colA], rowA+1, colA+1);


				colA--;
				board[rowA][colA] = disc;
				//printf("Position: %c\n", board[rowA][colA]);
				//printf("yes3\n");
				count++;
				//printf("%d\n", count);
				//printf("%c, row: %d, col: %d \n" , board[rowA][colA], rowA+1, colA+1);

			}
		}

		else {
			discCont = true;
		}

	}

	//}
	// 012
	// ---
	//3-B[]4
	// ---
	// 567

	if (opponent ==  move4){
		colA++;
		while(board[rowA][colA] !=  disc && board[rowA][colA] != EMPTY && (rowA <=SIZE && rowA >= 0) && (colA <= SIZE && colA>=0)){
			colA++;
			count++;

		}
		if(!(count >=1 && count < SIZE && board[rowA][colA] == disc)){

			discCont = false;
		}


		rowA = row;
		colA = col;

		count = 0;
		if(discCont){

			while(board[rowA][colA+1] != disc && (rowA <=SIZE && rowA >= 0) && (colA <= SIZE && colA>=0)){

				colA++;
				board[rowA][colA] = disc;

				move4 = board[rowA][colA+1];
				//printf("yes4\n");				
				count++;
			}
		}
		else {
			discCont = true;
		}

	}
	//}
	// 012
	// ---
	//3-B-4
	// []--
	// 567

	if (opponent ==  move5){
		rowA++;
		colA--;
		while(board[rowA][colA] !=  disc && board[rowA][colA] != EMPTY && (rowA <=SIZE && rowA >= 0) && (colA <= SIZE && colA>=0)){
			rowA++;
			colA--;
			count++;

		}
		if(!(count >=1 && count < SIZE && board[rowA][colA] == disc)){

			discCont = false;
		}


		rowA = row;
		colA = col;

		count = 0;
		if(discCont){

			while(board[rowA+1][colA-1] != disc && (rowA <=SIZE && rowA >= 0) && (colA <= SIZE && colA>=0)){
				rowA++;
				colA--;
				board[rowA][colA] = disc;


				move5 = board[rowA+1][colA-1];
				//printf("yes5\n");
				count++;				
			}
		}
		else {
			discCont = true;
		}

	}

	//}

	//if(valid){
	// 012
	// ---
	//3-B-4
	// -[]-
	// 567

if (opponent ==  move6){
	rowA++;
	while(board[rowA][colA] !=  disc && board[rowA][colA] != EMPTY && (rowA <=SIZE && rowA >= 0) && (colA <= SIZE && colA>=0)){
		rowA++;
		count++;

	}
	if(!(count >=1 && count < SIZE && board[rowA][colA] == disc)){

		discCont = false;
	}


	rowA = row;
	colA = col;

	count = 0;
	if(discCont){

		while(board[rowA+1][colA] != disc && (rowA <=SIZE && rowA >= 0) && (colA <= SIZE && colA>=0)){

			rowA++;
			board[rowA][colA] = disc;
			move6 = board[rowA+1][colA];
			//if(board[rowA][colA+2] != disc){
			//	break;
			//}
			//printf("yes6\n");
			count++;
		}
	}
	else {
		discCont = true;
	}

}
//}

//if(valid){
// 012
// ---
//3-B-4
// --[]
// 567

if (opponent ==  move7){
	rowA++;
	colA++;
	while(board[rowA][colA] !=  disc && board[rowA][colA] != EMPTY && (rowA <=SIZE && rowA >= 0) && (colA <= SIZE && colA>=0)){
		rowA++;
		colA++;
		count++;

	}
	if(!(count >=1 && count < SIZE && board[rowA][colA] == disc)){

		discCont = false;
	}


	rowA = row;
	colA = col;

	count = 0;
	if(discCont){

		while(board[rowA+1][colA+1] != disc && (rowA <=SIZE && rowA >= 0) && (colA <= SIZE && colA>=0)){
			rowA++;
			colA++;
			board[rowA][colA] = disc;

			move7 = board[rowA+1][colA+1];
			//printf("yes7\n");		
			count++;		
		}

	}


	else {
		discCont = true;
	}


}	
if(discCont){
	board[row][col] = disc;
}
}

/*********************************************************************
 *  Returns true if a valid move for disc is available; else returns 
 *  false
 *
 * @param board to check if move is possible
 * @param which player BLACK or WHITE
 * @return 0 or 1 if valid
 *  ******************************************************************/
bool isValidMoveAvailable(char board[][SIZE], char disc)
{
	int count =0;
	//loop through the function isValidMove
	//to see all decisions.
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			if(isValidMove(board,i,j,disc)){
				return true;
			}
			else if(!(isValidMove(board,i,j,disc))){
				//printf("%c\n", board[i][j]);
				//printf("Row: %d Col: %d\n", i+1,j+1);
				count++;
			}
		}
	}

	//board full would mean no moves available
	if(isBoardFull(board)){
		return false;
	}


	return false;	
}

/*****************************************************************************
 *  Returns true if the board is fully occupied with discs; else returns false
 *
 * @param board to check if board is full
 * @return 0 or 1 of completeness
 *  **************************************************************************/
bool isBoardFull(char board[][SIZE])
{
	//loop through 2x2 array to check for an empty tile
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			if(board[i][j] == EMPTY){
				return false;	

			}
		}
	}
	return true; //when going through the whole board is filled
}

/*****************************************************************************
 * Returns true if either the board is full or a valid move is not available
 * for either disc
 * 
 * @param board to check for game status
 * @return 0 or 1 of status
 * ***************************************************************************/
bool isGameOver(char board[][SIZE])
{
	//board is full then is true
	if(isBoardFull(board)){

		return true;
	}
	//neither player can move
	else if(!(isValidMoveAvailable(board, BLACK)) && !(isValidMoveAvailable(board, WHITE))){
		return true;
	}	
	return false;	
}

/**************************************************************************************** 
 * If there is a winner, it returns the disc (BLACK or WHITE) associated with the winner.
 * In case of a tie, it returns EMPTY
 *
 * @param board to check who is winner
 * @return tell main program the char of the disc
 ****************************************************************************************/
char checkWinner(char board[][SIZE])
{
	//keep count of both black and white disc
	int countB = 0;
	int countW = 0;

	//count through each cell
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			//count black
			if (board[i][j] == BLACK){
				countB++;
			}

			//count white
			if( board[i][j] == WHITE){
				countW++;
			}
		} //second loop 
	}//first loop
	//check for a valid rules of the game then loop
	if(isBoardFull(board) || (!(isValidMoveAvailable(board, BLACK)) && !(isValidMoveAvailable(board, WHITE)))){

		//black wins
		if(countB > countW){
			return BLACK;
		}

		//white wins
		else if(countW > countB){
			return WHITE;
		}

		//no winner
		else{
			return EMPTY;	
		}

	}

	return EMPTY;
}

