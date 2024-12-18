/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 03:13:46 by ubuntu            #+#    #+#             */
/*   Updated: 2024/12/18 19:58:55 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array3(void ***array)
{
	size_t	size;
	size_t	index;

    if (array)
    {
		size = 0;
		while ((array)[size])
		{
			index = 0;
			while((array)[size][index])
			{
				free(array[size][index]);
				index++;
			}
			free(array[size]);
			size++;
		}
        free(array);
        array = NULL;
    }
}
