/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 13:14:41 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 15:20:31 by videloff    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				i;
	int				neg;
	int				res;
	unsigned char	*s;

	i = 0;
	res = 0;
	s = (unsigned char *)str;
	while (s[i] == ' ' || s[i] == '\f' || s[i] == '\t' ||
			s[i] == '\v' || s[i] == '\n' || s[i] == '\r')
		i++;
	if (s[i] == '-')
		neg = 1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res *= 10;
		res += (s[i] - '0');
		i++;
	}
	if (neg == 1)
		return (-res);
	return (res);
}
