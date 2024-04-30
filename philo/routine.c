/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:45:46 by npatron           #+#    #+#             */
/*   Updated: 2024/02/17 13:42:19 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo)
{
	msg(philo, "think");
}

void	sleeping(t_philo *philo)
{
	msg(philo, "sleep");
	ft_usleep(philo->data->tt_sleep);
}

void	uber_eats(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	if (dead_loop(philo) == 1)
		return ;
	msg(philo, "fork");
	pthread_mutex_lock(philo->l_fork);
	if (dead_loop(philo) == 1)
		return ;
	msg(philo, "fork");
	philo->eat = 1;
	msg(philo, "eat");
	ft_usleep(philo->data->tt_eat);
	pthread_mutex_lock(&philo->data->stop);
	philo->meals++;
	pthread_mutex_unlock(&philo->data->stop);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	philo->eat = 0;
	pthread_mutex_lock(&philo->data->stop);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->data->stop);
}

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		usleep(500);
	while (philo->data->dead == false)
	{
		if (dead_loop(philo) == 1)
			break ;
		uber_eats(philo);
		if (dead_loop(philo) == 1)
			break ;
		sleeping(philo);
		if (dead_loop(philo) == 1)
			break ;
		thinking(philo);
	}
	return (ptr);
}
