#include "life.h"
#include <stdio.h>
#include <stdlib.h>

/*******************************************************
* Given program to modify and complete. Responsible for
* implementation of Conway's Game of Life.
*
* @version Winter 2019
* @author Atone Joryman
*
*******************************************************/


/*******************************************************
 * get_grid creates new memory for a "grid".
 * x is the height and y is the width.
 *
 * @param x is the row of the grid
 * @param y is the col of the grid
 * @return give the current grid state
 ******************************************************/
char** get_grid(int x, int y){

	//allocating memory for total height
        // https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
	char** z = (char** )malloc(x * sizeof(char*));
	
	//now make an addition to width
	for(int i = 0; i < x; i++) {
		*(z+i) = (char* )malloc(y * sizeof(char));
	}
	
	return z;

}

/*********************************************
 * print_grid attempts to print an x height
 * by y width grid stored at the location
 * provided by grid
 *
 * @param x coordinates to print
 * @param y coordinates to print
 * @param grid connect and show all cells (2x2)
 * @throw if too big
 ********************************************/
void print_grid(int x, int y, char** grid){

if(x > 30 || y > 30){//cannot be bigger than 30x30 on terminal screen
	exit(-1);
}

for(int i = 0; i < x; i++) {
		for(int j = 0; j < y; j++) {
//used the help from Black Lapum and Cole Sellers group to get the context of pointing to an adujusted position of the grind.
//https://github.com/danielshamburger/game-of-life/blob/master/life.c
			//so, point to grid byte at this row position then to column position point to that (from inside -> out)
			// like looking at 2x2 arrays
			if(*(*(grid+i)+j) == 0) {
				//give dead cell
				//*(*(grid+i)+j) = '-';
				printf("___");
			}
			if(*(*(grid+i)+j) == 1) {
				//give alive cell
				//*(*(grid+i)+j) = 'O'; 
				printf(":-)");
			}
			
		}
		printf("\n"); 
	}
	printf("\n"); 
}

/*********************************************
 * mutate takes a grid and mutates that grid
 * according to Conway's rules.  A new grid
 * is returned.
 *
 * @param x coordinates of width
 * @param y coordinates of height
 * @param grid is the given board to look at
 * @return double array of a grid type char**
 ********************************************/
char** mutate(int x, int y, char** grid){
	//grid 2x2 array to mutate positions
	char** gridA = grid;
	//char** gridFlag = grid;
	char** gridFlag = get_grid(x,y);
	
	//count neighbors
	int neighbors = 0; 
	//row 
	for(int i = 0; i < x; i++) {
		//col
		for(int j = 0; j < y; j++) {
			//get the amount of neighbors at this position
			neighbors = get_neighbors(i, j, x, y, grid);
		       	//when the cell is alive	
			if(*(*(gridA+i)+j) == 1) {
				//printf("Row: %d Col: %d, you get %d \n", i+1, j+1, neighbors);

				// A live cell with less than two live neighbors dies 
				if(neighbors < 2) {
					//make dead
					*(*(gridFlag+i)+j) = 0;
				}
				//A live cell with two or three live neighbors lives 
				else if(neighbors == 2 || neighbors == 3) {
					//printf("yes\n");
					//keep alive
					*(*(gridFlag+i)+j) = 1;
					//printf("Row: %d Col: %d, you get %d \n", i+1, j+1, neighbors);

				}
				//A live cell with more than three neighbors dies 
				else if(neighbors > 3) {
					//make dead
					*(*(gridFlag+i)+j) = 0;
				}
			}
			//otherwise look when it is dead
			else{
				// A dead cell with three live neighbors becomes live
				if(neighbors == 3) {
					//make alive
					*(*(gridFlag+i)+j) = 1;
					//printf("%d \n", neighbors);
				}
			}
		//printf("GridA---->  \n");
		//print_grid(x,y,gridA);
		//printf("GridFlag----->   \n");
		//print_grid(x,y,gridFlag);

		}//second for loop


	}//first for loop

	//so now that they are flagged now change grid
	for(int i = 0; i < x; i++) {
		for(int j = 0; j < y; j++) {
			if(*(*(gridFlag+i)+j) == 1){
				*(*(gridA+i)+j) = 1;
			}

			else {
				*(*(gridA+i)+j) = 0;
			}
		}
	}


	return gridA;

}

/***************************************************
 * get_neighbors is a helper method that returns
 * the number of live neighbors a cell has.
 *
 * @param i coordinates of cell to look at
 * @param j coordinates of cell to look at
 * @param x grid width
 * @param y grid height
 * @return type int the count of the surrounding 
 * neighbors
 * @throws when out of bounds looking at coordinate
 **************************************************/
int get_neighbors(int i, int j, int x, int y, char** grid){

	//char move0 = grid[i-1][j-1];
	//char move1 = grid[i-1][j];
	//char move2 = grid[i-1][j+1];
	//char move3 = grid[i][j-1];
	//char move4 = grid[i][j+1];
	//char move5 = grid[i+1][j-1];
	//char move6 = grid[i+1][j];
	//char move7 = grid[i+1][j+1];


	//Way to look at neighbors
	// 0    1   2
	// ___ ___ ___
	//3___ :-) ___4 //'O' being the position of the value I am looking from.
	// ___ ___ ___
	//  5   6   7
	int count = 0;

	//error checking if search is out of bounds
	if(i > x || j > y || i < 0 || j < 0) {
		return -1; 
	}

	//move 0
	if(i > 0 && j > 0 && i < x && j < y) { //making sure i and j are in bounds, going this way it has to be greater than zero
		if(*(*(grid+i-1)+j-1) == 1) {
			count++; 
		}
	}

	//move 1
	if(i > 0 && j >= 0 && i <= x && j <= y) {
		if(*(*(grid+i-1)+j) == 1) {
			count++; 
		}
	}

	//move 2
	if(i > 0 && j >= 0 && i < x && j < (y-1)) { //minus 1 on y so it won't go out of bounds 
		if(*(*(grid+i-1)+j+1) == 1) {
			count++; 
		}
	}

	//move 3
	if(i >= 0 && j > 0 && i < x && j < y) { 
		if(*(*(grid+i)+j-1) == 1) {
			count++; 
		}
	}

	//move 4
	if(i >= 0 && j >= 0 && i < x && j < (y-1)){ 
		if(*(*(grid+i)+j+1) == 1) {
			count++; 
		}
	}

	//move 5
	if(i >= 0 && j > 0 && i < (x-1) && j < y) { //minus 1 on x so it won't go out of bounds
		if(*(*(grid+i+1)+j-1) == 1) {
			count++; 
		}
	}

	//move 6
	if(i >= 0 && j >= 0 && i < (x-1) && j < y) { 
		if(*(*(grid+i+1)+j) == 1) {
			count++; 
		}
	}

	//move 7
	if(i >= 0 && j >= 0 && i < (x-1) && j < (y-1)) {
		if(*(*(grid+i+1)+j+1) == 1) {
			count++; 
		}
	}

	return count;


}
