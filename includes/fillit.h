/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <videloff@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/19 14:04:05 by yalabidi     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/22 17:23:36 by videloff    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "global.h"

# define INDEX g_pcs[pc->pt]

typedef struct		s_tlist
{
	int				pt;
	struct s_tlist	*next;
}					t_lst;

void				error(void);
void				usage(void);
int					ft_readnstock(int fd);
int					check_sizenchar(char *grid[5]);
int					get_index(char *tab[5]);
int					comp_tab(int i, t_pnt *piece);
int					check_line(char *line);
t_lst				*listing(int *tab, int size);
char				**malloc_board(int size);
void				display_board(char **board);
char				**resolver(t_lst *lst, int *size, char **board, char c);
char				**extend_board_size(char **board, int size);
void				free_board(char **board, int size);
void				free_list(t_lst *lst);
void				error_free(char *tab[5]);
void				init_grid(char *grid[5]);

#endif
