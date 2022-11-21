#include "inc/PicoShell.h"

void	gen_timer(void)
{
	pthread_t		*timer;

	get_data(NULL)->time = malloc(sizeof(t_timer));
	get_data(NULL)->time->timer_lock = malloc(sizeof(pthread_mutex_t));
	timer = malloc(sizeof(pthread_t));
	pthread_mutex_init(get_data(NULL)->time->timer_lock, NULL);
	get_data(NULL)->time->start_time = time(NULL);
	get_data(NULL)->time->cur_time = time(NULL);
	pthread_create(timer, NULL, routine, (void *)get_data(NULL)->time);
}

void	*routine(void *time_ds)
{
	t_timer *data_time;

	data_time = time_ds;
	while(1)
	{
		pthread_mutex_lock(data_time->timer_lock);
		usleep(1000);
		data_time->cur_time = time(NULL);
		pthread_mutex_unlock(data_time->timer_lock);
	}
	return(NULL);
}

unsigned long get_elapse_time(void)
{
	return (get_data(NULL)->time->cur_time - get_data(NULL)->time->start_time);
}

void	show_elapse_time(void)
{
	unsigned long timer = get_elapse_time();
	if(timer / 60 >= 1)
		ft_printfd(1, "\033[38;5;208m°º¤ø,¸¸,ø¤º°`°º¤ø,¸,ø¤°º¤ø,¸ Time since start : %u minutes and %u seconds `°º¤ø,¸,ø¤°º¤ø,¸¸,ø¤º°`°º¤ø,¸#0\n\n", timer/60, timer % 60);
	else
		ft_printfd(1, "\033[38;5;208m°º¤ø,¸¸,ø¤º°`°º¤ø,¸,ø¤°º¤ø,¸Time since start : %u seconds `°º¤ø,¸,ø¤°º¤ø,¸¸,ø¤º°`°º¤ø,¸#0\n\n", timer % 60);
}