/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:10:04 by npatron           #+#    #+#             */
/*   Updated: 2024/02/17 13:44:36 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutexes(t_data *data)
{
	int	i;

	i = -1;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nbr_philo);
	while (++i < data->nbr_philo)
		pthread_mutex_init(&data->forks[i], NULL);
	data->philo[0].r_fork = &data->forks[0];
	data->philo[0].l_fork = &data->forks[data->nbr_philo - 1];
	i = 1;
	while (i < data->nbr_philo)
	{
		data->philo[i].l_fork = &data->forks[i - 1];
		data->philo[i].r_fork = &data->forks[i];
		i++;
	}
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->stop, NULL);
	pthread_mutex_init(&data->deadlock, NULL);
	pthread_mutex_init(&data->meal, NULL);
	return ;
}

void	init_struct(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		data->philo[i].meals = 0;
		data->philo[i].id = i;
		data->philo[i].eat = 0;
		data->philo[i].data = data;
		data->philo[i].last_meal = get_current_time();
		i++;
	}
	return ;
}

void	start(t_data *data)
{
	int	i;

	i = 0;
	init_mutexes(data);
	init_struct(data);
	pthread_create(&data->elon_musk, NULL, meeting_security, &data->philo[i]);
	while (i < data->nbr_philo)
	{
		pthread_create(&data->philo[i].thread, NULL, routine, &data->philo[i]);
		i++;
	}
	i = 0;
	i = -1;
	while (++i < data->nbr_philo)
		pthread_join(data->philo[i].thread, NULL);
	pthread_join(data->elon_musk, NULL);
	return ;
}
