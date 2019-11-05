//
// Created by Julius Brigette on 26/10/2019.
//
#include "header.h"

void		free_list(t_tetr *t)
{
	t_tetr *tmp;

	while (tmp)
	{
		tmp = t;
		t = t->next;
		free(tmp);
	}
}

t_tetr	*make_tetr(char *buf, char let)
{
	t_tetr	*t;
	int		x;
	int		y;
	int		i;

//	let = (!let ? 'A' : let++);
	if (!(t = (t_tetr*)malloc(sizeof(t_tetr))))
		return (NULL);
	x = 0;
	y = 1;
	i = 0;
	while (i < 20)
	{
		if (buf[i] == '#') {
			t->coord[x] = i % 5;
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
		while (cur)
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
		printf("%s", buf);
		if (ret >= 20 && check_one(buf))
			tetr_list(buf, &first, let);
		else
			err_tetr(first, 1);
		let++;
	}
	if ((ret <= 0) && (prev == 21 || !prev))
		err_tetr(first, 1);
	return (first);
}