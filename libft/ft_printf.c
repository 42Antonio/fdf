/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:46:53 by aclaros-          #+#    #+#             */
/*   Updated: 2023/04/19 17:22:19 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_printf(char	const *a, ...)
{
	va_list	al;
	int		r;

	r = 0;
	va_start(al, a);
	while (*a)
	{
		if (*a != '%')
			r += ft_putchar_fd_i(*a, 1);
		else if (*++a == 'p')
			r = ft_putstr_fp(va_arg(al, void *), r);
		else if (*a == 'd' || *a == 'i' || *a == 'u')
				r = ft_putnbr_fd_i(*a, va_arg(al, int), 1, r);
		else if (*a == 'c')
				r += ft_putchar_fd_i(va_arg(al, int), 1);
		else if (*a == 's')
				r += ft_putstr_fd_i(va_arg(al, char *), 1);
		else if (*a == 'x' || *a == 'X')
				r = ft_putnbr_base(*a, va_arg(al, int), r);
		else if (*a == '%')
				r += ft_putchar_fd_i('%', 1);
		a++;
	}
	va_end(al);
	return (r);
}
