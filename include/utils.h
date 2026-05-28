/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehode <ehode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:58:15 by ehode             #+#    #+#             */
/*   Updated: 2026/05/28 03:56:41 by ehode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "ctx.h"
# include "display.h"
# include <sys/types.h>

void	toggle_arg_state(t_ctx *ctx, uint arg_number, uint8_t state);
uint8_t	get_arg_state(t_ctx *ctx, uint choice_index);
t_color	get_color_by_ext(const char *s);

#endif