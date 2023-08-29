#include "main.h"

/**
 * main - get the inputs.
 * 
 */

int main (int argc, char **argv)
{
	FILE *file;
	char *line = NULL;
	ssize_t ch_read = 0;
	size_t in_size = 0;	

	file = fopen(argv[1], "r");
	if (!file)
	{
		dprintf(stderr, "error");
		exit(EXIT_FAILURE);
	}
	while(1)
	{
		ch_read = getline(&line, &in_size, file);
		if (ch_read == -1)
		{
			return (0);
		}
		create_buff(line);

	}

}