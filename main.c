#include "header.h"

int main(int argc, char **argv)
{
	t_tetr	*t;
	t_tetr	*tmp;

	if (argc != 2)
		err_tetr(t, 0);
	t = read_file(argv[1]);
	tmp = t;
//	while (t)
//	{
//		write(1, &t->let, 1);
//		t = t->next;
	//if (read_file(t, argv[1]))
	//	READ;
	//	PRINT;
	//	FREE;
//	}
//	free_list(tmp);
	return (0);
}