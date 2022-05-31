/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:05:12 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/18 15:50:33 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	idx;

	idx = 0;
	while (*(str + idx) != '\0')
	{
		if (str[idx] >= 'a' && str[idx] <= 'z')
		{
			*(str + idx) -= 32;
		}
		idx++;
	}
	return (str);
}