/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 01:38:34 by mevangel          #+#    #+#             */
/*   Updated: 2023/09/29 01:38:39 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	*ft_collect_data(int fd, char *stash)
{
	int		read_bytes;
	char	buffer[BUFFER_SIZE + 1];

	read_bytes = 1;
	while (!(ft_strchr(stash, '\n')) && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(stash), NULL);
		buffer[read_bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	return (stash);
}

static char	*ft_restrict_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (stash[0] == '\0')
		return (NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_char_calloc(i + 1);
	if (!line)
		return (NULL);
	while (--i >= 0)
		line[i] = stash[i];
	return (line);
}

static char	*ft_renew_stash(char *stash)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (stash[i] == '\0')
		return (free(stash), NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	new = ft_char_calloc(ft_strlen(stash) - i + 1);
	if (!new)
		return (free(stash), NULL);
	if (stash[i] == '\n')
		i++;
	while (stash[i] != '\0')
		new[j++] = stash[i++];
	free(stash);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stash == NULL)
	{
		stash = ft_char_calloc(1);
		if (!stash)
			return (NULL);
	}
	stash = ft_collect_data(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_restrict_line(stash);
	stash = ft_renew_stash(stash);
	return (line);
}
