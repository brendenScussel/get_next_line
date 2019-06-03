#include "get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i = 0;

	printf("_____________________\n");
	if (argc || argv)
		;
	fd = open(argv[1], O_RDONLY);
	while ((i = get_next_line(fd, &line)) == 1)
	{
		printf("[%d] reading | \n", i);
		printf("%s\n", line);
	}
	if (i != 1)
	{
        if (i == 0)
			printf("[%d] done reading\n", i);
		else
			printf("[%d] ERROR\n", i);
		
	}
	close(fd);
	printf("_____________________\n");
	return (0);
}
