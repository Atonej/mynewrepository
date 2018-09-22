//#include <stdio.h>
//#include <stdlib.h>

#ifndef HEADERGUARD_H
#define HEADERGUARD_H

/***********************************************************
 * This h file will implement the files from it's h file and
 * allow for the reading and writing of a file
 *
 * @author Atone Joryman
 * @version Fall 2018
 * ********************************************************/

/***********************************************************
 * Read in a file 
 *
 * @param what is the name of the file
 * @param buffer for the temporary storage space
 * @return whether or not action could complete
 **********************************************************/
int read_file( char* filename, char **buffer );

/***********************************************************
 * Write to a file 
 *
 * @param what is the name of the file
 * @param buffer for the temporary storage space
 * @param give the size of the file
 * @return whether or not action could complete
 **********************************************************/
int write_file( char* filename, char *buffer, int size);



#endif

