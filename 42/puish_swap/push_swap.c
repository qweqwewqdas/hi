/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:38:35 by duhkim            #+#    #+#             */
/*   Updated: 2025/07/18 21:24:12 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rank_check(t_node *node, t_list *new_node)
{
	t_list	*temp;

	temp = node->head;
	while (temp)
	{
		if (temp->content == new_node->content)
		{
			free(new_node);
			return (1);
		}
		if (temp->content > new_node->content)
			temp->rank++;
		else
			new_node->rank++;
		temp = temp->next;
	}
	return (0);
}

int	check_args(t_node *node, t_list **newlst, char *nbr)
{
	int	i;

	i = 0;
	while (nbr[i])
	{
		if (nbr[i] == '+' || nbr[i] == '-')
		{
			if (i != 0 || nbr[i + 1] == '\0')
				return (1);
		}
		else if (!ft_isdigit(nbr[i]))
			return (1);
		i++;
	}
	if (rank_check(node, *newlst))
		return (1);
	return (0);
}

int	make_list(char **args, t_node *node)
{
	t_list		*newlst;
	long long	num;
	int			i;

	i = 0;
	while (args[i])
	{
		num = ft_atoi(args[i]);
		newlst = ft_lstnew(num);
		if (num > 2147483647 || num < -2147483648 || check_args(node, &newlst,
				args[i]))
		{
			free_list(node);
			return (write(1, "Error\n", 6), 1);
		}
		ft_lstadd_back(&node->head, newlst);
		i++;
	}
	return (0);
}

t_node	*parse(char **argv)
{
	t_node	*node;
	int		i;
	char	**str;

	node = malloc(sizeof(t_node));
	node->head = NULL;
	i = 1;
	while (argv[i])
	{
		str = ft_split(argv[i++], ' ');
		if (make_list(str, node))
		{
			ft_free(str);
			return (NULL);
		}
		ft_free(str);
	}
	node->tail = ft_lstlast(node->head);
	return (node);
}

int	main(int argc, char **argv)
{
	t_node	*a_node;
	t_node	*b_node;
	int		grid;
	int		size;

	if (argc < 2)
		return (1);
	a_node = parse(argv);
	if (!a_node)
		return (1);
	if (!(is_sort(a_node)))
		return (0);
	b_node = create_b_node(a_node);
	size = ft_lstsize(a_node->head);
	if (size <= 5)
		short_sort(a_node, b_node, size);
	else
	{
		grid = grid_count(a_node);
		grid_sort(a_node, b_node, grid);
	}
	free_list(a_node);
	free_list(b_node);
	return (0);
}
