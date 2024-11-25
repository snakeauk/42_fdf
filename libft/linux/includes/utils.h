/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 00:25:40 by kinamura          #+#    #+#             */
/*   Updated: 2024/11/08 21:52:12 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"
# include "ft_printf.h"

void	ft_error(const char *format, ...);
void	ft_exit_message(int status, const char *format, ...);
int		ft_fopen(char *filename, const char *mode);

#endif