/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmeliani <zmeliani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:17:28 by zmeliani          #+#    #+#             */
/*   Updated: 2025/01/08 17:17:50 by zmeliani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int		fd = open("test_gnl_files/tes", O_RDONLY);
	// int		fd = 0;
	char	*result = "\0";
	int		i = 0;

	// if (ac != 2)
	// 	return (0);
	while (result != NULL)
	{
		result = get_next_line(fd);
		printf("(fd: \e[1;31m%d\e[0m, line: \e[1;32m%d\e[0m, size: \e[1;34m%zu\e[0m) --> %s\n",
				fd, (i + 1), ft_strlen(result), result);
		free(result);
		i++;
	}
	// (void)av;
	result = NULL;
	printf("\nEND --> %s\n", result);
}