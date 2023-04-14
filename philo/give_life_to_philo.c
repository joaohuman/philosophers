/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_life_to_philo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 03:46:32 by jvictor-          #+#    #+#             */
/*   Updated: 2023/04/14 03:47:54 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*test_philo(void *philo)
{
	pthread_mutex_t *phi_nxt;
	t_philo 		*phi;
	int				phi_nxt_id;
	int				i;
	long long		time;

	phi = (t_philo *)philo;
	i = phi->i;
	if (i % 2 == 0)
		usleep(1000);
	if (i != phi->param->num_philo - 1)
	{
		phi_nxt = &phi->param->philo[i+1].fork;
		phi_nxt_id = phi->param->philo[i+1].phi_id;
	}
	else
	{
		phi_nxt = &phi->param->philo[0].fork;
		phi_nxt_id = phi->param->philo[0].phi_id;
	}
	time = get_time() - phi->param->init_time;
	//preciso pegar "&phi->param->philo[i+1].fork" e colocar em uma variavel
	// lembrando que esse i+1 pode dar problema, entao antes verificar
	// para que o ultimo nao tente acessar memoria que nao deve
	// ele precisa entao retornar para o primeiro garfo
	
	pthread_mutex_lock(&phi->fork);
	printf("\033[1;39m{%06lli\033[0;39m} - filosofo %i has taken a fork\n", time, phi->phi_id);
	pthread_mutex_lock(phi_nxt);
	printf("\033[1;39m{%06lli\033[0;39m} - filosofo %i has taken a %i fork\n", time, phi->phi_id, phi_nxt_id);
	pthread_mutex_unlock(phi_nxt);
	printf("\033[1;39m{%06lli\033[0;39m} - filosofo %i has released a %i fork\n", time, phi->phi_id, phi_nxt_id);
	pthread_mutex_unlock(&phi->fork);
	printf("\033[1;39m{%06lli\033[0;39m} - filosofo %i has released a fork\n", time, phi->phi_id);
	return(NULL);
}

int	give_life_to_philo(t_param *p)
{
	int i;

	i = 0;
	while (i < p->num_philo)
	{
		p->philo[i].i = i;
		if (pthread_create(&p->philo[i].phi_thread, NULL, test_philo, &p->philo[i]))
			return (printf("Error creating thread\n"), ERROR);
		i++;
	}
	i = 0;
	while (i < p->num_philo)
	{
		if (pthread_join(p->philo[i].phi_thread, NULL))
			return (printf("Error joining thread\n"), ERROR);
		i++;
	}
	free(p->philo);
	return (SUCCESS);
}
