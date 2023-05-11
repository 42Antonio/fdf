/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:21:36 by aclaros-          #+#    #+#             */
/*   Updated: 2023/04/19 17:22:22 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd_i(char a, long int n, int fd, int count)
{
	if (a == 'u')
	{
		if (n < 0)
			return (ft_putnbr_fd_i('o', 4294967295 + n + 1, fd, count));
		return (ft_putnbr_fd_i('o', n, fd, count));
	}
	if (n < 0)
	{
		count++;
		ft_putchar_fd_i('-', fd);
		count = ft_putnbr_fd_i('o', -n, fd, count);
	}
	else if (n >= 10)
	{
		count++;
		count = ft_putnbr_fd_i('o', n / 10, fd, count);
		ft_putnbr_fd_i('o', n % 10, fd, count);
	}
	else
		count += ft_putchar_fd_i(n + '0', fd);
	return (count);
}
