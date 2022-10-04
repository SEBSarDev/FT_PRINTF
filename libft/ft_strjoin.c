/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 10:15:15 by ssar              #+#    #+#             */
/*   Updated: 2020/11/22 17:21:09 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_stl(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len;
	size_t	i;
	size_t	u;

	i = 0;
	u = 0;
	if (s1 == 0)
		return ((char*)s2);
	if (s2 == 0)
		return ((char *)s1);
	if (!(ptr = (char *)malloc((ft_stl(s1) + ft_stl(s2)) + 1)))
		return (NULL);
	if ((len = ft_stl(s1) + ft_stl(s2)) <= 0)
	{
		ptr[len] = 0;
		return (ptr);
	}
	while (s1[u])
		ptr[i++] = s1[u++];
	u = 0;
	while (s2[u])
		ptr[i++] = s2[u++];
	ptr[i] = '\0';
	return (ptr);
}
