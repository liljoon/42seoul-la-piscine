/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:49:18 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/21 14:39:35 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	length_str(char *str)
{
	unsigned int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		idx++;
	}
	return (idx);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;
	unsigned int	length_src;
	unsigned int	length_dest;

	length_src = length_str(src);
	length_dest = length_str(dest);
	if (length_dest >= size)
		return (length_src + size);
	idx = length_dest;
	while (idx < size - 1 && src[idx - length_dest] != '\0')
	{
		dest[idx] = src[idx - length_dest];
		idx++;
	}
	dest[idx] = '\0';
	return (length_src + length_dest);
}
