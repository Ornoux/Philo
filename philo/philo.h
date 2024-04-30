/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:10:10 by npatron           #+#    #+#             */
/*   Updated: 2024/02/17 14:04:40 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_t						thread;
	int								id;
	int								eat;
	int								meals;
	long long unsigned int			last_meal;
	pthread_mutex_t					*r_fork;
	pthread_mutex_t					*l_fork;
	struct s_data					*data;
}			t_philo;

typedef struct s_data
{
	int						nbr_philo;
	int						nbr_meals;
	long long unsigned int	tt_die;
	int						tt_eat;
	int						tt_sleep;
	bool					dead;
	long long				start_simulation;
	pthread_t				elon_musk;
	pthread_mutex_t			*forks;
	pthread_mutex_t			meal;
	pthread_mutex_t			print;
	pthread_mutex_t			stop;
	pthread_mutex_t			deadlock;
	t_philo					*philo;
}			t_data;

int				lil_atoi(char *s);
int				print_error(int i);
int				check_args(char **tab, int a, t_data *data);
void			init_struct(t_data *data);
long long		get_current_time(void);
int				ft_usleep(long long milliseconds);
void			*routine(void *ptr);
void			start(t_data *data);
void			thinking(t_philo *philo);
void			*meeting_security(void *ptr);
void			msg(t_philo *philo, char *s);
void			destroy_prog(t_philo *philo);
int				ft_strcmp(const char *s1, const char *s2);
void			free_structs(t_philo *philo);
int				condition_life(t_philo *philo);
int				dead_loop(t_philo *philo);
void			free_prog(t_philo *philo);
long long int	rac(t_philo *philo);
void			msg_dead(t_philo *philo, char *s);
void			meeting_security_2(t_philo *philo);

#endif