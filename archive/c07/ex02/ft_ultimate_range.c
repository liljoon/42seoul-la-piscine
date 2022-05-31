/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:30:09 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/27 11:03:48 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	idx;
	int	*p;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	p = malloc(sizeof(int) * (max - min));
	if (p == 0)
	{
		*range = 0;
		return (-1);
	}
	idx = 0;
	while (idx < (max - min))
	{
		p[idx] = idx + min;
		idx++;
	}
	*range = p;
	return (max - min);
}
