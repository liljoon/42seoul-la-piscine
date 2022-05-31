/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:56:56 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/23 17:47:02 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	ret;
	int	idx;

	ret = 1;
	idx = 1;
	if (nb < 0)
		return (0);
	while (idx <= nb)
	{
		ret *= idx;
		idx++;
	}
	return (ret);
}
