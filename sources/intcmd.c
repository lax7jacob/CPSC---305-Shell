#include "shell.h"

//cd unix - change directory 
int cd(char **args){
	int i;
	if(args[1] != NULL){
	 i = chdir(args[1]);
	}
	if(i < 0){

		perror("No such directory");

	}
	
	return 1;

}

///make directory 
int sh_mkdir(char **args, int size){
   int b;
   for(int i = 1; i <= size; i++){
   	if(args[i] != NULL){
   	 	b = mkdir(args[i], 0700);
  	 }
   }
    if(b == -1){
     perror("Unable to create directory");
    }
return 1;
}

//parent working directory
int pwd(char **args){

    char *buff;
    buff = getcwd(NULL, 0);
    fprintf(stdout, "%s\n", buff);
    fflush(stdout);
    free(buff);
    return 1;
}

//exit 
int sh_exit(char **args){

 exit(0);

}

//calls all the internal commands if the argument matches with any
int int_cmd(char **args){
    int size = 0;
    int i = 0;
    while(args[i] != NULL){
        size = size+1;
          i++;
        }
  if(size == 1){
  	if(strcmp(args[0],"pwd") == 0){
        	   pwd(args);
	  	   return 0;

 	 }
  
  	if(strcmp(args[0], "exit") == 0){

        	  sh_exit(args);
		  return 0;
 	 }
  }else if(size == 2){
         if(strcmp(args[0],"cd") == 0){
                   cd(args);
                   return 0;

         }
  
        if(strcmp(args[0], "mkdir") == 0){

                sh_mkdir(args, size);
                return 0;
         }
  }else if(size > 2){

        if(strcmp(args[0], "mkdir") == 0){

                sh_mkdir(args, size);
                return 0;
         }
  }

  return 1;
}

