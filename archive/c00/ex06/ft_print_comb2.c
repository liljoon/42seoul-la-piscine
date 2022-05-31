/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:58:55 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/16 19:43:13 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	print_number(int number)
{
	char	digit[2];

	digit[0] = number / 10 + '0';
	digit[1] = number % 10 + '0';
	write(1, digit, 2);
}

void	ft_print_comb2(void)
{
	int	first_n;
	int	second_n;

	first_n = 0;
	second_n = 1;
	while (first_n < 99)
	{
		print_number(first_n);
		write (1, " ", 1);
		print_number(second_n);
		if (!(first_n == 98 && second_n == 99))
		{
			write(1, ", ", 2);
		}
		second_n++;
		if (second_n > 99)
		{
			first_n++;
			second_n = first_n + 1;
		}
	}
}
