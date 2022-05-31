/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:47:53 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/30 19:51:07 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	len(char *s)
{
	int	cnt;

	cnt = 0;
	while (s[cnt] != '\0')
		cnt++;
	return (cnt);
}

char	*ft_strdup(char *src)
{
	int		src_len;
	int		idx;
	char	*p;

	src_len = len(src);
	p = malloc(src_len + 1);
	if (p == 0)
		return (p);
	idx = 0;
	while (src[idx] != '\0')
	{
		p[idx] = src[idx];
		idx++;
	}
	p[idx] = '\0';
	return (p);
}

void	free_strs(t_stock_str *arr)
{
	int	idx;

	idx = 0;
	while (arr[idx].copy != 0)
	{
		free(arr[idx].copy);
		idx++;
	}
	return ;
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			idx;
	t_stock_str	*arr;

	arr = malloc(sizeof(t_stock_str) * (ac + 1));
	if (arr == 0)
		return (0);
	idx = 0;
	while (idx < ac)
	{
		arr[idx].size = len(av[idx]);
		arr[idx].str = av[idx];
		arr[idx].copy = ft_strdup(av[idx]);
		if (arr[idx].copy == 0)
		{
			free_strs(arr);
			free(arr);
			return (0);
		}
		idx++;
	}
	arr[idx].str = 0;
	return (arr);
}
