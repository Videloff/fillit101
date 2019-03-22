/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/12 15:11:03 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 15:39:50 by videloff    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*trc;

	i = 0;
	if (!s)
		return (0);
	if (!(trc = ft_strnew(len)))
		return (0);
	while (s[start] && len > 0)
	{
		trc[i++] = s[start++];
		len--;
	}
	return (trc);
}
