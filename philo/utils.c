/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:28:05 by npatron           #+#    #+#             */
/*   Updated: 2024/02/13 18:29:08 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int is_numeric(char c)
{
    if (c >= '0' && c <= '9')
        return (0);
    return (1);
}

static int str_is_numeric(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        if (is_numeric(str[i]))
            return (1);
        i++;
    }
    return (0);
}

int lil_atoi(char *s)
{
	int i;
	long long res;
    int len;

	i = 0;
	res = 0;
    len = 0;
	if (str_is_numeric(s))
		return (-1);
	while (s[i])
	{
		res = res * 10 + (s[i] - '0');
		i++;
		len++;
	}
	if (len > 10 || res > INT_MAX)
		return (-1);
	return (res);
}

int	print_error(int	i)
{
	if (i == 0)
		printf("Check number of philosophes\n");
	else if (i == 1)
		printf("Check number of arguments\n");
	else if (i == 2)
		printf("Check time_to_die number\n");
	else if (i == 3)
		printf("Check time_to_eat number\n");
	else if (i == 4)
		printf("Check time_to_sleep number\n");
	else if (i == 5)
		printf("Check number_meals number\n");
	return (1);
}
int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		i++;
	}
	return (0);
}