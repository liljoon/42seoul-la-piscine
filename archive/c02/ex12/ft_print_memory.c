/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:53:41 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/20 16:52:18 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

const char	*g_hex = "0123456789abcdef";

void	print_memory_hex(unsigned long long memory)
{	
	char			print[16];
	unsigned int	idx;

	idx = 0;
	while (memory > 0)
	{
		print[15 - idx] = g_hex[memory % 16];
		memory /= 16;
		idx++;
	}
	while (idx < 16)
	{
		print[15 - idx] = '0';
		idx++;
	}
	write(1, print, 16);
	write(1, ": ", 2);
}

void	print_ascii_hex_line(char *c, int last)
{
	int	idx;
	int	is_finished;

	idx = 0;
	is_finished = 0;
	while (idx < 16)
	{
		if (is_finished)
		{
			write(1, "  ", 2);
		}
		else
		{
			if (idx == last - 1)
			{	
				is_finished = 1;
			}
			write(1, g_hex + (unsigned char)c[idx] / 16, 1);
			write(1, g_hex + (unsigned char)c[idx] % 16, 1);
		}
		if (idx % 2 == 1)
			write(1, " ", 1);
		idx++;
	}
}

void	print_char_line(char *c, int last)
{
	int	idx;

	idx = 0;
	while (idx < last)
	{
		if (c[idx] >= 32 && c[idx] <= 126)
			write(1, &c[idx], 1);
		else
			write(1, ".", 1);
		idx++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{	
	unsigned int	y;
	char			*addr_c;
	int				last;

	if (size == 0)
		return (addr);
	addr_c = (char *)addr;
	y = 0;
	last = 16;
	while (y <= (size - 1) / 16)
	{
		if (y == (size - 1) / 16)
			last = (size - 1) % 16 + 1;
		print_memory_hex((unsigned long long)&addr_c[16 * y]);
		print_ascii_hex_line(&addr_c[16 * y], last);
		print_char_line(&addr_c[16 * y], last);
		write(1, "\n", 1);
		y++;
	}
	return (addr);
}
