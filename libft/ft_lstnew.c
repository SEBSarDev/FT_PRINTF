/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:37:47 by ssar              #+#    #+#             */
/*   Updated: 2020/11/23 15:25:25 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *ptr;

	if (!(ptr = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}
