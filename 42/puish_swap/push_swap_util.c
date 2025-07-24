/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:46:14 by duhkim            #+#    #+#             */
/*   Updated: 2025/07/18 21:10:37 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_node *node)
{
	t_list	*tmp;
	t_list	*lst;

	lst = node->head;
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	free(node);
}

void	ft_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

int	is_sort(t_node *node)
{
	t_list	*tmp;

	tmp = node->head;
	while (tmp && tmp->next)
	{
		if (tmp->rank > tmp->next->rank)
			return (1);
		tmp = tmp->next;
	}
	free_list(node);
	return (0);
}

t_node	*create_b_node(t_node *a_node)
{
	t_node	*b_node;

	b_node = malloc(sizeof(t_node));
	if (!b_node)
	{
		free_list(a_node);
		exit(1);
	}
	b_node->head = NULL;
	b_node->tail = NULL;
	return (b_node);
}

int	grid_count(t_node *a_node)
{
	int	list_size;

	list_size = ft_lstsize(a_node->head);
	if (list_size <= 10)
		return (2);
	else if (list_size <= 100)
		return (3);
	else if (list_size <= 250)
		return (4);
	else
		return (5);
}
