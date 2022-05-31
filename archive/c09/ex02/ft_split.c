/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:55:31 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/28 15:26:08 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

static int	g_str_idx;

int	is_deli(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	cnt;
	int	flag;

	flag = 0;
	cnt = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (!is_deli(str[i], charset) && !flag)
			cnt++;
		if (is_deli(str[i], charset))
			flag = 0;
		else
			flag = 1;
		i++;
	}
	return (cnt);
}

int	str_len(char *str, char *charset)
{
	int	idx;

	idx = 0;
	while (!is_deli(str[idx], charset) && str[idx] != '\0')
		idx++;
	return (idx);
}

void	copy(char **p, char *str, int words_idx, int len)
{
	int	temp;

	temp = 0;
	while (temp < len)
	{
		p[words_idx][temp] = str[g_str_idx];
		temp++;
		g_str_idx++;
	}
	p[words_idx][temp] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	char	**p;
	int		words;
	int		words_idx;
	int		len;

	words = count_words(str, charset);
	p = (char **)malloc(sizeof(char *) * (words + 1));
	words_idx = 0;
	g_str_idx = 0;
	while (words_idx < words)
	{				
		while (is_deli(str[g_str_idx], charset))
			g_str_idx++;
		len = str_len(str + g_str_idx, charset);
		p[words_idx] = malloc(sizeof(char) * len + 1);
		copy(p, str, words_idx, len);
		words_idx++;
	}
	p[words_idx] = 0;
	return (p);
}
