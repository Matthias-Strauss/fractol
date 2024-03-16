/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:13:53 by mstrauss          #+#    #+#             */
/*   Updated: 2023/12/14 19:30:49 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief writes n zeroed bytes to the string s
/// @param s string to be written to
/// @param n amount of bytes to be written
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*d;

	d = s;
	while (0 < n)
		d[--n] = 0;
}
