/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:34:19 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/26 17:31:18 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	len_str(char *s)
{
	int	idx;

	idx = 0;
	while (s[idx] != '\0')
		idx++;
	return (idx);
}

int	cnt_chars(int size, char **strs)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (i < size)
	{
		cnt += len_str(strs[i]);
		i++;
	}
	return (cnt);
}

int	copy(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	while (s2[idx] != '\0')
	{
		s1[idx] = s2[idx];
		idx++;
	}
	return (idx);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	char	*p;
	int		size_idx;
	int		str_idx;

	len = cnt_chars(size, strs) + len_str(sep) * (size - 1);
	if (size != 0)
		p = malloc(len + 1);
	else
		p = malloc(1);
	size_idx = 0;
	str_idx = 0;
	while (size_idx < size)
	{
		str_idx += copy(p + str_idx, strs[size_idx]);
		if (size_idx != size - 1)
		{
			str_idx += copy(p + str_idx, sep);
		}
		size_idx++;
	}
	p[str_idx] = '\0';
	return (p);
}
