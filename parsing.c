/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:58:10 by mevangel          #+#    #+#             */
/*   Updated: 2023/09/29 22:48:37 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pass_spaces(char *s)
{
	int	move;

	move = 0;
	while (s[move] && s[move] == ' ')
		move++;
	return (move);
}

static char	*get_each_number(char *s, int *numbers)
{
	char	*dest;
	int		i;
	int		len;

	i = 0;
	len = word_length(s);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		error_free_exit(s, numbers, NULL);
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static void	check_for_duplicates(int *numbers, int words, char *input)
{
	int	i;
	int	j;

	i = -1;
	while (++i < words - 1)
	{
		j = i + 1;
		while (j < words)
		{
			if (numbers[i] == numbers[j])
				error_free_exit(numbers, input, NULL);
			j++;
		}
	}
}

bool	input_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (false);
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] == '\0')
			break ;
		if (str[i] && (str[i] == '+' || str[i] == '-'))
		{
			if (i != 0 && (str[i - 1] >= '0' && str[i - 1] <= '9'))
				return (false);
			i++;
		}
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}

int	*check_and_split(char *str, int args_num)
{
	int		*numbers;
	int		row;
	int		move;
	char	*tmp;

	row = 0;
	move = 0;
	numbers = (int *)malloc(sizeof(int) * (args_num));
	if (!numbers)
		error_free_exit(str, NULL, NULL);
	move = move + pass_spaces(str);
	while (row < args_num)
	{
		tmp = get_each_number(str + move, numbers);
		if ((ft_atoll(tmp) > INT_MAX) || (ft_atoll(tmp) < INT_MIN))
			error_free_exit(numbers, str, tmp);
		numbers[row] = (int)ft_atoll(tmp);
		move = move + word_length(tmp);
		move += pass_spaces(str + move);
		free(tmp);
		row++;
	}
	check_for_duplicates(numbers, args_num, str);
	return (numbers);
}
