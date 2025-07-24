/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 00:26:17 by duhkim            #+#    #+#             */
/*   Updated: 2025/07/17 20:40:40 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node *node, t_node *to_node)
{
	t_list	*first;

	if (!node->head)
		return ;
	first = node->head;
	node->head = first->next;
	if (!node->head)
		node->tail = NULL;
	else
		node->head->prev = NULL;
	first->next = to_node->head;
	if (to_node->head)
		to_node->head->prev = first;
	to_node->head = first;
	first->prev = NULL;
	if (!to_node->tail)
		to_node->tail = first;
}

void	pa(t_node *a_node, t_node *b_node)
{
	push(b_node, a_node);
	write(1, "pa\n", 3);
}

void	pb(t_node *a_node, t_node *b_node)
{
	push(a_node, b_node);
	write(1, "pb\n", 3);
}
