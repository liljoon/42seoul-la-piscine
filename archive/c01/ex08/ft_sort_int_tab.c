/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isunwoo <isunwoo@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:32:03 by isunwoo           #+#    #+#             */
/*   Updated: 2022/04/16 20:28:52 by isunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	idx_now;
	int	idx_search;
	int	idx_min;

	idx_now = 0;
	while (idx_now < size - 1)
	{
		idx_search = idx_now;
		idx_min = idx_search;
		while (idx_search < size)
		{
			if (tab[idx_search] < tab[idx_min])
			{
				idx_min = idx_search;
			}
			idx_search++;
		}
		swap(tab + idx_now, tab + idx_min);
		idx_now++;
	}
}
