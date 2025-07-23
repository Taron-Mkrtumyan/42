/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 22:13:54 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/07/21 22:14:24 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

void	set_res(t_data *data, t_result value)
{
	mutex_op(&data->data_mutex, LOCK);
	data->end = value;
	mutex_op(&data->data_mutex, UNLOCK);
}

t_result	get_res(t_data *data)
{
	t_result	res;

	mutex_op(&data->data_mutex, LOCK);
	res = data->end;
	mutex_op(&data->data_mutex, UNLOCK);
	return (res);
}

bool	sim_ended(t_data *data)
{
	if (get_res(data) == UNKNOWN)
		return (false);
	return (true);
}
