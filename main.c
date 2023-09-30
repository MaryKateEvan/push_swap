/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:20:39 by mevangel          #+#    #+#             */
/*   Updated: 2023/09/30 01:28:24 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	count_arguments(char *s)
{
	size_t	num;
	size_t	i;

	num = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] != ' ' && s[i + 1] == ' ') || \
			(s[i] != ' ' && s[i + 1] == '\0'))
			num++;
		i++;
	}
	return (num);
}

static void	choose_sort(t_stack *stack_a, t_stack *stack_b, int size)
{
	if (is_sorted(stack_a->head) == true)
		return ;
	if (size == 2)
		swap(stack_a, 'a');
	else if (size == 3)
		sort_three(stack_a, 'a');
	else if (size <= 15)
		small_sort(stack_a, stack_b, size);
	else if (size > 15)
	{
		fill_b_to_k_shape(stack_a, stack_b, size);
		filter_and_return_to_a(stack_a, stack_b, size);
	}
	else
		return ;
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
	choose_sort(&stack_a, &stack_b, args_num);
	free_stack(stack_a.head);
	free_stack(stack_b.head);
	return (EXIT_SUCCESS);
}
