#include "shell.h"

//reads the line from the shell 
char *read_line(void)
{
    int bufsize = LSH_RL_BUFSIZE;
    int position = 0; 
    int c;
    char *buffer = malloc(sizeof(char) *bufsize);

    if (!buffer)
    {
        fprintf(stderr, "ve482sh: Allocation error\n");
        return NULL;
    }

    while (1)
    {
        c = getchar();
        switch (c)
        {
        case '\n':
                buffer[position] = '\0';
                return buffer;
        case EOF:
            if (position == 0)
            {
                free(buffer);
                fprintf(stdout, "\n");
                fflush(stdout);
                exit(EXIT_SUCCESS);
            }
            position--;
            break;
        default:
            buffer[position] = c;
        }
        position++;
        if (position >= bufsize)
        {
            fprintf(stderr, "ve482sh: Command line length exceeds\n");
            exit(EXIT_FAILURE);
        }
    }
}

//splits the line depending on the delim
char **parse_line(char *line)

{
    int bufsize = LSH_TOK_BUFSIZE, position = 0;
    char **tokens = (char**) malloc(bufsize * sizeof(char *));
    char *token;
    char *delim;

    if (!tokens)
    {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    if( strchr(line, '|') != NULL){
	    delim = "|";

    }else if( strchr(line, '>')  != NULL){
         delim = ">";
     }else if(strchr(line, '<')  != NULL){
	    delim = "<";
    }else {

	delim = " \t\r\n\a";
    }

    token = strtok(line, delim);
    while (token != NULL)
    {
        tokens[position] = token;
        position++;

        if (position >= bufsize)
        {
		bufsize += LSH_TOK_BUFSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      	if (!tokens) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
        }
	}

        token = strtok(NULL, delim);
    }
    tokens[position] = NULL;
    return tokens;
}
  
