/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:06:04 by aclaros-          #+#    #+#             */
/*   Updated: 2023/04/19 17:17:19 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	repeat(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (base[i])
	{
		while (base[j])
		{	
			if (base[i] == base[j])
				return (1);
			j++;
		}	
		i++;
		j = i + 1;
	}
	return (i);
}

static int	sign_in_empty_one(char	*base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (1);
		i++;
	}
	if (i < 2)
		return (1);
	return (0);
}

static int	recursive(unsigned int nbr, char *base,
		unsigned int size, int count)
{	
	if (nbr >= size)
	{
		count++;
		count = recursive(nbr / size, base, size, count);
		ft_putchar(base[nbr % size]);
	}
	if (nbr < size)
	{
		count++;
		ft_putchar(base[nbr % size]);
	}
	return (count);
}

int	ft_putnbr_base(char a, unsigned int nbr, int count)
{
	char	*base;
	int		size;

	if (a == 'x')
		base = "0123456789abcdef";
	if (a == 'X')
		base = "0123456789ABCDEF";
	if (!repeat(base) || !sign_in_empty_one(base))
	{
		size = repeat(base);
		count = recursive(nbr, base, size, count);
	}
	return (count);
}
