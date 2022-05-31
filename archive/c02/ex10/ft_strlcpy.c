/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 16:11:07 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/20 15:52:11 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;

	idx = 0;
	if (size != 0)
	{
		while (idx < size - 1 && src[idx] != '\0')
		{
			dest[idx] = src[idx];
			idx++;
		}
		dest[idx] = '\0';
	}
	while (src[idx] != '\0')
	{
		idx++;
	}	
	return (idx);
}
