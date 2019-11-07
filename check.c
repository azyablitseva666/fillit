//
// Created by Julius Brigette on 24/10/2019.
//
#include "header.h"

int	check_two(char *buf, int i)
{
	int count;

	if (i == 19)
		return (0);
	count = 0;
	if (buf[i]  == '#')
	{
		if (i > 0 && buf[i - 1] == '#')
			count++;
		if (i < 19 && buf[i + 1] == '#')
			count++;
		if (i >= 5 && buf[i - 5] == '#')
			count++;
		if (i <= 14 && buf[i + 5] == '#')
			count++;
	}
	return (count + check_two(buf, ++i));
}

int check_one(char *buf)
{
	int i;
	int s_hash;
	int	tmp;
	int	fl;

	i = 0;
	s_hash = 0;
	while (buf[i] && (buf[i] == '#' || buf[i] == '.' || (buf[i] == '\n' && (i % 5 == 4 || i == 20))) && s_hash < 5)
	{
		if (buf[i] == '#')
			tmp = (++s_hash == 1 ? i : tmp);
		i++;
	}
	if (i >= 20 && !buf[i] && s_hash == 4 && (fl = check_two(buf, tmp)) &&(fl == 6 || fl == 8))
		return (1);
	return (0);
}

int     check_overlap(t_map *m, t_tetr *t)
{
    int x;
    int y;
    int i;

    i = 2;
    x = t->x + t->coord[0];
    y = t->y + t->coord[1];
    while (i < 7)
    {
        if (m->map[y][x] != '.')
            return (1);
        x = t->x + t->coord[i];
        y = t->y + t->coord[i + 1];
        i += 2;
    }
    return (0);
}

int     check_borders(int m_size, t_tetr *t, char n)
{
    int x;

    x = (n == 0 ? t->x : t->y);
    if (t->coord[0 + n] + x < m_size &&
        t->coord[2 + n] + x < m_size &&
        t->coord[4 + n] + x < m_size &&
        t->coord[6 + n] + x < m_size)
        return (1);
    return (0);
}