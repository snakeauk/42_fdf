/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 02:24:00 by kinamura          #+#    #+#             */
/*   Updated: 2024/10/05 02:24:05 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isint(const char *str)
{
	long long	llnum;
	char		*ptr;
	int			sign;

	ptr = (char *)str;
	sign = ft__space_sign(&ptr);
	if (!ptr || *ptr == '\0')
		return (0);
	llnum = 0;
	while (*ptr >= '0' && *ptr <= '9')
	{
		llnum = llnum * 10 + (*ptr - '0');
		if ((sign * llnum) < INT_MIN || (sign * llnum) > INT_MAX)
			return (0);
		ptr++;
	}
	if (*ptr != '\0')
		return (0);
	return (1);
}
