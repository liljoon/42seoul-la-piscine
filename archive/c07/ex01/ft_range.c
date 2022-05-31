/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:05:30 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/26 17:20:26 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	idx;

	if (min >= max)
		return (0);
	arr = malloc(sizeof(int) * (max - min));
	idx = 0;
	while (idx < (max - min))
	{
		arr[idx] = idx + min;
		idx++;
	}
	return (arr);
}
