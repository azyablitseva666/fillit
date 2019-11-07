//
// Created by Julius Brigette on 26/10/2019.
//
#include "header.h"

void	landing_x(t_tetr *t, int n)
{
	t->coord[0] += n;
	t->coord[2] += n;
	t->coord[4] += n;
	t->coord[6] += n;
}

void	landing_y(t_tetr *t, int n)
{
	t->coord[1] += n;
	t->coord[3] += n;
	t->coord[5] += n;
	t->coord[7] += n;
}

void    landing(t_tetr *t)
{
	while (t->coord[0] != 0 && \
			t->coord[2] != 0 && \
			t->coord[4] != 0 && \
			t->coord[6] != 0)
		landing_x(t, -1);
	while (t->coord[1] != 0 && \
			t->coord[3] != 0 && \
			t->coord[5] != 0 && \
			t->coord[7] != 0)
		landing_y(t, -1);
}

t_tetr	*make_tetr(char *buf, char let)
{
	t_tetr	*t;
	int		x;
	int		y;
	int		i;

	if (!(t = (t_tetr*)malloc(sizeof(t_tetr))))
		return (NULL);
	x = 0;
	y = 1;
	i = 0;
	while (i < 20)
	{
		if (buf[i] == '#') {
			t->coord[x] = (i >= 5) ? (i % 5) : i;
			t->coord[y] = i / 5;
			x += 2;
			y += 2;
		}
		i++;
	}
	t->x = 0;
	t->y = 0;
	t->let = let;
	t->next = NULL;
	landing(t);
	return (t);
}

void	tetr_list(char *buf, t_tetr **t, char let)
{
	t_tetr		*cur;
	int			i;

	if (!buf)
		return ;
	if (!(*t))
		*t = make_tetr(buf, let);
	else
	{
		cur = *t;
		while (cur->next)
			cur = cur->next;
		cur->next = make_tetr(buf, let);
	}
}

t_tetr *read_file(char *file)
{
	int		fd;
	int		ret;
	int		prev;
	char	buf[22];
	t_tetr	*first;
	char	let;

	ret = 0;
	let = 'A';
	first = NULL;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	while ((ret = read(fd, buf, 21)) > 0)
	{
		prev = ret;
		buf[ret] = '\0';
		if (ret >= 20 && check_one(buf))
			tetr_list(buf, &first, let);
		else
			err_tetr(&first, 1);
		let++;
	}
	if ((ret <= 0) && (prev == 21 || !prev))
		err_tetr(&first, 1);
	return (first);
}