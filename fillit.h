/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <videloff@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/19 14:04:05 by yalabidi     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 16:32:23 by videloff    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"

typedef	struct		s_pnt
{
	int				x;
	int				y;
}					t_pnt;

typedef struct		t_list
{
	void			*content;
	struct t_list	*next;
	struct t_list	*prev;
}					t_lst;

void				error(void);
void				usage(void);
int					ft_readnstock(int fd);
int					check_sizenchar(char *grid[5]);
int					get_index(char *tab[5]);
int					comp_tab(int i, t_pnt *piece);
int					check_line(char *line);

#endif
