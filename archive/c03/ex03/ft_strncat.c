/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:59:51 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/21 19:40:18 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	idx_d;
	unsigned int	idx_s;

	idx_d = 0;
	idx_s = 0;
	while (dest[idx_d] != '\0')
	{
		idx_d++;
	}
	while (src[idx_s] != '\0' && idx_s < nb)
	{
		dest[idx_s + idx_d] = src[idx_s];
		idx_s++;
	}
	dest[idx_s + idx_d] = '\0';
	return (dest);
}
