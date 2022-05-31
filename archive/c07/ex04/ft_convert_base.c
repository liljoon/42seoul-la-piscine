/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:45:07 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/28 17:25:18 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	check_base(char *base);

void	swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_rev_int_tab(char *tab, int size)
{
	int	idx;

	idx = 0;
	while (idx <= size / 2 - 1)
	{
		swap(tab + idx, tab + size - idx - 1);
		idx++;
	}
}

void	nbr_setting(int nbr, long long *nbr_l, int *sign)
{
	if (nbr < 0)
	{
		*sign = -1;
		*nbr_l = (long long)nbr;
		*nbr_l *= -1;
	}
	else
	{
		*nbr_l = (long long)nbr;
	}
}

char	*ft_putnbr_base(int nbr, char *base)
{
	long long	nbr_l;
	int			check;
	char		*p;
	int			idx;
	int			sign;

	sign = 1;
	p = malloc(sizeof(char) * 35);
	check = check_base(base);
	idx = 0;
	if (nbr == 0)
		p[idx++] = base[0];
	nbr_setting(nbr, &nbr_l, &sign);
	while (nbr_l != 0)
	{
		p[idx++] = base[nbr_l % check];
		nbr_l /= check;
	}
	if (sign == -1)
		p[idx++] = '-';
	ft_rev_int_tab(p, idx);
	p[idx] = '\0';
	return (p);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		n;
	char	*p;

	if (check_base(base_from) == 0 || check_base(base_to) == 0)
		return (0);
	n = ft_atoi_base(nbr, base_from);
	p = ft_putnbr_base(n, base_to);
	return (p);
}
