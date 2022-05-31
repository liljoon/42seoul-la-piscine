/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:00:18 by isunwoo           #+#    #+#             */
/*   Updated: 2022/05/05 12:23:27 by yham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	check_valid_map(t_map_info *map_info, int argc)
{
	map_info->buf = NULL;
	map_info->map = NULL;
	map_info->dp = NULL;
	if (!check_first_line(map_info, argc == 1))
		return (0);
	if (!count_line_len(map_info))
		return (0);
	if (!get_map(map_info))
		return (0);
	translate_map(map_info);
	if (!find_largest_square(map_info))
		return (0);
	return (1);
}

void	free_error_case(t_map_info *map_info)
{
	if (map_info->map_lines == -1)
		free_map_info(map_info, 0);
	else
		free_map_info(map_info, map_info->map_lines);
}

int	main(int argc, char *argv[])
{
	int			input_i;
	t_map_info	map_info;

	input_i = 0;
	if (argc != 1)
		input_i++;
	while (input_i < argc)
	{
		if (argc != 1)
			map_info.filename = argv[input_i];
		map_info.map_lines = -1;
		if (!check_valid_map(&map_info, argc))
		{
			free_error_case(&map_info);
			write(2, "map error\n", 10);
			if (input_i != argc - 1)
				write(1, "\n", 1);
			input_i++;
			continue ;
		}
		free_map_info(&map_info, map_info.map_lines);
		if (input_i != argc - 1)
			write(1, "\n", 1);
		input_i++;
	}
}
