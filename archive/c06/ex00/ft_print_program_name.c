/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:08:35 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/25 17:15:13 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	main(int argc, char *argv[])
{
	int	idx;

	if (argc != 1)
		return (0);
	idx = 0;
	while (argv[0][idx] != 0)
	{
		write(1, &argv[0][idx], 1);
		idx++;
	}
	write(1, "\n", 1);
}
