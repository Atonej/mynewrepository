#include "file_utils.h"
#include <sys/stat.h>
#include <stdio.h>

/*******************************************
 * Main class to call to those read and 
 * write function. Which will cause to write
 * in backwards
 * 
 * @author Atone Joryman
 * @version Fall 2018
 * ****************************************/
int main(int argc, char** argv){
	
	//read in and write in
	FILE *fin, *fout;

//	struct stat st;
//	stat(filename, &st);
//	int size = st.st_size;

  //for char
  int count = 0;

  int i = 0;
  
  fin  = fopen(argv[1], "r");
  fout = fopen(argv[2], "w");

  if(argc != 3){
	fprintf(stderr, "Command Line Must Have 2 Arguments");
  }

  if (!fin) {
    fprintf(stderr, "Cannot Open File");
    return -1;
  }

  // Move the file pointer to the end 
  // seek for the last byte in the file
  fseek(fin, 0, SEEK_END);
  // Get the position at the end
  // man page ftell
  count = ftell(fin);

  //loop through the count of the file, increment after each check
  while (i++ < count) {
    // Go backwards from the end character and write each one to the new file
    fseek(fin, -i, SEEK_END);
    fprintf(fout, "%c", fgetc(fin));

    }

  // Close the files
  fclose(fin);

  fclose(fout);
  
  return 0;

}
