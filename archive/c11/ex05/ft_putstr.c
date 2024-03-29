/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:56:46 by isunwoo           #+#    #+#             */
/*   Updated: 2022/05/04 20:50:29 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putstr(char *str)
{
	int	idx;

	idx = 0;
	while (*(str + idx) != '\0')
	{
		write(2, str + idx, 1);
		idx++;
	}
}
