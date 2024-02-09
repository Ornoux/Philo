/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:10:10 by npatron           #+#    #+#             */
/*   Updated: 2024/02/09 21:16:49 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdbool.h>
#include <limits.h>
#include <unistd.h>


typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eat;
	int				sleep;
	bool			dead;
	int				nb_fork;
	pthread_mutex_t fork;
	struct s_data	*data;
}			t_philo;

typedef struct s_data
{
    int nbr_philo;
    int nbr_meals;
    int tt_die;
    int tt_eat;
    int tt_sleep;
    long long start_simulation;
	pthread_mutex_t print;
	t_philo *philo;
}			t_data;

int			lil_atoi(char *s);
int			print_error(int i);
int			check_args(char **tab, int a, t_data *data);
void		init_struct(t_data *data);
long long	get_current_time(void);
int			ft_usleep(long long milliseconds);
void 		*routine(void *ptr);
void 		start(t_data *data);



#endif