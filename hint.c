#include "inc/hints.h"

void	adjust_level_hint(DATA *data)
{
	data->level_hint_stat += 1;
	if (data->level == 1)
	{
		if (data->level_hint_stat == HINTS_L1)
			data->level_hint_stat = 0;
		if (data->max_used_hints < HINTS_L1)
			data->max_used_hints += 1;
	}
	else if (data->level == 2)
	{
		if (data->level_hint_stat == HINTS_L2)
			data->level_hint_stat = 0;
		if (data->max_used_hints < HINTS_L2)
			data->max_used_hints += 1;
	}
	else if (data->level == 3)
	{
		if (data->level_hint_stat == HINTS_L3)
			data->level_hint_stat = 0;
		if (data->max_used_hints < HINTS_L3)
			data->max_used_hints += 1;
	}
}

char	*hint(int level, int num)
{
	switch(level)
	{
		case 1:
			switch (num)
			{
				case 0:
					return ("Hint 1 for level : 1");
				case 1:
					return ("Hint 2 for level : 1");
			}
		case 2:
			switch (num)
			{
				case 0:
					return ("Hint 1 for level : 2");
				case 1:
					return ("Hint 2 for level : 2");
				case 2:
					return ("Hint 3 for level : 2");
			}
		case 3:
			switch (num)
			{
				case 0:
					return ("Hint 1 for level : 3");
			}
	}
	return (0);
}

void	get_hint(void)
{
	DATA *data = get_data(NULL);
	if (data->level < 1 || data->level > 3)
		return ;
	ft_printfd(1, "Your hint : [%s]\n", hint(data->level, data->level_hint_stat));
	adjust_level_hint(data);
}