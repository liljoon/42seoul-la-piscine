/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:26:57 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/23 16:59:16 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	check_base(char *base)
{
	int	idx;
	int	flag[128];

	idx = 0;
	while (idx < 128)
	{	
		flag[idx] = 0;
		idx++;
	}
	idx = 0;
	while (base[idx] != '\0')
	{
		if (base[idx] == '+' || base[idx] == '-')
			return (0);
		if (flag[(int)base[idx]] == 1)
			return (0);
		flag[(int)base[idx]] = 1;
		idx++;
	}
	if (idx <= 1)
		return (0);
	return (idx);
}

void	print_recursive(long long n, int div, char *base)
{
	if (n == 0)
		return ;
	print_recursive(n / div, div, base);
	write(1, base + n % div, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long	nbr_l;
	int			check;

	check = check_base(base);
	if (check == 0)
		return ;
	if (nbr == 0)
		write(1, base, 1);
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr_l = (long long)nbr;
		nbr_l *= -1;
	}
	else
	{
		nbr_l = (long long)nbr;
	}
	print_recursive(nbr_l, check, base);
}
