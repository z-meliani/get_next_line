/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmeliani <zmeliani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:17:28 by zmeliani          #+#    #+#             */
/*   Updated: 2024/12/10 12:14:24 by zmeliani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int		fd[5] = {open("test_gnl_files/test.txt", O_RDONLY),
					open("test_gnl_files/test.txt", O_RDONLY),
					open("test_gnl_files/test2.txt", O_RDONLY),
					open("test_gnl_files/test3.txt", O_RDONLY),
					0};
	char	*result = "\0";
	int		i = 0;
	int		j = 0;
	int		end = 4;

	while (end != 0 && i > -1)
	{
		end = 4;
		j = 0;
		while (fd[j])
		{
			result = get_next_line(fd[j]);
			printf("(fd: \e[1;31m%d\e[0m, line: \e[1;32m%d\e[0m, size: \e[1;34m%zu\e[0m) --> %s\n",
				fd[j], (i + 1), ft_strlen(result), result);
			if ((result == NULL) || (result[ft_strlen(result) - 1] != '\n'))
				printf("\n");
			if (result == NULL)
				end--;
			free(result);
			j++;
		}
		i++;
	}
	result = NULL;
	printf("\nEND --> %s\n", result);
}
