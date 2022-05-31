/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 19:25:34 by jeseo             #+#    #+#             */
/*   Updated: 2022/04/24 19:30:41 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	g_perm_idx;

void	copy_line(int *s1, int *s2);

void	perm_recursive(int idx, int *arr, int *visited, int perm[24][4])
{
	int	i;

	if (idx == 4)
	{
		copy_line(perm[g_perm_idx], arr);
		g_perm_idx++;
	}
	i = 1;
	while (i <= 4)
	{
		if (!visited[i])
		{
			arr[idx] = i;
			visited[i] = 1;
			perm_recursive(idx + 1, arr, visited, perm);
			visited[i] = 0;
		}
		i++;
	}
}

void	make_permutation_list(int perm[24][4])
{
	int	arr[4];
	int	visited[5];
	int	idx;

	idx = 0;
	while (idx < 5)
	{
		visited[idx] = 0;
		idx++;
	}
	g_perm_idx = 0;
	perm_recursive(0, arr, visited, perm);
}
