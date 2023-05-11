/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:03:49 by aclaros-          #+#    #+#             */
/*   Updated: 2023/04/29 12:15:25 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_aux(char *from_buffer, char *container)
{
	free(from_buffer);
	if (container)
	{
		free(container);
		container = NULL;
	}
	return (container);
}

static char	*read_aux2(char *from_buffer, char *container)
{
	free(from_buffer);
	from_buffer = NULL;
	return (container);
}

char	*ft_read(char *container, int fd)
{
	char	*from_buffer;
	ssize_t	bytes_read;
	int		nl;

	from_buffer = NULL;
	bytes_read = 1;
	nl = 1;
	while (bytes_read != 0 && nl)
	{
		from_buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!from_buffer)
			return (NULL);
		bytes_read = read(fd, from_buffer, BUFFER_SIZE);
		if (fd < 0 || BUFFER_SIZE <= 0 || bytes_read < 0)
			return (read_aux(from_buffer, container));
		else if (from_buffer[0] == 0 || bytes_read == 0)
			return (read_aux2(from_buffer, container));
		from_buffer[bytes_read] = '\0';
		container = get_next_line_utils(container, from_buffer);
		if (from_buffer[0] == 10 || ft_strchr_g(from_buffer, 10))
			nl = 0;
		free(from_buffer);
		from_buffer = NULL;
	}
	return (container);
}

char	*cut_beginning(char *s, int i)
{
	char	*sol;
	int		j;

	j = 0;
	sol = (char *)malloc(i + 2);
	while (s[j] && j <= i)
	{
	sol[j] = s[j];
	j++;
	}
	sol[j] = '\0';
	return (sol);
}

char	*get_next_line(int fd)
{
	static char	*container;
	char		*cutted;
	int			k;

	k = 0;
	container = ft_read(container, fd);
	if (container && (ft_strchr_g(container, 10) || container[0] == 10))
	{
		k = ft_strchr_g(container, 10);
		cutted = (cut_beginning(container, k));
		container = cut(container, ft_strchr_g(container, 10));
		return (cutted);
	}
	if (container && container[0] != '\0')
	{
		cutted = (char *)malloc(ft_strlen_g(container) + 1);
		ft_strlcpy_g(cutted, container, 0);
	}
	else
		cutted = NULL;
	free (container);
	container = NULL;
	return (cutted);
}
