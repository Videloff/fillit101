/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yalabidi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/26 09:52:22 by yalabidi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/26 09:52:24 by yalabidi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

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

int		main(int ac, char **av)
{
	int		tab[27];
	int		i;
	int		j;
	int		fd;
	int		tmp;

	i = 0;
	j = 0;
	tmp = 0;
	if (ac != 2)
		usage();
	if (!(fd = open(av[1], O_RDONLY)))
		return (0);
	while ((tmp = ft_readnstock(fd)) && i <= 26)
	{
		if (tmp == -1)
			break ;
		tab[i++] = tmp;
	}
	tab[i] = 0;
	if (tmp == -1)
		error();
	while (tab[j])
	{
		printf("tab[%d] = %d\n", j, tab[j]);
		j++;
	}
	return (0);
}
