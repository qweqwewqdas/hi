/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:47:35 by duhkim            #+#    #+#             */
/*   Updated: 2025/07/19 21:24:46 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_list *head)
{
	int		max_rank;
	int		max;
	int		i;
	t_list	*tmp;

	i = 0;
	max = 0;
	max_rank = 0;
	tmp = head;
	while (tmp)
	{
		if (tmp->rank > max_rank)
		{
			max_rank = tmp->rank;
			max = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (max);
}

void	push_grid_to_b(t_node *a_node, t_node *b_node, int grid_min,
		int grid_max)
{
	int	count;
	int	size;

	count = 0;
	size = ft_lstsize(a_node->head);
	while (count < size)
	{
		if (a_node->head->rank >= grid_min && a_node->head->rank <= grid_max)
		{
			pb(a_node, b_node);
			if (b_node->head->rank < (grid_min + grid_max) / 2)
				rb(b_node);
		}
		else
			ra(a_node);
		count++;
	}
}

void	rotate_b_to_max(t_node *b_node, int pos, int size)
{
	int	limit;
	int	j;

	j = 0;
	if (pos <= size / 2)
		limit = pos;
	else
		limit = size - pos;
	while (j < limit)
	{
		if (pos  <= size / 2)
			rb(b_node);
		else
			rrb(b_node);
		j++;
	}
}

void	push_back_to_a(t_node *a_node, t_node *b_node)
{
	int	max;
	int	size;

	while (b_node->head)
	{
		max = find_max(b_node->head);
		size = ft_lstsize(b_node->head);
		rotate_b_to_max(b_node, max, size);
		pa(a_node, b_node);
		if (a_node->head && a_node->head->next)
		{
			if (a_node->head->rank > a_node->head->next->rank)
				sa(a_node);
		}
	}
}

void	grid_sort(t_node *a_node, t_node *b_node, int num_grids)
{
	int	list_size;
	int	grid_size;
	int	i;
	int	min;
	int	max;

	list_size = ft_lstsize(a_node->head);
	grid_size = (list_size + num_grids - 1) / num_grids;
	i = 0;
	while (i < num_grids)
	{
		min = i * grid_size + 1;
		max = (i + 1) * grid_size;
		push_grid_to_b(a_node, b_node, min, max);
		i++;
	}
	push_back_to_a(a_node, b_node);
}
