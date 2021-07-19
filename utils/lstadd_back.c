/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 18:06:59 by kkonishi          #+#    #+#             */
/*   Updated: 2021/07/07 16:43:22 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *ne)
{
	t_list	*tmp;

	if (!*lst)
	{
		*lst = ne;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp->next = ne;
}
