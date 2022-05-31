/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 21:13:30 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/21 14:38:52 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	length(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
		idx++;
	return (idx);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	idx_str;
	int	idx_find;
	int	str_length;
	int	to_find_length;

	str_length = length(str);
	to_find_length = length(to_find);
	if (to_find_length == 0)
		return (str);
	idx_str = 0;
	while (idx_str < str_length)
	{
		idx_find = 0;
		while (idx_find < to_find_length)
		{
			if (str[idx_str + idx_find] != to_find[idx_find])
				break ;
			idx_find++;
		}
		if (idx_find == to_find_length)
			return (str + idx_str);
		idx_str++;
	}
	return (NULL);
}
