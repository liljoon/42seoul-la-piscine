/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yham <yham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:17:43 by yham              #+#    #+#             */
/*   Updated: 2022/05/05 12:23:58 by yham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_map_info
{
	char	*filename;
	char	*buf;
	int		buf_len;
	char	marker[3];
	int		map_lines;
	int		line_len;
	char	**map;
	int		**dp;
	int		ans_y;
	int		ans_x;
	int		ans_size;
}	t_map_info;

int		init_buf(t_map_info *map_info);
int		init_map(t_map_info *map_info);
int		init_dp(t_map_info *map_info);
void	free_map_info(t_map_info *map_info, int lines);

int		check_marker(t_map_info *map_info);
int		get_lines_and_marker(char *arr, t_map_info *map_info);
int		read_input(t_map_info *map_info, int is_stdin);
int		check_first_line(t_map_info *map_info, int is_stdin);

int		count_line_len(t_map_info *map_info);
int		get_map(t_map_info *map_info);
int		get_marker_index(t_map_info *map_info, char c);
void	translate_map(t_map_info *map_info);

int		move_recursive(int y, int x, t_map_info *map_info);
void	put_square(t_map_info *map_info);
void	ft_putchar(char c);
void	print_square(t_map_info *map_info);
int		find_largest_square(t_map_info *map_info);

#endif
