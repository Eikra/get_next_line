/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecharak <iecharak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:12:46 by iecharak          #+#    #+#             */
/*   Updated: 2022/11/24 23:12:21 by iecharak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	line = NULL;
	//printf("tst");
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) < 0)
		return (NULL);
	str = ft_read_add_to_str(str, fd);
	if (str == NULL)
		return (NULL);
	// printf("<str:%s> \n", str);
	line = ft_str_to_line(str);
	// printf("<line:%s> \n", line);
	str = ft_clean_str(str);
	//printf("<%s> \n", str);
	return (line);
}

char	*ft_read_add_to_str(char *str, int fd)
{
	int		readed;
	char	*buffer;

	readed = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (ft_strchr(str, '\n') == 0 && readed > 0)
	{
		//printf("{%s|", str);
		readed = read(fd, buffer, BUFFER_SIZE);
		//printf("readed:%d|", readed);
		if (readed <= 0)
			break ;
		buffer[readed] = '\0';
		//printf("%s|", buffer);
		str = add_to_str(str, buffer, readed);
		//printf("%s}\n", str);
	}
	free(buffer);
	return (str);
}

char	*add_to_str(char *str, char *buffer, int readed)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	//printf("<%s|", str);
	while (str && str[i])
		i++;
	s = malloc(sizeof(char) * (i + readed + 1));
	if (!s)
		return (NULL);
	while (str && str[j])
	{
		s[j] = str[j];
		j++;
	}
	i = 0;
	while (buffer[i])
	{
		s[j] = buffer[i];
		i++;
		j++;
	}
	s[j] = '\0';
	//printf("%s>\n", s);
	//printf("<str %s\tbuff %s\ts %s>\n ", str, buffer,s);
	free(str);
	return (s);
}

char	*ft_str_to_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	// printf("<%d> ", (i + 1));
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_clean_str(char *str)
{
	char *current;
	int i;
	int j;

	//printf("<%s", str);
	i = 0;
	if (!str)
		return (NULL);
	if (str[i] == '\n')
		i++;
	else
		while (str[i] && str[i] != '\n')
		{
			i++;
			if (str[i] == '\n')
			{
				i++;
				break ;
			}
		}
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	current = malloc((ft_strlen(str) - i + 1));
	if (!current)
	{
		free(str);
		return (NULL);
	}
	j = 0;
	while (str[i])
	{
		current[j] = str[i];
		i++;
		j++;
	}
	current[j] = '\0';
	free(str);
	//printf("|%s>", current);
	return (current);
}