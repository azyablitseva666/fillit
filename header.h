//
// Created by Julius Brigette on 17/10/2019.
//

#ifndef HEADER_H
# define HEADER_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# define ERR_US "usage: ./fillit source_file\n"
# define ERR_W "error\n"

typedef struct		s_tetr
{
	int				x;
	int				y;
	int				coord[8];
	struct s_tetr	*next;
	char 			let;
}					t_tetr;

typedef struct		s_map
{
	char			**map;
}					t_map;

int		check_two(char *buf, int i);
int		check_one(char *buf);
int     check_borders(int m_size, t_tetr *t, char n);
int     check_overlap(t_map *m, t_tetr *t);
void    free_tetr(t_tetr **t);
void	free_list(t_tetr **t);
t_tetr	*make_tetr(char *buf, char let);
void	tetr_list(char *buf, t_tetr **t, char let);
t_tetr	*read_file(char *file);
void	err_tetr(t_tetr **t, int i);
int     size_map(int n);
int     count_tetr(t_tetr *t);
void	landing_y(t_tetr *t, int n);
void    landing_x(t_tetr *t, int n);
void    landing(t_tetr *t);
void	ft_memdel(void **ap);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strnew(size_t size);
void	*ft_memalloc(size_t size);
void	ft_bzero(void *s, size_t n);
t_map   *make_map(int m_size);
void	print_map(t_map *m, int size);
void	free_map(t_map *m, int m_size);
void    paste_tetr(t_tetr *t, char let, t_map *m);
int     is_solve(t_map *m, t_tetr *t, int m_size);
void	solve_map(t_tetr *t);

#endif
