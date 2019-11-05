#include "header.h"

void	err_tetr(t_tetr *t, int i)
{
	if (i == 0)
		write (1, ERR_US, 28);
	else
		write (1, ERR_W, 6);
	free_list(t);
	exit(1);
}