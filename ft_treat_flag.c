/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:42:16 by ssar              #+#    #+#             */
/*   Updated: 2020/12/15 10:41:57 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_dup_and_free(char *p)
{
	int		i;
	char	*tab;
	int		len;

	len = ft_len(p);
	i = 0;
	if (!(tab = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (p[i])
	{
		tab[i] = p[i];
		i++;
	}
	tab[i] = '\0';
	free(p);
	return (tab);
}

char	*ft_treat_precision(char *tab, char c, int precision)
{
	char *new_tab;

	if (c == 's')
	{
		if (precision >= 0 && ft_len(tab) > precision)
		{
			if (!(new_tab = ft_treat_prec_s(tab, precision)))
				return (NULL);
		}
		else
			return (tab);
	}
	else
	{
		if (precision > 0 && ft_len_nb(tab) < precision)
		{
			if (!(new_tab = ft_treat_prec_nb(tab, precision)))
				return (NULL);
		}
		else
			return (tab);
	}
	return (new_tab);
}

char	*ft_larg(char *tab, t_flag flag)
{
	char *new_tab;

	if (ft_len(tab) < flag.larg_min)
	{
		if (!(new_tab = ft_treat_larg_min(tab, flag.larg_min)))
			return (NULL);
		if (flag.to_left != 0)
			ft_treat_to_left(&new_tab);
		if (flag.pad_zero != 0 && flag.precision < 0 && flag.to_left == 0)
			ft_treat_pad_zero(&new_tab);
	}
	else
		return (tab);
	return (new_tab);
}

char	*ft_treat_flag(char *p, t_flag flag, char c)
{
	char *tab;

	if (flag.isprecision == 0 && flag.larg_min == 0
			&& flag.to_left == 0 && flag.pad_zero == 0)
		return (p);
	if (flag.precision == 0 && ft_cmp(p, "0") == 0)
	{
		free(p);
		if (!(tab = ft_strdup("")))
			return (NULL);
	}
	else
	{
		if (!(tab = ft_dup_and_free(p)))
			return (NULL);
	}
	if (flag.isprecision)
		if (!(tab = ft_treat_precision(tab, c, flag.precision)))
			return (ft_free_tab(tab));
	if (flag.larg_min)
		if (!(tab = ft_larg(tab, flag)))
			return (ft_free_tab(tab));
	return (tab);
}
