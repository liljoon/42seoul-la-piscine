/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yham <yham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:34:39 by yham              #+#    #+#             */
/*   Updated: 2022/05/04 23:34:44 by yham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	move_recursive(int y, int x, t_map_info *map_info)
{
	int	min_dist;
	int	temp;

	if (y >= map_info->map_lines || x >= map_info->line_len)
		return (0);
	if (map_info->map[y][x] == '1')
		return (0);
	if (map_info->dp[y][x] != -1)
		return (map_info->dp[y][x]);
	min_dist = 2147483647;
	temp = move_recursive(y, x + 1, map_info) + 1;
	if (min_dist > temp)
		min_dist = temp;
	temp = move_recursive(y + 1, x + 1, map_info) + 1;
	if (min_dist > temp)
		min_dist = temp;
	temp = move_recursive(y + 1, x, map_info) + 1;
	if (min_dist > temp)
		min_dist = temp;
	map_info->dp[y][x] = min_dist;
	return (min_dist);
}

void	put_square(t_map_info *map_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_info->ans_size)
	{
		j = 0;
		while (j < map_info->ans_size)
		{
			map_info->map[map_info->ans_y + i][map_info->ans_x + j] = '2';
			j++;
		}
		i++;
	}
	print_square(map_info);
}

void	print_square(t_map_info *map_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_info->map_lines)
	{
		j = 0;
		while (j < map_info->line_len)
		{
			ft_putchar(map_info->marker[map_info->map[i][j++] - '0']);
		}
		write(1, "\n", 1);
		i++;
	}
}

int	find_largest_square(t_map_info *map_info)
{
	int	i;
	int	j;
	int	temp;

	if (!init_dp(map_info))
		return (0);
	map_info->ans_size = -1;
	i = -1;
	while (++i < map_info->map_lines)
	{
		j = 0;
		while (j < map_info->line_len)
		{
			temp = move_recursive(i, j, map_info);
			if (map_info->ans_size < temp)
			{
				map_info->ans_size = temp;
				map_info->ans_y = i;
				map_info->ans_x = j;
			}
			j++;
		}
	}
	put_square(map_info);
	return (1);
}
