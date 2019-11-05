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
void	free_list(t_tetr *t);
t_tetr	*make_tetr(char *buf, char let);
void	tetr_list(char *buf, t_tetr **t, char let);
t_tetr	*read_file(char *file);
void	err_tetr(t_tetr *t, int i);

#endif
