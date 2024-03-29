/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:06:00 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/25 10:31:28 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long	idx;

	idx = 0;
	while (idx * idx <= nb)
	{
		if (idx * idx == nb)
			return (idx);
		idx++;
	}
	return (0);
}
