/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yham <yham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:26:59 by yham              #+#    #+#             */
/*   Updated: 2022/05/05 12:15:25 by yham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	init_buf(t_map_info *map_info)
{
	map_info->buf = malloc(sizeof(char) * 500000);
	if (!map_info->buf)
		return (0);
	return (1);
}

int	init_map(t_map_info *map_info)
{
	int	i;

	map_info->map = malloc(sizeof(char *) * map_info->map_lines);
	if (!map_info->map)
		return (0);
	i = 0;
	while (i < map_info->map_lines)
	{
		map_info->map[i] = malloc(sizeof(char) * (map_info->line_len + 1));
		if (!map_info->map[i++])
			return (0);
	}
	return (1);
}

int	init_dp(t_map_info *map_info)
{
	int	i;
	int	j;

	map_info->dp = malloc(sizeof(int *) * map_info->map_lines);
	if (!map_info->dp)
		return (0);
	i = 0;
	while (i < map_info->map_lines)
	{
		map_info->dp[i] = malloc(sizeof(int) * map_info->line_len);
		if (!map_info->dp[i++])
			return (0);
	}
	i = 0;
	while (i < map_info->map_lines)
	{
		j = 0;
		while (j < map_info->line_len)
			map_info->dp[i][j++] = -1;
		i++;
	}
	return (1);
}

void	free_map_info(t_map_info *map_info, int lines)
{
	int	i;

	i = 0;
	while (i < lines)
	{
		if (map_info->map != NULL)
			free(map_info->map[i]);
		if (map_info->dp != NULL)
			free(map_info->dp[i]);
		i++;
	}
	free(map_info->map);
	free(map_info->dp);
	free(map_info->buf);
}
