/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:23:58 by mevangel          #+#    #+#             */
/*   Updated: 2023/09/29 23:01:17 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	new_node->index = 0;
	new_node->next = stack->head;
	stack->head = new_node;
	stack->size++;
}

static void	sort_int_array(int *nums, int size)
{
	int		i;
	int		tmp;
	bool	sorting_done;

	tmp = 0;
	sorting_done = false;
	while (sorting_done == false)
	{
		sorting_done = true;
		i = -1;
		while (++i < size - 1)
		{
			if (nums[i] > nums[i + 1])
			{
				tmp = nums[i];
				nums[i] = nums[i + 1];
				nums[i + 1] = tmp;
				sorting_done = false;
			}
		}
	}
}

void	initialize_stacks(t_stack *a, t_stack *b, int *arr, int size)
{
	int		i;
	t_node	*step;

	a->head = NULL;
	b->head = NULL;
	a->size = 0;
	b->size = 0;
	i = size;
	while (--i >= 0)
		fill_nums_stack_a(a, arr[i], arr);
	sort_int_array(arr, size);
	step = a->head;
	while (step != NULL)
	{
		i = -1;
		while (++i < size)
		{
			if (arr[i] == step->value)
			{
				step->index = i;
				break ;
			}
		}
		step = step->next;
	}
}

bool	is_sorted(t_node *check)
{
	while (check->next != NULL)
	{
		if (check->value > check->next->value)
			return (false);
		check = check->next;
	}
	return (true);
}

void	free_stack(t_node *to_free)
{
	t_node	*move;

	if (!to_free)
		return ;
	while (to_free != NULL)
	{
		move = to_free->next;
		free(to_free);
		to_free = move;
	}
	to_free = NULL;
}
