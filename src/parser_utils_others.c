/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_others.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbayra <ealbayra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:25:30 by ealbayra          #+#    #+#             */
/*   Updated: 2023/11/05 14:25:32 by ealbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

void	free_parse(t_mparse *parse)
{
	if (!parse)
		return ;
	free(parse->cmd);
	free_text(parse->text);
	free(parse);
}
