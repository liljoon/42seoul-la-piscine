/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:41:29 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/21 19:26:03 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	idx_d;
	int	idx_s;

	idx_d = 0;
	idx_s = 0;
	while (dest[idx_d] != '\0')
	{
		idx_d++;
	}
	while (src[idx_s] != '\0')
	{
		dest[idx_s + idx_d] = src[idx_s];
		idx_s++;
	}
	dest[idx_s + idx_d] = '\0';
	return (dest);
}
