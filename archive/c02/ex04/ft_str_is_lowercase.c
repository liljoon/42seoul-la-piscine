/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 13:50:57 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/18 15:45:12 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	idx;

	idx = 0;
	while (*(str + idx) != '\0')
	{
		if (!(str[idx] >= 'a' && str[idx] <= 'z'))
		{
			return (0);
		}
		idx++;
	}
	return (1);
}
