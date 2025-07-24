/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_short_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:09:00 by duhkim            #+#    #+#             */
/*   Updated: 2025/07/19 21:22:47 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_node *node)
{
	if (node->head->content > node->head->next->content)
		sa(node);
}

void	sort_three(t_node *node)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = node->head->rank;
	num2 = node->head->next->rank;
	num3 = node->head->next->next->rank;
	if (num1 > num2 && num2 < num3 && num1 < num3)
		sa(node);
	else if (num1 > num2 && num2 > num3)
	{
		sa(node);
		rra(node);
	}
	else if (num1 > num2 && num2 < num3 && num1 > num3)
		ra(node);
	else if (num1 < num2 && num2 > num3 && num1 < num3)
	{
		sa(node);
		ra(node);
	}
	else if (num1 < num2 && num2 > num3 && num1 > num3)
		rra(node);
}

void	sort_four(t_node *a, t_node *b)
{
	while (ft_lstsize(a->head) > 3)
	{
		if (a->head->rank == 1)
			pb(a, b);
		else
			ra(a);
	}
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_node *a, t_node *b)
{
	while (ft_lstsize(a->head) > 3)
	{
		if (a->head->rank == 1 || a->head->rank == 2)
			pb(a, b);
		else
			ra(a);
	}
	sort_three(a);
	if (b->head && b->head->next && b->head->content < b->head->next->content)
		sb(b);
	pa(a, b);
	pa(a, b);
}

int	short_sort(t_node *a_node, t_node *b_node, int size)
{
	if (size == 2)
		sort_two(a_node);
	else if (size == 3)
		sort_three(a_node);
	else if (size == 4)
		sort_four(a_node, b_node);
	else
		sort_five(a_node, b_node);
	return (0);
}
