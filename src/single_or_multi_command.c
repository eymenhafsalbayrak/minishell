/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_or_multi_command.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbayra <ealbayra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:26:28 by ealbayra          #+#    #+#             */
/*   Updated: 2023/11/05 14:52:52 by ealbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	single_or_multi_command(t_shell *m_shell)
{
	t_mparse	*parse;
	int			i;

	i = 0;
	parse = m_shell->mparse;
	while (parse)
	{
		if (parse->type == 2)
			i++;
		parse = parse->next;
	}
	return (i);
}
