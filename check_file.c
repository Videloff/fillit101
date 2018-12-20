/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_file.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <videloff@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/19 09:58:28 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 12:54:54 by videloff    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "global.h"

int		check_line(char *line)
{
	int i;

	i = -1;
	while (line[++i])
		if (line[i] != '#' && line[i] != '.')
			return (-1);
	if (i != 4)
		return (-1);
	return (1);
}

int		comp_tab(int i, t_pnt *piece)
{
	return ((g_pcs[i][0].x == piece[1].x - piece[0].x) && (g_pcs[i][0].y ==
		piece[1].y - piece[0].y) && (g_pcs[i][1].x == piece[2].x - piece[0].x)
		&& (g_pcs[i][1].y == piece[2].y - piece[0].y) && (g_pcs[i][2].x ==
		piece[3].x - piece[0].x) && (g_pcs[i][2].y == piece[3].y - piece[0].y));
}

int		get_index(char *tab[5])
{
	int		i;
	int		x;
	int		y;
	int		res;
	t_pnt	test[4];

	i = 0;
	y = -1;
	x = 0;
	res = -1;
	while (tab[++y])
	{
		while (tab[y][x])
		{
			if (tab[y][x] == '#')
			{
				if (i >= 4)
					return (-1);
				test[i].x = x;
				test[i].y = y;
				i++;
			}
			x++;
		}
		x = 0;
	}
	if (i == 4)
	{
		i = 0;
		while (i == 0 && ++res <= 18)
			i = comp_tab(res, test);
		while (tab[++x])
			free(tab[x]);
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
			return (-1);
	if (i != 4)
		return (-1);
	return (get_index(grid));
}

int		ft_readnstock(int fd)
{
	char	*line;
	char	*tab[5];
	int		i;
	int		j;
	int		tmp;

	j = 0;
	i = 0;
	tab[4] = NULL;
	while ((tmp = get_next_line(fd, &line)))
	{
		if (line[0] == '\0' && i == 4)
			break ;
		if (line[0] == '\0')
			error();
		tab[i++] = ft_strdup(line);
		ft_memdel((void**)&line);
	}
	if (i == 4)
		return (check_sizenchar(tab));
	if (tmp == 0)
		return (0);
	error();
	return (-1);
}
