//
// Created by Julius Brigette on 06/11/2019.
//

#include "header.h"

void    paste_tetr(t_tetr *t, char let, t_map *m)
{
    int x;
    int y;
    int i;

    i = 0;
    while (i < 7)
    {
        x = t->coord[i] + t->x;
        y = t->coord[i + 1] + t->y;
        m->map[y][x] = let;
        i += 2;
    }
}

int     is_solve(t_map *m, t_tetr *t, int m_size)
{
    if (!t)
        return (1);
    t->x = 0;
    t->y = 0;
    while (check_borders(m_size, t, 1))
    {
        while (check_borders(m_size, t, 0))
        {
            if (!check_overlap(m, t))
            {
                paste_tetr(t, t->let, m);
                if (is_solve(m, t->next, m_size))
                    return (1);
                paste_tetr(t, '.', m);
            }
            t->x++;
        }
        t->x = 0;
        t->y++;
    }
    return (0);
}
void	solve_map(t_tetr *t)
{
    t_map	*m;
    int		m_size;

    m_size = size_map(count_tetr(t) * 4);
    m = make_map(m_size);
    while (!is_solve(m, t, m_size))
    {
       free_map(m, m_size);
       m_size++;
       m = make_map(m_size);
    }
    print_map(m, m_size);
    free_map(m, m_size);
}
