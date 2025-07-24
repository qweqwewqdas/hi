/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 02:00:03 by duhkim            #+#    #+#             */
/*   Updated: 2025/07/17 19:33:53 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node *a_node)
{
	t_list	*last;

	if (!a_node->head || !a_node->head->next)
		return ;
	last = a_node->tail;
	a_node->tail = last->prev;
	a_node->tail->next = NULL;
	last->prev = NULL;
	last->next = a_node->head;
	a_node->head->prev = last;
	a_node->head = last;
	write(1, "rra\n", 4);
}

void	rrb(t_node *b_node)
{
	t_list	*last;

	if (!b_node->head || !b_node->head->next)
		return ;
	last = b_node->tail;
	b_node->tail = last->prev;
	b_node->tail->next = NULL;
	last->prev = NULL;
	last->next = b_node->head;
	b_node->head->prev = last;
	b_node->head = last;
	write(1, "rrb\n", 4);
}

void	rrr(t_node *a_node, t_node *b_node)
{
	rra(a_node);
	rrb(b_node);
	write(1, "rrr\n", 4);
}
