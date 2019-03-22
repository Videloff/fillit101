/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   resolver.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <videloff@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/21 17:12:09 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/21 14:23:28 by videloff    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

#include <stdio.h>

char	**insert_piece(t_lst *pc, char **board, char c, int (*axes)[3])
{
	int y_ax;
	int x_ax;

	y_ax = (*axes)[0];
	x_ax = (*axes)[1];
	board[y_ax][x_ax] = c;
	board[(g_pcs[pc->pt][0].y) + y_ax][(g_pcs[pc->pt][0].x) + x_ax] = c;
	board[(g_pcs[pc->pt][1].y) + y_ax][(g_pcs[pc->pt][1].x) + x_ax] = c;
	board[(g_pcs[pc->pt][2].y) + y_ax][(g_pcs[pc->pt][2].x) + x_ax] = c;
	return (board);
}

int		check_piece(t_lst *pc, char **board, int (*axes)[3])
{
	int y_ax;
	int x_ax;

	y_ax = (*axes)[0];
	x_ax = (*axes)[1];
	if (INDEX[0].y + y_ax >= (*axes)[2] || INDEX[0].x + x_ax >= (*axes)[2] ||
		INDEX[1].y + y_ax >= (*axes)[2] || INDEX[1].x + x_ax >= (*axes)[2] ||
		INDEX[2].y + y_ax >= (*axes)[2] || INDEX[2].x + x_ax >= (*axes)[2] ||
		INDEX[0].x + x_ax < 0 ||
		INDEX[1].x + x_ax < 0 ||
		INDEX[2].x + x_ax < 0)
		return (0);
	if (board[(INDEX[0].y) + y_ax][(INDEX[0].x) + x_ax] == '.' &&
		board[(INDEX[1].y) + y_ax][(INDEX[1].x) + x_ax] == '.' &&
		board[(INDEX[2].y) + y_ax][(INDEX[2].x) + x_ax] == '.' &&
		board[y_ax][x_ax] == '.')
		return (1);
	return (0);
}

char	**remove_last_piece(t_lst *pc, char **board, int (*axes)[3])
{
	int y_ax;
	int x_ax;

	y_ax = (*axes)[0];
	x_ax = (*axes)[1];
	board[y_ax][x_ax] = '.';
	board[(g_pcs[pc->pt][0].y) + y_ax][(g_pcs[pc->pt][0].x) + x_ax] = '.';
	board[(g_pcs[pc->pt][1].y) + y_ax][(g_pcs[pc->pt][1].x) + x_ax] = '.';
	board[(g_pcs[pc->pt][2].y) + y_ax][(g_pcs[pc->pt][2].x) + x_ax] = '.';
	return (board);
}

char	**check_free_dot(t_lst *pc, int (*axes)[3], char **board)
{
	while ((*axes)[0] < (*axes)[2])
	{
		while ((*axes)[1] < (*axes)[2])
		{
			if (board[(*axes)[0]][(*axes)[1]] == '.')
			{
				if (check_piece(pc, board, axes) == 1)
					return (board);
			}
			(*axes)[1]++;
			if ((*axes)[1] == (*axes)[2])
			{
				(*axes)[1] = 0;
				break ;
			}
		}
		(*axes)[0]++;
	}
	return (NULL);
}

/*
** axes[0] = y
** axes[1] = x
** axes[2] = size
*/

char	**resolver(t_lst *lst, int *size, char **board, char c)
{
	int axes[3];

	if (!lst)
		return (board);
	axes[2] = *size;
	axes[0] = 0;
	axes[1] = 0;
	while (axes[0] < axes[2])
	{
		if ((check_free_dot(lst, &axes, board)))
		{
			board = insert_piece(lst, board, c, &axes);
			if (resolver(lst->next, size, board, c + 1))
				return (board);
			board = remove_last_piece(lst, board, &axes);
		}
		axes[1]++;
		if (axes[1] == axes[2] && (axes[0] += 1))
			axes[1] = 0;
	}
	if (c == 'A' && (*size)++)
		return (resolver(lst, size, extend_board_size(board, axes[2]), c));
	return (NULL);
}
