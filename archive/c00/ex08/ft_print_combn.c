/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 00:09:27 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/16 15:28:22 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_print_combn_recursive(int digit, const int n, char *stack)
{
	int	start;
	int	end;

	if (digit == n)
	{
		if (!(stack[0] == '0' && stack[n - 1] == n - 1 + '0'))
			write(1, ", ", 2);
		write(1, stack, n);
		return ;
	}
	if (digit == 0)
	{
		start = 0;
	}
	else
	{
		start = stack[digit - 1] - '0' + 1;
	}
	end = 10 - n + digit;
	while (start <= end)
	{
		stack[digit] = start + '0';
		ft_print_combn_recursive(digit + 1, n, stack);
		start++;
	}
}

void	ft_print_combn(int n)
{
	char	stack[9];

	ft_print_combn_recursive(0, n, stack);
}
