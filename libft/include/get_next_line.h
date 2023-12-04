/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:17:50 by ahooghe           #+#    #+#             */
/*   Updated: 2023/03/20 14:17:58 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define GNL_SUCCESS	1
# define GNL_FAILURE	-1
# define GNL_EOF		0

# define LBREAK	'\n'
# define STR_EMPTY ""

# define OPEN_MAX		16
# define BUFFER_SIZE	1024

int		get_next_line(int fd, char **line);

#endif
