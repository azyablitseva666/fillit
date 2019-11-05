//
// Created by Julius Brigette on 24/10/2019.
//
#include "header.h"

int	check_two(char *buf, int i)
{
	int count;

	count = 0;
	if (i > 19)
		return (0);
	if (buf[i]  == '#')
	{
		if (i > 0 && buf[i - 1] == '#')
			count++;
		if (i < 19 && buf[i + 1] == '#')
			count++;
		if (i > 4 && buf[i - 5] == '#')
			count++;
		if (i < 14 && buf[i + 5] == '#')
			count++;
	}
	return (count + check_two(buf, i + 1));
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
		if (buf[i++] == '#')
			tmp = (++s_hash == 1 ? s_hash : tmp);
	}
	if (i >= 20 && s_hash == 4 && (fl = check_two(buf, tmp)) && (fl == 6 || fl == 8))
		return (1);
	return (0);
}

