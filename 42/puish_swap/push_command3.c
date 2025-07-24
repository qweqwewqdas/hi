/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 01:32:59 by duhkim            #+#    #+#             */
/*   Updated: 2025/07/11 01:33:11 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node *node)
{
	t_list	*first;

	if (!node || !node->head || node->head == node->tail)
		return ;
	first = node->head;
	node->head = first->next;
	node->head->prev = NULL;
	node->tail->next = first;
	first->prev = node->tail;
	first->next = NULL;
	node->tail = first;
}

void	ra(t_node *a_node)
{
	rotate(a_node);
	write(1, "ra\n", 3);
}

void	rb(t_node *b_node)
{
	rotate(b_node);
	write(1, "rb\n", 3);
}

void	rr(t_node *a_node, t_node *b_node)
{
	rotate(a_node);
	rotate(b_node);
	write(1, "rr\n", 3);
}
