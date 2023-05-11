/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclaros- <aclaros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:09:03 by aclaros-          #+#    #+#             */
/*   Updated: 2022/10/11 11:56:23 by aclaros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*upcopy;

	upcopy = (char *)malloc(ft_strlen(s1) + 1);
	if (!(upcopy))
		return (0);
	ft_memcpy(upcopy, s1, ft_strlen(s1) + 1);
	return (upcopy);
}
