/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:25:42 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/23 11:26:06 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *base)
{
	int	idx;
	int	flag[128];

	idx = 0;
	while (idx < 128)
	{
		flag[idx] = 0;
		idx++;
	}
	idx = 0;
	while (base[idx] != '\0')
	{
		if (base[idx] == '+' || base[idx] == '-')
			return (0);
		else if ((base[idx] >= 9 && base[idx] <= 13) || base[idx] == 32)
			return (0);
		if (flag[(int)base[idx]] == 1)
			return (0);
		flag[(int)base[idx]] = 1;
		idx++;
	}
	if (idx <= 1)
		return (0);
	return (idx);
}

int	is_base(char c, char *base)
{
	int	idx;

	idx = 0;
	while (base[idx] != '\0')
	{
		if (base[idx] == c)
			return (idx);
		idx++;
	}
	return (-1);
}

void	pass_space(char *str, int *idxp)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0'
		&& ((str[idx] >= 9 && str[idx] <= 13) || str[idx] == 32))
		idx++;
	*idxp = idx;
	return ;
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_length;
	int	idx;
	int	sign;
	int	ret;
	int	n;

	sign = 1;
	ret = 0;
	base_length = check_base(base);
	if (base_length == 0)
		return (0);
	pass_space(str, &idx);
	while (str[idx] != '\0' && (str[idx] == '+' || str[idx] == '-'))
	{
		if (str[idx++] == '-')
			sign *= -1;
	}
	while (str[idx] != '\0')
	{
		n = is_base(str[idx++], base);
		if (n == -1)
			break ;
		ret = ret * base_length + n;
	}
	return (ret * sign);
}
