/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   listing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <videloff@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/06 14:40:40 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/22 16:58:35 by videloff    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fillit.h"

static t_lst	*newchainlink(void)
{
	t_lst	*link;

	if (!(link = malloc(sizeof(t_fdlist))))
		return (NULL);
	link->next = NULL;
	return (link);
}

t_lst			*listing(int *tab, int size)
{
	int		i;
	t_lst	*start;
	t_lst	*list;

	i = 0;
	if (!(list = malloc(sizeof(t_list))))
		return (0);
	list->next = NULL;
	start = list;
	while (i < size)
	{
		list->pt = tab[i];
		if (i + 1 < size)
			list->next = newchainlink();
		list = list->next;
		i++;
	}
	return (start);
}
