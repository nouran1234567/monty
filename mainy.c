#include <monty.h>

int main(int argc, char **argv)
{
	
	char *liny = NULL;
	ssize_t ready;
	size_t leny = 0;
	FILE *fily;
	unsigned int line_nmbr = 0;
	stack_t *stacky = NULL;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s monty_file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	fily = fopen(argv[1], "r");
	if (fily == NULL) {
		fprintf(stderr, "Error opening file: %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((ready = getline(&liny, &leny, fily)) != -1) 
	{
		line_nmbr++;

		parse_line(liny, line_nmbr, &stacky);
	}

	free_stacky(&stacky);
	
	return 0;
}
