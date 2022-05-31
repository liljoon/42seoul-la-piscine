/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:26:33 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/18 16:03:06 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_word(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	idx;
	int	cap;

	cap = 1;
	idx = 0;
	while (*(str + idx) != '\0')
	{
		if (cap && str[idx] >= 'a' && str[idx] <= 'z')
			str[idx] -= 32;
		else if (!cap && str[idx] >= 'A' && str[idx] <= 'Z')
			str[idx] += 32;
		if (is_word(str[idx]))
			cap = 0;
		else
			cap = 1;
		idx++;
	}
	return (str);
}
