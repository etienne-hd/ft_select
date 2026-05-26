/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:58:13 by ehode             #+#    #+#             */
/*   Updated: 2026/05/26 21:45:13 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdint.h>
#include <sys/types.h>

void	toggle_arg_state(t_ctx *ctx, uint choice_index, t_state state)
{
	uint	i;
	uint	current_choice_index;

	current_choice_index = 0;
	i = 0;
	while (i < ctx->choice_count)
	{
		if (!(ctx->choice_state[i] & DELETED))
		{
			if (choice_index == current_choice_index)
			{
				ctx->choice_state[i] ^= state;
				break ;
			}
			current_choice_index++;
		}
		i++;
	}
}
