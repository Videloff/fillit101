/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <videloff@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/20 14:22:49 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/22 13:18:07 by videloff    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

char			*dot_line(char *line, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		line[i] = '.';
		i++;
	}
	return (line);
}

void			display_board(char **board)
{
	int x;

	if (!board)
		return ;
	x = 0;
	while (board[x])
	{
		ft_putstr(board[x]);
		ft_putchar('\n');
		x++;
	}
}

char			**malloc_board(int size)
{
	char	**board;
	int		i;

	i = 0;
	if (!(board = malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(board[i] = ft_strnew(size)))
			return (NULL);
		i++;
	}
	board[size] = NULL;
	i = 0;
	while (board[i])
	{
		board[i] = dot_line(board[i], size);
		i++;
	}
	return (board);
}
