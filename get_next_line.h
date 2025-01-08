/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmeliani <zmeliani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:15:30 by zmeliani          #+#    #+#             */
/*   Updated: 2024/12/09 13:58:41 by zmeliani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

char	*append_to_text(char *text_buff, char *temp_buff, int len_temp);
char	*ft_strlcpy(char *dest, const char *src, size_t len_dest);
char	*ft_strlcat(char *dest, const char *src, size_t len_dest,
			size_t len_src);
char	*get_next_line(int fd);
char	*line_text(char *text_buff);
char	*read_text(int fd, char *text_buff);
char	*trim_text(char *text_buff, char *line);

int		find_new_line(const char *str);

size_t	ft_strlen(const char *str);

#endif
