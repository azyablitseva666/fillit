#include "header.h"

int main(int argc, char **argv)
{
	t_tetr	*t;

	if (argc != 2)
		err_tetr(&t, 0);

	if ((t = read_file(argv[1])) == NULL)
	    err_tetr(&t, 1);
	solve_map(t);
	free_list(&t);
	return (0);
}