/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:45:39 by aclaros-          #+#    #+#             */
/*   Updated: 2023/04/19 17:17:39 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static void	ft_putchar2(char c)
{
	write(1, &c, 1);
}

static int	recursive2(unsigned long int nbr, char	*base, int count)
{	
	if (nbr >= 16)
	{
		count++;
		count = recursive2(nbr / 16, base, count);
		ft_putchar2(base[nbr % 16]);
	}
	if (nbr < 16)
	{
		count++;
		ft_putchar2(base[nbr % 16]);
	}
	return (count);
}

int	ft_putstr_fp(char *s, int count)
{
	unsigned long int	p;

	p = (unsigned long int)s;
	ft_putchar2('0');
	count++;
	ft_putchar2('x');
	count++;
	count = recursive2(p, "0123456789abcdef", count);
	return (count);
}
