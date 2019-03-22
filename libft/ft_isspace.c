/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isspace.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 15:09:10 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 15:38:41 by videloff    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(int c)
{
	if (c == '\f' || c == '\t' || c == ' ' ||
			c == '\v' || c == '\n' || c == '\r')
		return (1);
	else
		return (0);
}
