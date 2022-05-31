/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 12:58:48 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/24 21:27:08 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_map(int map[4][4]);
int		argv_to_side(char *str, int side[][4]);
void	make_permutation_list(int perm[24][4]);
int		cnt_box_leftright(int *arr, int delta);
void	copy_line(int *s1, int *s2);
int		check_updown(int map[4][4], int side[4][4]);
static int	g_found;

void	make_map_recursive(int idx, int perm[][4], int side[][4], int map[][4])
{
	int	perm_idx;

	if (g_found)
		return ;
	if (idx == 4)
	{
		if (!check_updown(map, side))
			return ;
		print_map(map);
		g_found = 1;
		return ;
	}
	perm_idx = 0;
	while (perm_idx < 24)
	{
		copy_line(map[idx], perm[perm_idx]);
		if (side[2][idx] == cnt_box_leftright(map[idx], 1)
			&& side[3][idx] == cnt_box_leftright(map[idx], -1))
		{
			make_map_recursive(idx + 1, perm, side, map);
		}
		perm_idx++;
	}
}

int	main(int argc, char *argv[])
{
	int	perm[24][4];
	int	side[4][4];
	int	map[4][4];

	g_found = 0;
	if (argc != 2 || !argv_to_side(argv[1], side))
	{
		write(1, "Error", 5);
		return (0);
	}
	make_permutation_list(perm);
	make_map_recursive(0, perm, side, map);
	if (!g_found)
		write(1, "Error", 5);
}
