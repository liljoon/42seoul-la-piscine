/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yham <yham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:33:11 by yham              #+#    #+#             */
/*   Updated: 2022/05/04 23:01:44 by yham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	count_line_len(t_map_info *map_info)
{
	int		i;
	int		buf_i;
	int		cnt;

	buf_i = 0;
	while (map_info->buf[buf_i++] != '\n')
		i = -1;
	map_info->line_len = -1;
	while (++i < map_info->map_lines)
	{
		cnt = 0;
		while (map_info->buf[buf_i] != '\n')
		{
			if (!(map_info->buf[buf_i] == map_info->marker[0]
					|| map_info->buf[buf_i] == map_info->marker[1]))
				return (0);
			cnt++;
			buf_i++;
		}
		if (map_info->line_len != -1 && map_info->line_len != cnt)
			return (0);
		map_info->line_len = cnt;
		buf_i++;
	}
	return (map_info->line_len);
}

int	get_map(t_map_info *map_info)
{
	int		i;
	int		j;
	int		buf_i;

	if (!init_map(map_info))
		return (0);
	buf_i = 0;
	while (map_info->buf[buf_i++] != '\n')
		continue ;
	i = 0;
	while (i < map_info->map_lines)
	{
		j = 0;
		while (j < map_info->line_len)
			map_info->map[i][j++] = map_info->buf[buf_i++];
		map_info->map[i++][j] = '\0';
		buf_i++;
	}
	if (map_info->buf[buf_i] != 0)
		return (0);
	return (1);
}

int	get_marker_index(t_map_info *map_info, char c)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (map_info->marker[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	translate_map(t_map_info *map_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_info->map_lines)
	{
		j = 0;
		while (j < map_info->line_len)
		{
			map_info->map[i][j] = \
				get_marker_index(map_info, map_info->map[i][j]) + '0';
			j++;
		}
		i++;
	}
}
