/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 08:45:55 by ssar              #+#    #+#             */
/*   Updated: 2020/11/22 17:48:37 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_s(char const *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void		*ft_copy(void *dest, const void *src, size_t n)
{
	unsigned char *temp_dest;
	unsigned char *temp_src;

	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	while (n > 0)
	{
		if (temp_dest == temp_src)
			return (NULL);
		*temp_dest = *temp_src;
		temp_dest++;
		temp_src++;
		n--;
	}
	return (dest);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (s == 0)
		return ((char *)s);
	if (start >= ft_strlen_s(s))
	{
		if (!(ptr = (char *)malloc(sizeof(char))))
			return (NULL);
		ptr = ft_copy(ptr, "", 1);
		return (ptr);
	}
	if (!(ptr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (len <= 0 || !s)
	{
		ptr[len] = 0;
		return (ptr);
	}
	while (i < len && s[start])
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}
