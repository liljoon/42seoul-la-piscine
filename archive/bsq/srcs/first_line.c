/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yham <yham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:31:55 by yham              #+#    #+#             */
/*   Updated: 2022/05/04 23:40:51 by yham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	check_marker(t_map_info *map_info)
{
	if (!map_info->marker[0] || !map_info->marker[1]
		|| !map_info->marker[2])
		return (0);
	if (map_info->marker[0] == map_info->marker[1]
		|| map_info->marker[1] == map_info->marker[2]
		|| map_info->marker[2] == map_info->marker[0])
		return (0);
	return (1);
}

int	get_lines_and_marker(char *arr, t_map_info *map_info)
{
	int			i;
	int			j;
	long long	ll;

	i = 0;
	ll = 0;
	while (arr[i + 3])
	{
		if (!(arr[i] >= '0' && arr[i] <= '9'))
			return (0);
		ll = ll * 10 + (arr[i++] - '0');
	}
	if (ll == 0 || ll > 2147483647)
		return (0);
	j = 0;
	while (j < 3)
		map_info->marker[j++] = '\0';
	j = 0;
	while (j < 3)
		map_info->marker[j++] = arr[i++];
	if (!check_marker(map_info))
		return (0);
	return (ll);
}

int	read_input(t_map_info *map_info, int is_stdin)
{
	int	i;
	int	fd;

	if (!init_buf(map_info))
		return (0);
	if (is_stdin)
	{
		i = 0;
		while (read(0, map_info->buf + i, 1) > 0)
			i++;
		map_info->buf_len = i;
	}
	else
	{
		fd = open(map_info->filename, O_RDONLY);
		map_info->buf_len = read(fd, map_info->buf, 500000);
		if (fd < 0)
			return (0);
		close(fd);
	}
	map_info->buf[map_info->buf_len] = 0;
	return (1);
}

int	check_first_line(t_map_info *map_info, int is_stdin)
{
	int		i;
	char	arr[100];

	if (!read_input(map_info, is_stdin))
		return (0);
	i = 0;
	while (map_info->buf[i] != '\n'
		&& map_info->buf[i] >= 32 && map_info->buf[i] <= 126)
	{
		arr[i] = map_info->buf[i];
		i++;
	}
	arr[i] = '\0';
	if (map_info->buf[i] != '\n' || i - 3 > 10)
		return (0);
	map_info->map_lines = get_lines_and_marker(arr, map_info);
	if (map_info->map_lines == 0)
		return (0);
	return (map_info->map_lines);
}
