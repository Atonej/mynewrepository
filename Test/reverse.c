#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "file_utils.h"


int main(int argc, char** argv){
	
	char* readfile = argv[1];		//first argument (0 is exec. name)
	char* writefile = argv[2];		//second argument

	//get the size of the file
    struct stat st; 
    stat(readfile, &st);
    int size = st.st_size;
    
    //reserve memory for file contents
    char* fileMem = (char*)malloc(size * sizeof(char));

	//self-explanatory, more info in file_utils.h
	read_file(readfile, &fileMem);

	//reverse elements in the buffer,
	// swapping items outside working towards middle
	char temp;
	for(int i=0;i<(size/2);i++){
		temp = fileMem[i];		
		fileMem[i] = fileMem[size - i - 1]; 	//swap 'far' element into 'close'
		fileMem[size - i - 1] = temp;			//replace far with the old val of close
	}	


	//more info in file_utils.h
	write_file(writefile,fileMem,size);

}