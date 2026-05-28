/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:58:13 by ehode             #+#    #+#             */
/*   Updated: 2026/05/28 03:58:07 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "utils.h"
#include <stdint.h>
#include <sys/types.h>

void	toggle_arg_state(t_ctx *ctx, uint choice_index, uint8_t state)
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

uint8_t	get_arg_state(t_ctx *ctx, uint choice_index)
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
				return (ctx->choice_state[i]);
			current_choice_index++;
		}
		i++;
	}
	return (0);
}

t_color	get_color_by_ext(const char *s)
{
	const t_color	colors[] = {RED, GREEN, YELLOW, BLUE, PURPLE, CYAN};
	uint8_t			found;
	uint			sum;
	uint			i;

	found = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '.')
			found = 1;
		i++;
	}
	if (!found)
		return (WHITE);
	sum = 0;
	while (s[i] != '.')
		sum += s[i--];
	return (colors[sum % sizeof(colors) / sizeof(t_color)]);
}
