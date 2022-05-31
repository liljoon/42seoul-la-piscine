/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:14:39 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/26 16:49:30 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

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
