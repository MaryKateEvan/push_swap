/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:23:58 by mevangel          #+#    #+#             */
/*   Updated: 2023/09/30 01:06:00 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	fill_nums_stack_a(t_stack *stack, int num, int *arr)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
	{
		free_stack(stack->head);
		error_free_exit(arr, NULL, NULL);
	}
	new_node->value = num;
	new_node->next = stack->head;
	stack->head = new_node;
	stack->size++;
}

void	initialize_stacks(t_stack *a, t_stack *b, int *arr, int size)
{
	int		i;

	a->head = NULL;
	b->head = NULL;
	a->size = 0;
	b->size = 0;
	i = size;
	while (--i >= 0)
		fill_nums_stack_a(a, arr[i], arr);
}

void	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
