/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:49:45 by npatron           #+#    #+#             */
/*   Updated: 2024/02/17 14:04:27 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	msg_dead(t_philo *philo, char *s)
{
	if (ft_strcmp(s, "dead") == 0)
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%lld %d is dead\n", rac(philo), philo->id + 1);
		pthread_mutex_unlock(&philo->data->print);
	}
}

void	meeting_security_2(t_philo *philo)
{
	destroy_prog(philo);
	pthread_mutex_lock(&philo->data->deadlock);
	philo->data->dead = true;
	pthread_mutex_unlock(&philo->data->deadlock);
}
