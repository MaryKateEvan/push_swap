/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:20:39 by mevangel          #+#    #+#             */
/*   Updated: 2023/09/30 02:09:03 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	*join_args(char **av)
{
	char	*joined;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (av[++k])
		i += (ft_strlen(av[k]) + 1);
	joined = (char *)malloc((sizeof(char) * i) + 1);
	if (!joined)
		error_free_exit(NULL, NULL, NULL);
	i = 0;
	k = -1;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j] != '\0')
			joined[++k] = av[i][j];
		joined[++k] = ' ';
	}
	joined[++k] = '\0';
	return (joined);
}

static bool	strings_are_the_same(char *s1, char *s2)
{
	if (ft_strlen(s1) != ft_strlen(s2))
		return (false);
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (false);
		s1++;
		s2++;
	}
	return (true);
}

static bool	did_operation_ok(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (strings_are_the_same(line, "sa\n") == true)
		swap(stack_a);
	else if (strings_are_the_same(line, "sb\n") == true)
		swap(stack_b);
	else if (strings_are_the_same(line, "ss\n") == true)
		swap_both(stack_a, stack_b);
	else if (strings_are_the_same(line, "pa\n") == true)
		push(stack_a, stack_b);
	else if (strings_are_the_same(line, "pb\n") == true)
		push(stack_b, stack_a);
	else if (strings_are_the_same(line, "ra\n") == true)
		rotate(stack_a);
	else if (strings_are_the_same(line, "rb\n") == true)
		rotate(stack_b);
	else if (strings_are_the_same(line, "rr\n") == true)
		rotate_both(stack_a, stack_b);
	else if (strings_are_the_same(line, "rra\n") == true)
		reverse_rotate(stack_a);
	else if (strings_are_the_same(line, "rrb\n") == true)
		reverse_rotate(stack_b);
	else if (strings_are_the_same(line, "rrr\n") == true)
		reverse_rotate_both(stack_a, stack_b);
	else
		return (false);
	return (true);
}

static void	check_operations(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (did_operation_ok(line, stack_a, stack_b) == false)
		{
			write(2, "Error\n", 6);
			free(line);
			return ;
		}
		free(line);
	}
	if (is_sorted(stack_a->head) && stack_b->size == 0 && stack_a->size != 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	*input;
	int		args_num;
	int		*numbers;

	if (ac < 2)
		return (0);
	if (av[1][0] == '\0')
		error_free_exit(NULL, NULL, NULL);
	input = join_args(av);
	args_num = count_arguments(input);
	if (args_num == 0 || input_is_numeric(input) == false)
		error_free_exit(input, NULL, NULL);
	numbers = check_and_split(input, args_num);
	free(input);
	initialize_stacks(&stack_a, &stack_b, numbers, args_num);
	free(numbers);
	check_operations(&stack_a, &stack_b);
	free_stack(stack_a.head);
	free_stack(stack_b.head);
	return (EXIT_SUCCESS);
}
