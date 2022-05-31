/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:03:46 by jeseo             #+#    #+#             */
/*   Updated: 2022/04/24 18:06:39 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	copy_line(int *s1, int *s2)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		s1[i] = s2[i];
		i++;
	}
}

void	print_map(int map[4][4])
{
	char	print;
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			print = map[i][j] + '0';
			write(1, &print, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
