/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_file.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <videloff@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/18 17:55:42 by yalabidi     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/22 17:26:06 by videloff    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		comp_tab(int i, t_pnt *piece)
{
	return ((g_pcs[i][0].x == piece[1].x - piece[0].x) && (g_pcs[i][0].y ==
		piece[1].y - piece[0].y) && (g_pcs[i][1].x == piece[2].x - piece[0].x)
		&& (g_pcs[i][1].y == piece[2].y - piece[0].y) && (g_pcs[i][2].x ==
		piece[3].x - piece[0].x) && (g_pcs[i][2].y == piece[3].y - piece[0].y));
}

int		get_index2(char **grid, t_pnt (*test)[4], int *x, int *i)
{
	int		y;

	y = -1;
	while (grid[++y])
	{
		while (grid[y][*x])
		{
			if (grid[y][*x] == '#')
			{
				if (*i >= 4)
					return (-1);
				(*test)[*i].x = *x;
				(*test)[*i].y = y;
				(*i)++;
			}
			(*x)++;
		}
		*x = 0;
	}
	if (*i < 4)
		return (-1);
	return (0);
}

int		get_index(char **grid)
{
	int		i;
	int		x;
	int		res;
	t_pnt	test[4];

	i = 0;
	x = 0;
	res = -1;
	if (get_index2(grid, &test, &x, &i))
	{
		error_free(grid);
		return (-1);
	}
	if (i == 4)
	{
		i = 0;
		while (i == 0 && ++res <= 18)
			i = comp_tab(res, test);
		while (grid[x])
			free(grid[x++]);
		if (i != 0)
			return (res + 1);
	}
	return (-1);
}

int		check_sizenchar(char **grid)
{
	int	i;

	i = -1;
	while (grid[++i])
		if (check_line(grid[i]) == -1)
		{
			error_free(grid);
			return (-1);
		}
	if (i != 4)
	{
		error_free(grid);
		return (-1);
	}
	return (get_index(grid));
}

int		ft_readnstock(int fd)
{
	char	*line;
	char	*grid[5];
	int		i;
	int		j;
	int		tmp;

	j = 0;
	i = 0;
	init_grid(grid);
	while ((tmp = get_next_line(fd, &line)))
	{
		if (line[0] == '\0' && i == 4)
		{
			ft_memdel((void**)&line);
			break ;
		}
		line[0] == '\0' ? error_free(grid) : 0;
		grid[i++] = ft_strdup(line);
		ft_memdel((void**)&line);
	}
	if (i == 4)
		return (check_sizenchar(grid));
	if (tmp == 0)
		return (0);
	return (-1);
}
