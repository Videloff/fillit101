/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <videloff@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/26 09:52:22 by yalabidi     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/22 17:27:33 by videloff    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	error(void)
{
	write(1, "error\n", 6);
	exit(1);
}

void	usage(void)
{
	write(1, "usage: fillit file_name\n", 24);
	exit(1);
}

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

void	dispenser(int size, int tab[27])
{
	t_lst	*list;
	char	**board;

	list = listing(tab, size);
	size = ft_sqrt(size * 4);
	if (!(board = malloc_board(size)))
		return ;
	if (!board[1])
		error();
	board = resolver(list, &size, board, 'A');
	display_board(board);
	free_list(list);
	free_board(board, size);
}

int		main(int ac, char **av)
{
	int		tab[27];
	int		i;
	int		fd;
	int		tmp;

	i = 0;
	tmp = 1;
	if (ac != 2)
		usage();
	if ((fd = open(av[1], O_RDONLY)) < 1 || read(fd, NULL, 0) == -1)
		error();
	while ((tmp = ft_readnstock(fd)))
	{
		if (i > 26)
			error();
		if (tmp == -1)
			break ;
		tab[i++] = tmp - 1;
	}
	tab[i] = -2;
	if (tmp == -1)
		error();
	dispenser(i, tab);
	return (0);
}
