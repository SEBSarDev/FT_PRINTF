/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:23:22 by ssar              #+#    #+#             */
/*   Updated: 2020/12/15 11:35:38 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_len_nb(char *str)
{
	int i;
	int count;

	count = 0;
	if (str[0] == '-')
		i = 1;
	else
		i = 0;
	while (str[i])
	{
		count++;
		i++;
	}
	return (count);
}

char	*ft_free_tab(char *tab)
{
	free(tab);
	return (NULL);
}

char	*ft_dup2(char *s)
{
	char	*ptr;
	int		len;
	int		i;

	i = -1;
	if (s == NULL)
	{
		if (!(ptr = (char *)malloc(sizeof(char) * 7)))
			return (NULL);
		ptr[0] = '(';
		ptr[1] = 'n';
		ptr[2] = 'u';
		ptr[3] = 'l';
		ptr[4] = 'l';
		ptr[5] = ')';
		ptr[6] = '\0';
		return (ptr);
	}
	len = ft_len(s);
	if (!(ptr = (char *)malloc(sizeof(char) * (ft_len(s) + 1))))
		return (NULL);
	while (++i < ft_len(s))
		ptr[i] = s[i];
	ptr[len] = '\0';
	return (ptr);
}

int		ft_next(const char *str)
{
	int count;

	count = 1;
	while (str[count] && ft_is_in("cspdiuxX%", str[count]) != 1)
		count++;
	count++;
	return (count);
}
