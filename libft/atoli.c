/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoli.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 09:28:57 by aclaros-          #+#    #+#             */
/*   Updated: 2023/03/27 14:50:42 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// atoli it is justa copy of atoi to make work with long integers. 

#include "libft.h"

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

long	atoli(const char *str)
{
	long	sign;
	long	result;

	sign = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str++ - '0');
	}
	return (result * sign);
}
