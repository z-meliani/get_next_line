/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmeliani <zmeliani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:41:40 by zmeliani          #+#    #+#             */
/*   Updated: 2024/12/10 14:04:40 by zmeliani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_text(int fd, char *text_buff)
{
	char	*temp_buff;
	int		nb_read;
	int		nl;

	temp_buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp_buff)
		return (free(temp_buff), NULL);
	nb_read = 1;
	nl = 1;
	while (nb_read > 0 && nl == nb_read)
	{
		nb_read = read(fd, temp_buff, BUFFER_SIZE);
		if (nb_read == -1)
			return (free(text_buff), free(temp_buff), NULL);
		temp_buff[nb_read] = 0;
		text_buff = append_to_text(text_buff, temp_buff, nb_read);
		nl = find_new_line(temp_buff);
	}
	free(temp_buff);
	return (text_buff);
}

char	*append_to_text(char *text_buff, char *temp_buff, int len_temp)
{
	const int	len_text = ft_strlen(text_buff);
	char		*new_text;

	if (len_text == 0 && len_temp == 0)
		return (free(text_buff), NULL);
	new_text = malloc(sizeof(char) * (len_text + len_temp + 1));
	if (!new_text)
		return (free(new_text), NULL);
	new_text = ft_strlcpy(new_text, text_buff, len_text);
	new_text = ft_strlcat(new_text, temp_buff, len_text, len_temp);
	free(text_buff);
	return (new_text);
}

char	*line_text(char *text_buff)
{
	const int	nl = find_new_line(text_buff);
	char		*line;

	if (text_buff == NULL)
		return (NULL);
	else
	{
		line = malloc(sizeof(char) * (nl + 2));
		if (!line)
			return (free(line), NULL);
		line = ft_strlcpy(line, text_buff, (nl + 1));
	}
	return (line);
}

char	*trim_text(char *text_buff, char *line)
{
	const int	i_start = ft_strlen(line);
	const int	size = ft_strlen(text_buff) - i_start;
	int			i;

	if (size == 0)
		return (free(text_buff), NULL);
	text_buff = ft_strlcpy(text_buff, &text_buff[i_start], size);
	i = 0;
	while (i < i_start)
	{
		text_buff[size + i] = '\0';
		i++;
	}
	return (text_buff);
}

char	*get_next_line(int fd)
{
	static char	*text_buff[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!text_buff[fd])
	{
		text_buff[fd] = malloc(sizeof(char));
		if (!text_buff[fd])
			return (free(text_buff[fd]), NULL);
		text_buff[fd][0] = 0;
	}
	text_buff[fd] = read_text(fd, text_buff[fd]);
	line = line_text(text_buff[fd]);
	text_buff[fd] = trim_text(text_buff[fd], line);
	return (line);
}
