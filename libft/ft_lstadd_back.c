/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 08:36:12 by ssar              #+#    #+#             */
/*   Updated: 2020/11/23 16:56:40 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *temp;

	if (!new)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	temp = ft_lstlast(*alst);
	temp->next = new;
}
