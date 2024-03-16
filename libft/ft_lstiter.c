/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:50:40 by mstrauss          #+#    #+#             */
/*   Updated: 2023/10/20 18:54:13 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 		Iterates the list ’lst’ and applies the function ’f’ on
///				the content of each node.
/// @param lst 	Address of a pointer to a node.
/// @param f 	Address of the function used to iterate on the list.
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	tmp = lst;
	while (lst != NULL)
	{
		lst = lst->next;
		f(tmp->content);
		tmp = lst;
	}
}
