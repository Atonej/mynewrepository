#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include "file_utils.h"

/***********************************************************
 * This c file will implement the files from it's h file and
 * allow for the reading and writing of a file
 *
 * @author Atone Joryman
 * @version Fall 2018
 * ********************************************************/


FILE *fin, *fout;

/***********************************************************
 * Read in a file 
 *
 * @param what is the name of the file
 * @param buffer for the temporary storage space
 * @return whether or not action could complete
 **********************************************************/
int read_file( char* filename, char **buffer ){

	//Grand Valley Professor Woodring gave this code
	//this is to tell the size to the file
	struct stat st;
	stat(filename, &st);
	int size = st.st_size;

	// attempts to read the filename passed into it
	fin = fopen(filename, "r");

	//returns error code -1 if open was not successful and prints error message
	if(!fin){
	  fprintf(stderr, "Cannot Open File \n");
	return -1;	
	}

	size_t s = 0;
	//get char from file
	int i = fgetc(fin);
	//temporary string to hold characters from file
	char* endS;
	//allocate memory to tempString
	endS = (char*)malloc(size*sizeof(char));
	//read character in until reaching the end
	while (i != EOF){
		endS[s++] = (char) i;
	}
	//at end null character 
	endS[s] = '\0';

	//exploiting buffer to string copy, a way to post it
	//https://shankaraman.wordpress.com/tag/how-to-exploit-strcpy/
	strcpy(*buffer, endS);


	//deallocate memory
	free(endS);

	//close the file
	fclose(fin);
	
	return 0;






}
/***********************************************************
 * Write to a file 
 *
 * @param what is the name of the file
 * @param buffer for the temporary storage space
 * @param give the size of the file
 * @return whether or not action could complete
 **********************************************************/

int write_file( char* filename, char * buffer, int size){
 	
	//create file 
	fout = fopen(filename, "w");

	//through the iteration of the buffer check those char
	for(int i = size - 2; i >= 0;  i--){
		//cast to an integer
	  fputc((int) buffer[i], fout);
	}

	//close
	fclose(fout);

	return 0;

}
