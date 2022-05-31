/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:54:56 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/25 10:53:53 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long long	idx;

	if (nb <= 1)
		return (0);
	idx = 2;
	while (idx * idx <= nb)
	{
		if (nb % idx == 0)
			return (0);
		idx++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	long long	idx;

	idx = nb;
	while (1)
	{
		if (ft_is_prime(idx))
			return (idx);
		idx++;
	}
}
