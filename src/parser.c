/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbayra <ealbayra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:25:44 by ealbayra          #+#    #+#             */
/*   Updated: 2023/11/08 13:49:37 by ealbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

char	*get_hard(t_list *lex)
{
	char	*str;
	char	*ret;
	int		i;

	i = 0;
	str = (char *)lex->content;
	ret = malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

void	free_tmp(t_list *tmp)
{
	while (tmp)
	{
		free(tmp->content);
		tmp = tmp->next;
	}
	free(tmp);
}

void	free_node(t_list *node)
{
	if (!node)
		return ;
	if (node->next != NULL)
		free_node(node->next);
	if (node->content)
		node->content = (free(node->content), NULL);
	if (node)
		node = (free(node), NULL);
}

int	ft_parser(t_shell *m_shell)
{
	int	a[3];

	a[0] = 0;
	a[1] = 0;
	a[2] = 0;
	mini_parse(m_shell->lex_list->lex, m_shell, a);
	free_node(m_shell->lex_list->lex);
	return (create_files_m(m_shell));
}
