#include "inc/PicoShell.h"

void get_status(void)
{
	DATA *data = get_data(NULL);
	int hintsmax;
	if (data->level == 1)
		hintsmax = (int)HINTS_L1;
	else if (data->level == 2)
		hintsmax = (int)HINTS_L2;
	else if (data->level == 3)
		hintsmax = (int)HINTS_L3;
	else
		hintsmax = 0;
	printf("Current level : %d/5\nTime since start : %lu seconds\nHints for level : %d/%d\n", data->level, get_elapse_time(), data->max_used_hints, hintsmax);
}

void	get_hint_score(void)
{
	DATA *data = get_data(NULL);
	data->hint_score -= data->max_used_hints * 1200000;
}

void	get_time_score(void)
{
	DATA *data = get_data(NULL);

	data->time_score += (60 * PLAY_TIME - get_elapse_time()) * 3000;
}

unsigned long get_global_score(void)
{
	DATA *data = get_data(NULL);

	return (data->time_score + data->hint_score);
}