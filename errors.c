#include "header.h"

void	err_tetr(t_tetr **t, int i)
{
	if (i == 0)
		write (1, ERR_US, 28);
	else
		write (1, ERR_W, 6);
	free_list(t);
	exit(1);
}

void    free_tetr(t_tetr **t)
{
    if (t && *t)
    {
        free(*t);
        *t = NULL;
    }
}

void	free_list(t_tetr  **t)
{
    t_tetr *tmp;
    t_tetr *f;

    if (t)
    {
        f = *t;
        while (f)
        {
            tmp = f->next;
            free_tetr(&f);
            f = tmp;

        }
        *t = NULL;
    }
}