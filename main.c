#include "shell.h"
#include <stdbool.h>

int main()
{
        char *line;
	char **args, **new , **new2;
	int status = 1;
	int numpipe, num, num2, l;
	int check = 0;
	signal(SIGINT, signal_handler);
	while(status){
	  prompt();
	  line = read_line();
          int pipe  = strchr(line, '|') != NULL;
	  int out = strchr(line , '>') != NULL;
	  int in = strchr(line, '<') != NULL;
	  args = parse_line(line);
	  int s = size(args);
	  if(args[0] != 0){
           //redirection 
           if(!strcmp(args[s-1], "&" )){
			check = 1;
			bg_process(args);
	   }
	   // runs "<"
            if(in == 1){

                for(int i = 0; args[i] != NULL; i++){
                  num2 = i-1;
                }
                if(num2 == 0){
                                new = parse_line(args[1]);
                                new2 = parse_line(args[0]);
                                file_out(new , new2);
                          }
                 }

	    //runs ">"
	    if(out == 1){		  
		for(int i = 0; args[i] != NULL; i++){
                  num = i-1;
                }
                if(num == 0){
                                 new = parse_line(args[1]);
				 new2 = parse_line(args[0]);
				file_in(new , new2);
                          }
	         }

	  if( (pipe == 0) & (out == 0) & (in == 0) & (check == 0)){
          //executes internal command 
	  int cmd = int_cmd(args);
	  //if none executed then runs extcmd
          if( cmd == 1){
            l = ext_cmd(args);
	  }
          //executes list (;) commands 
          if(l == -1){
	  for(int i = 0; i <= args[i]; i++){
		  
          	char *token = strtok(args[i], ";");
		while(token != NULL) {
			int pid = fork();
			if(pid == 0){

	                if(execlp(strdup(token), token,  NULL)==-1){
				
				printf("Command not found\n");
	
				
			}
			}else{

    				         wait(NULL);
    			}

			
        	   token = strtok(NULL, ";");
		}
		}

	  l = 0;
	  }
	  //executes pipe | commands
	  }else if( pipe == 1){
		for(int i = 0; args[i] != NULL; i++){
		  numpipe = i-1;
		}
		if(numpipe == 0){
   			 new = parse_line(args[0]);
			 new2 = parse_line(args[1]);
		         pipe_handler(new, new2);
			  }
						   

	  }
	  check = 0; 
          free(line);
	  free(args);

    
	  }
   }

   return EXIT_SUCCESS;

}

