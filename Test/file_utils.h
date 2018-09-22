#ifndef FILE_UTILS_H 
#define FILE_UTILS_H

/************************************************************
* read_file 
* ---------
* takes all characters from filename and loads them into
 	memory.
* char* filename - name of file to read
* char **buffer - portion of memory to store file content 
************************************************************/
int read_file(char* filename, char **buffer);


/************************************************************
* write_file 
* ---------
* takes all chars from a buffer and writes them to a file
* char* filename - name of file to write to
* char *buffer - portion of memory where file content is
	stored
* int size - size of the buffer (in bytes)
************************************************************/
int write_file(char* filename, char *buffer, int size);

#endif //FILE_UTILS_H