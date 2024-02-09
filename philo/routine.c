/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:45:46 by npatron           #+#    #+#             */
/*   Updated: 2024/02/09 21:35:30 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	sleeping(t_philo *philo)
{
	printf("%lld %d Is sleeping\n", (get_current_time() - philo->data->start_simulation), philo->id);
	ft_usleep(philo->data->tt_sleep);
}
/*
void	message(t_data *data, char *msg)
{
	pthread_mutex_lock(&data->print);
	printf("%lld %d %s\n",(get_current_time() - data->start_simulation), data->philo->id, msg);
	pthread_mutex_unlock(&data->print);
}
*/

void	uber_one(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	printf("%lld %d Has taken a fork\n",(get_current_time() - philo->data->start_simulation), philo->id);
	pthread_mutex_lock(&philo[philo->data->nbr_philo - 1].fork);
	printf("%lld %d Has taken a fork\n",(get_current_time() - philo->data->start_simulation), philo->id);
	philo->eat = 1;
	printf("%lld %d Is Eating\n",(get_current_time() - philo->data->start_simulation), philo->id);
	ft_usleep(philo->data->tt_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo[philo->data->nbr_philo - 1].fork);
	sleeping(philo);
	philo->eat = 0;
}

void	uber_eats(t_philo *philo)
{
	if (philo->id == 0)
		uber_one(philo);
	pthread_mutex_lock(&philo->fork);
	printf("%lld %d Has taken a fork\n",(get_current_time() - philo->data->start_simulation), philo->id);
	pthread_mutex_lock(&philo[philo->id - 1].fork);
	printf("%lld %d Has taken a fork\n",(get_current_time() - philo->data->start_simulation), philo->id);
	printf("%lld %d Is Eating\n",(get_current_time() - philo->data->start_simulation), philo->id);
	ft_usleep(philo->data->tt_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo[philo->id - 1].fork);
	sleeping(philo);
}

void *routine(void *ptr)
{	
	t_philo	*philo;
	
	philo = (t_philo *)ptr;
	if (philo->id % 2)
		ft_usleep(philo->data->tt_eat);
	while (1)
	{
		uber_eats(philo);
	}
	return (NULL);
}
