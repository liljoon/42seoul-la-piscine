/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 19:32:55 by jeseo             #+#    #+#             */
/*   Updated: 2022/04/24 21:19:10 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	cnt_box_leftright(int *arr, int delta)
{
	int	cnt;
	int	max_num;
	int	idx;

	cnt = 1;
	if (delta == 1)
	{
		idx = 1;
		max_num = arr[0];
	}
	else
	{
		idx = 2;
		max_num = arr[3];
	}
	while (idx < 4 && idx >= 0)
	{
		if (arr[idx] > max_num)
		{
			cnt++;
			max_num = arr[idx];
		}
		idx += delta;
	}
	return (cnt);
}

int	cnt_box_updown(int n, int delta, int map[4][4])
{
	int	cnt;
	int	max_num;
	int	idx;

	cnt = 1;
	if (delta == 1)
	{
		idx = 1;
		max_num = map[0][n];
	}
	else
	{
		idx = 2;
		max_num = map[3][n];
	}
	while (idx < 4 && idx >= 0)
	{
		if (map[idx][n] > max_num)
		{
			cnt++;
			max_num = map[idx][n];
		}
		idx += delta;
	}
	return (cnt);
}
