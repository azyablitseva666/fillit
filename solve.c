//
// Created by Julius Brigette on 06/11/2019.
//

#include "header.h"

int size_map(int n)
{
    int ms;

    ms = 2;
    while (ms * ms < n)
        ms++;
    return (ms);
}

int count_tetr(t_tetr *t)
{
    int count;

    count = 0;
    while (t)
    {
        count++;
        t = t->next;
    }
    return (count);
}

t_map   *make_map(int m_size)
{
    t_map   *m;
    int     i;

    m = (t_map *)ft_memalloc(sizeof(t_map));
    m->map = (char**)ft_memalloc(sizeof(char*) * m_size);
    i = 0;
    while (i < m_size)
    {
        m->map[i] = ft_strnew(m_size);
        ft_memset(m->map[i], '.', m_size);
        i++;
    }
    return (m);
}

void	print_map(t_map *m, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        printf("%s\n", m->map[i]);
       // write(1, &m->map[i], size);
        //write (1, "\n", 1);
        i++;
    }
}

void	free_map(t_map *m, int m_size)
{
    int i;

    i = 0;
    while (i < m_size)
    {
        ft_memdel((void **)&(m->map[i]));
        i++;
    }
    ft_memdel((void **)&(m->map));
    ft_memdel((void **)&m);
}