/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:37:01 by isunwoo           #+#    #+#             */
/*   Updated: 2022/05/04 20:32:20 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);
void	ft_putstr(char *str);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		plus(int a, int b);
int		minus(int a, int b);
int		divide(int a, int b);
int		modul(int a, int b);
int		multiply(int a, int b);

int	check_op(char c)
{
	if (c == '+')
		return (0);
	else if (c == '-')
		return (1);
	else if (c == '/')
		return (2);
	else if (c == '%')
		return (3);
	else if (c == '*')
		return (4);
	else
		return (-1);
}

int	main(int argc, char *argv[])
{
	int			a;
	int			b;
	char		oper;
	int			oper_idx;
	static int	(*f[5])(int, int) = {plus,
		minus, divide, modul, multiply};

	if (argc != 4)
		return (0);
	a = ft_atoi(argv[1]);
	oper = argv[2][0];
	b = ft_atoi(argv[3]);
	oper_idx = check_op(oper);
	if (check_op(oper) == -1 || ft_strlen(argv[2]) != 1)
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (oper == '/' && b == 0)
		ft_putstr("Stop : division by zero");
	else if (oper == '%' && b == 0)
		ft_putstr("Stop : modulo by zero");
	else
		ft_putnbr(f[oper_idx](a, b));
	ft_putstr("\n");
}
