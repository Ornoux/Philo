/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:44:12 by npatron           #+#    #+#             */
/*   Updated: 2024/02/14 17:29:43 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(long long milliseconds)
{
	long long	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(50);
	return (0);
}

long long	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	free_structs(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nbr_philo)
	{
		free(&philo[i]);
		i++;
	}
}

void	msg(t_philo *philo, char *s)
{
	if (ft_strcmp(s, "fork") == 0)
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%lld %d has taken a fork\n",(get_current_time() - philo->data->start_simulation), philo->id);
		pthread_mutex_unlock(&philo->data->print);
	}
	else if (ft_strcmp(s, "eat") == 0)
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%lld %d is eating\n",(get_current_time() - philo->data->start_simulation), philo->id);
		pthread_mutex_unlock(&philo->data->print);
	}
	else if (ft_strcmp(s, "sleep") == 0)
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%lld %d is sleeping\n",(get_current_time() - philo->data->start_simulation), philo->id);
		pthread_mutex_unlock(&philo->data->print);
	}
	else if (ft_strcmp(s, "think") == 0)
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%lld %d is thinking\n",(get_current_time() - philo->data->start_simulation), philo->id);
		pthread_mutex_unlock(&philo->data->print);
	}
	else if (ft_strcmp(s, "dead") == 0)
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%lld %d is dead\n",(get_current_time() - philo->data->start_simulation), philo->id);
		pthread_mutex_unlock(&philo->data->print);
	}
}
