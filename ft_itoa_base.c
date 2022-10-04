/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 10:32:11 by ssar              #+#    #+#             */
/*   Updated: 2020/12/11 10:33:04 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fill_tab(long long n, char *base_to, char *tab, int len)
{
	while (n >= (long long)ft_len(base_to))
	{
		ft_fill_tab(n / ft_len(base_to), base_to, tab, len - 1);
		n = n % ft_len(base_to);
	}
	tab[len] = base_to[n];
}

int		ft_size_of_conv(long long n, char *base_to)
{
	int u;

	u = 1;
	if (n >= (long long)ft_len(base_to))
	{
		return (1 + ft_size_of_conv(n / ft_len(base_to), base_to));
	}
	return (u);
}

void	ft_init_exception(int excep, char *tab, int *len)
{
	if (excep == -1)
	{
		tab[0] = '-';
		tab[*len + 1] = '\0';
	}
	else if (excep == 2)
	{
		tab[0] = '0';
		tab[1] = 'x';
		tab[*len + 2] = '\0';
		*len = *len + 1;
	}
	else
	{
		tab[*len] = '\0';
		*len = *len - 1;
	}
}

char	*ft_itoa_base(long long n, char *base_to, int excep)
{
	int		len;
	char	*tab;

	len = ft_size_of_conv(n, base_to);
	if (excep == -1)
	{
		if (!(tab = (char *)malloc(sizeof(char) * (len + 2))))
			return (NULL);
		ft_init_exception(excep, tab, &len);
	}
	else if (excep == 2)
	{
		if (!(tab = (char *)malloc(sizeof(char) * (len + 3))))
			return (NULL);
		ft_init_exception(excep, tab, &len);
	}
	else
	{
		if (!(tab = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		ft_init_exception(excep, tab, &len);
	}
	ft_fill_tab(n, base_to, tab, len);
	return (tab);
}
