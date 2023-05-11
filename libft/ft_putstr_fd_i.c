/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:45:03 by aclaros-          #+#    #+#             */
/*   Updated: 2023/04/19 17:22:25 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_putstr_fd_i(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		s = "(null)";
	while (s[i])
		ft_putchar_fd_i(s[i++], fd);
	return (i);
}
