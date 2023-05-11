/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclaros- <aclaros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:32:39 by aclaros-          #+#    #+#             */
/*   Updated: 2023/05/11 11:32:40 by aclaros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*cut(char *s, int i)
{
	char	*sol;
	int		j;

	j = 0;
	sol = (char *)malloc(ft_strlen_g(s) - i + 1);
	if (!sol)
		return (NULL);
	while (j <= ft_strlen_g(s) - i - 1)
	{
		sol[j] = s[j + i + 1];
		j++;
	}
	sol[j] = '\0';
	if ((sol && *sol == '\0') || !sol)
	{
		free(sol);
		sol = NULL;
	}
	free (s);
	s = NULL;
	return (sol);
}

int	ft_strchr_g(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return (i);
	return (0);
}

int	ft_strlen_g(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy_g(char *dst, const char *src, int k)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[k + i] = src[i];
		i++;
	}
	dst[k + i] = '\0';
	return (ft_strlen_g(src));
}

char	*get_next_line_utils(char	*container, char	*from_buffer)
{
	int		k;
	int		cn;
	char	*new_container;

	cn = 0;
	if (container == NULL)
	{
		container = (char *)malloc(1);
		if (container == NULL)
			return (NULL);
		container[0] = '\0';
		cn = 1;
	}
	k = ft_strlen_g(container);
	new_container = (char *)malloc(ft_strlen_g(from_buffer) + k + 1);
	if (new_container == NULL)
		return (NULL);
	if (cn != 1)
		ft_strlcpy_g(new_container, container, 0);
	ft_strlcpy_g(new_container, from_buffer, k);
	free (container);
	container = NULL;
	return (new_container);
}
