/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:59:32 by aclaros-          #+#    #+#             */
/*   Updated: 2023/03/21 19:34:31 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*onelst;

	if (!*lst || !del)
		return ;
	while (*lst)
	{
		onelst = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = onelst;
	}
	*lst = NULL;
}
