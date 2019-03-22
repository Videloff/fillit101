/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   extend_board.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <videloff@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/04 11:34:54 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/22 17:24:08 by videloff    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	init_grid(char *grid[5])
{
	grid[0] = NULL;
	grid[1] = NULL;
	grid[2] = NULL;
	grid[3] = NULL;
	grid[4] = NULL;
}

void	error_free(char *grid[5])
{
	int i;

	i = -1;
	while (++i < 4)
		if (grid[i])
			free(grid[i]);
	write(1, "error\n", 6);
	exit(1);
}

void	free_list(t_lst *lst)
{
	t_lst *tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

void	free_board(char **board, int size)
{
	int	i;

	i = 0;
	if (!board)
		return ;
	while (i <= size)
	{
		free(board[i]);
		i++;
	}
	free(board);
}

char	**extend_board_size(char **board, int size)
{
	char	**new_board;

	free_board(board, size);
	if (!(new_board = malloc_board(size + 1)))
		return (NULL);
	return (new_board);
}
