/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:02:05 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/17 10:47:44 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern void	ft_putchar(char c);

void	print_char_by_coord(int now_x, int now_y, int x, int y)
{
	if ((now_x == 1 && now_y == 1) || (now_x == x && now_y == 1))
		ft_putchar('A');
	else if ((now_x == 1 && now_y == y) || (now_x == x && now_y == y))
		ft_putchar('C');
	else if (now_x == 1 || now_x == x || now_y == y || now_y == 1)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	idx_x;
	int	idx_y;

	if (x <= 0 || y <= 0)
		return ;
	idx_x = 1;
	idx_y = 1;
	while (idx_y <= y)
	{
		idx_x = 1;
		while (idx_x <= x)
		{
			print_char_by_coord(idx_x, idx_y, x, y);
			idx_x++;
		}
		ft_putchar('\n');
		idx_y++;
	}
}
