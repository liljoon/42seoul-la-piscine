/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:29:40 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/20 16:01:15 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	is_printable(char c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int		idx;
	int		digit[2];
	char	*hex;

	hex = "0123456789abcdef";
	idx = 0;
	while (str[idx] != '\0')
	{
		if (is_printable(str[idx]))
		{
			write(1, str + idx, 1);
		}
		else
		{
			digit[0] = (unsigned char)str[idx] / 16;
			digit[1] = (unsigned char)str[idx] % 16;
			write(1, "\\", 1);
			write(1, hex + digit[0], 1);
			write(1, hex + digit[1], 1);
		}
		idx++;
	}
}
