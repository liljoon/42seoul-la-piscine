/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:50:35 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/16 15:27:41 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

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
