/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 07:25:34 by aoueldma          #+#    #+#             */
/*   Updated: 2022/06/26 07:26:01 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static const char	*re(const char	*str)
{
	int					i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' )
		i++;
	return (&str[i]);
}

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long int	r;
	int					s;
	const char			*st;

	st = re(str);
	i = 0;
	s = 1;
	r = 0;
	if (st[i] == '-' || st[i] == '+')
	{
		if (st[i] == '-')
			s = s * -1;
		i++;
	}
	while (st[i] && st[i] >= '0' && st[i] <= '9')
	{
		r = r * 10 + (st[i] - 48);
		i++;
		if (r > 9223372036854775807 && (s == 1))
			return (-1);
		if (r > 9223372036854775807 && (s == -1))
			return (0);
	}
	return (r * s);
}
