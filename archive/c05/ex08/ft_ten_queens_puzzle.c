/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:19:27 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/23 19:20:29 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	print_map(int map[])
{
	int		idx;
	char	print;

	idx = 0;
	while (idx < 10)
	{
		print = map[idx] + '0';
		write(1, &print, 1);
		idx++;
	}
	write(1, "\n", 1);
}

int	possible(int idx, int map[])
{
	int	y;
	int	x1;
	int	x2;

	y = 0;
	while (y < idx)
	{
		if (map[idx] == map[y])
			return (0);
		y++;
	}
	y = idx - 1;
	x1 = map[idx] - 1;
	x2 = map[idx] + 1;
	while (y >= 0)
	{
		if (map[y] == x1 || map[y] == x2)
			return (0);
		x1--;
		x2++;
		y--;
	}
	return (1);
}

void	recursive(int idx, int map[], int *count)
{
	int	x;

	if (idx == 10)
	{
		print_map(map);
		*count += 1;
		return ;
	}
	x = 0;
	while (x < 10)
	{
		map[idx] = x;
		if (possible(idx, map))
			recursive(idx + 1, map, count);
		x++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	map[10];
	int	count;

	count = 0;
	recursive(0, map, &count);
	return (count);
}
