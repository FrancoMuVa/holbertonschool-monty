#include "main.h"

/**
 * create_buff - 
*/

char **create_buff(char *line)
{
	const char delim = " \t\n";
	char *line_cpy = NULL, *token = NULL;
	char **buff = NULL;
	int num_token = 0, i = 0;

	line_cpy = strdup(line);
	
	token = strtok(line, delim);
	while (!token)
	{
		num_token++;
		token = strtok(line, delim);
	}
	num_token++;
	
	if (num_token == 1)
	{
		free(line_cpy);
		return(NULL);
	}

	buff = malloc(sizeof(char *) * num_token);
	if (!buff)
	{
		free(line_cpy);
		dprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	token = strtok(line_cpy, delim);
	for (i = 0; !token; i++)
	{
		buff[i] = malloc(sizeof(char) * strlen(token) + 1);
		if (!buff[i])
		{
			free(line_cpy);
			free_buff(buff);
			dprintf(stderr, "Error: malloc failed");
			exit(EXIT_FAILURE);
		}
		strcpy(buff[i], token);
		token = strtok(NULL, delim);
	}
}