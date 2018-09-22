#include <stdio.h>
#include <sys/stat.h>

int read_file(char* filename, char **buffer){
	
	//open file
	FILE *fp;
	fp = fopen(filename,"r");
	
	//does it exist?
	if(fp  == NULL){
		fprintf(stderr, "*FILE ERROR (read)*\n");
		return -1;
	}

	//get the size of the file
	struct stat st;
	stat(filename, &st);
	int size = st.st_size;

	//load file data into buffer memory 
	//(thanks to  http://www.cplusplus.com/reference/cstdio/fread/)
	size_t result;	
	result = fread(*buffer,sizeof(char),size,fp);
	
	//no errors? yay! :D
	return 0;
}


int write_file(char* filename, char *buffer, int size){
	
	//make the file
	FILE *fp;
	fp = fopen(filename,"w");

	//hopefully it exists, you just made it
	if(fp == NULL){
		fprintf(stderr, "*FILE ERROR (write)*\n");
       	return -1;
	}
	
	//slap the data in the buffer onto the file
	for(int i=0;i<size;i++){
		fputc(buffer[i],fp);
	}

	//no errors? yay! :D
	return 0;
}