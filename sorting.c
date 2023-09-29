/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:41:36 by mevangel          #+#    #+#             */
/*   Updated: 2023/09/29 23:07:18 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	distance_from_head(t_node *head, int i)
{
	int	dstn;

	dstn = 0;
	while (head->index != i)
	{
		dstn++;
		head = head->next;
	}
	return (dstn);
}

void	sort_three(t_stack *stack, char x)
{
	int		max;
	t_node	*tmp;

	if (is_sorted(stack->head) == true)
		return ;
	tmp = stack->head;
	max = tmp->index;
	while (tmp != NULL)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	if (stack->head->index == max)
		rotate(stack, x);
	else if (stack->head->next->index == max)
		reverse_rotate(stack, x);
	if (stack->head->index > stack->head->next->index)
		swap(stack, x);
}

void	small_sort(t_stack *a, t_stack *b, int size)
{
	int	i;
	int	lowest;
	int	dstn;

	i = 0;
	lowest = -1;
	while (++i <= size - 3 && ++lowest < size)
	{
		dstn = distance_from_head(a->head, lowest);
		if (dstn < size - dstn - lowest)
			while (a->head->index != lowest)
				rotate(a, 'a');
		else
			while (a->head->index != lowest)
				reverse_rotate(a, 'a');
		if (b->size == 0 && is_sorted(a->head))
			return ;
		push (b, a, 'b');
	}
	sort_three(a, 'a');
	i = 0;
	while (++i <= size - 3)
		push(a, b, 'a');
}

void	fill_b_to_k_shape(t_stack *a, t_stack *b, int size)
{
	int	threshold;
	int	iter;

	threshold = ft_sqrt(size) * 3 / 2;
	iter = 0;
	while (a->head != NULL && iter < size)
	{
		if (a->head->index > iter + threshold)
			rotate(a, 'a');
		else if (a->head->index <= iter)
		{
			push(b, a, 'b');
			rotate(b, 'b');
			iter++;
		}
		else
		{
			push(b, a, 'b');
			iter++;
		}
	}
}

void	filter_and_return_to_a(t_stack *a, t_stack *b, int curr_highest)
{
	int	rb_times;
	int	rrb_times;

	while (--curr_highest >= 0 && b->head != NULL)
	{
		rb_times = distance_from_head(b->head, curr_highest);
		rrb_times = b->size - rb_times;
		while (b->head->index != curr_highest)
		{
			if (rb_times <= rrb_times)
				rotate(b, 'b');
			else
				reverse_rotate(b, 'b');
		}
		push(a, b, 'a');
	}
}
