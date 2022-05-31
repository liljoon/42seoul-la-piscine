/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:38:27 by isunwoo           #+#    #+#             */
/*   Updated: 2022/05/01 13:23:42 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	put_str(char *s)
{
	int	idx;

	idx = 0;
	while (s[idx] != '\0')
	{
		write(1, s + idx, 1);
		idx++;
	}
}

void	print_recursive(int n)
{
	char	print_char;

	if (n <= 0)
	{
		return ;
	}
	else
	{
		print_recursive(n / 10);
		print_char = n % 10 + '0';
		write(1, &print_char, 1);
	}
}

void	ft_putnbr(int nb)
{
	int		dividend;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}	
	if (nb < 0)
	{
		dividend = -1 * nb;
		write(1, "-", 1);
	}
	else if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	else
	{
		dividend = nb;
	}
	print_recursive(dividend);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	idx;

	idx = 0;
	while (par[idx].str != 0)
	{
		put_str(par[idx].str);
		write(1, "\n", 1);
		ft_putnbr(par[idx].size);
		write(1, "\n", 1);
		put_str(par[idx].copy);
		write(1, "\n", 1);
		idx++;
	}
}
