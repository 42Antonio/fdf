/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclaros- <aclaros-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:57:47 by aclaros-          #+#    #+#             */
/*   Updated: 2023/03/18 09:00:31 by aclaros-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}
