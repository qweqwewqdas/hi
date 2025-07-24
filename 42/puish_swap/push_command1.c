/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:46:10 by duhkim            #+#    #+#             */
/*   Updated: 2025/07/16 21:36:29 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node *node)
{
	t_list	*first;
	t_list	*second;

	if (!node->head || !node->head->next)
		return ;
	first = node->head;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	node->head = second;
	if (first->next == NULL)
		node->tail = first;
}

void	sa(t_node *a_node)
{
	swap(a_node);
	write(1, "sa\n", 3);
}

void	sb(t_node *b_node)
{
	swap(b_node);
	write(1, "sb\n", 3);
}

void	ss(t_node *a_node, t_node *b_node)
{
	swap(a_node);
	swap(b_node);
	write(1, "ss\n", 3);
}
