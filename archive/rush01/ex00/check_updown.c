/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_updown.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:59:27 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/24 21:10:06 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	cnt_box_updown(int n, int delta, int map[4][4]);

int	check_col_overlap(int map[4][4], int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			if (map[i][n] == map[j][n])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_updown(int map[4][4], int side[4][4])
{
	int	i;
	int	n;

	n = 0;
	while (n < 4)
	{
		if (!check_col_overlap(map, n))
			return (0);
		n++;
	}
	i = 0;
	while (i < 4)
	{
		if (side[0][i] != cnt_box_updown(i, 1, map)
				|| side[1][i] != cnt_box_updown(i, -1, map))
			return (0);
		i++;
	}
	return (1);
}
