/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_side.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:20:08 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/24 19:52:14 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len(char *s)
{
	int	cnt;

	cnt = 0;
	while (s[cnt] != '\0')
	{
		cnt++;
	}
	return (cnt);
}

int	check_format(char *s)
{
	int	is_space;
	int	idx;

	is_space = 0;
	idx = 0;
	while (idx < 31)
	{
		if (is_space)
		{
			if (s[idx] != ' ')
				return (0);
			else
				is_space = 0;
		}
		else
		{
			if (!(s[idx] >= '1' && s[idx] <= '4'))
				return (0);
			else
				is_space = 1;
		}
		idx++;
	}
	return (1);
}

int	argv_to_side(char *str, int side[4][4])
{
	int	idx;
	int	x;
	int	y;

	if (str_len(str) != 31)
		return (0);
	if (!check_format(str))
		return (0);
	x = 0;
	y = 0;
	idx = 0;
	while (idx < 32)
	{
		side[y][x] = str[idx] - '0';
		x = (x + 1) % 4;
		if (x == 0)
			y++;
		idx += 2;
	}
	return (1);
}
