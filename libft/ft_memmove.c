/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:51:42 by aclaros-          #+#    #+#             */
/*   Updated: 2022/10/26 12:25:32 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*dst1;
	char	*src1;

	dst1 = (char *)dst;
	src1 = (char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst < src)
		while (n--)
			*dst1++ = *src1++;
	else
		while (n--)
			((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
	return (dst);
}
