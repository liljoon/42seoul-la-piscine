/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:00:53 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/16 15:18:50 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_print_comb(void)
{
	char	digit[3];

	digit[0] = '0';
	while (digit[0] <= '7')
	{
		digit[1] = digit[0] + 1;
		while (digit[1] <= '8')
		{
			digit[2] = digit[1] + 1;
			while (digit[2] <= '9')
			{	
				write(1, digit, 3);
				if (!(digit[0] == '7' && digit[1] == '8' && digit[2] == '9'))
				{
					write(1, ", ", 2);
				}
				digit[2]++;
			}
			digit[1]++;
		}
		digit[0]++;
	}
}
