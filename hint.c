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
					return ("Parfois, des changement arrivent dans les dossiers !");
				case 1:
					return ("L'extension d'un fichier pourrait changer la donne ?");
			}
		case 2:
			switch (num)
			{
				case 0:
					return ("Oui tu as bien compris, lève toi !");
				case 1:
					return ("Serieusement ! le staff est a ton service pour te répondre!");
			}
		case 3:
			switch (num)
			{
				case 0:
					return ("Des fichiers t'attendent dans un dossier !");
				case 1:
					return ("'Remove me' signifie litteralement : 'Retire moi'");
			}
	}
	return (0);
}

void	get_hint(void)
{
	DATA *data = get_data(NULL);
	if (data->level < 1 || data->level > 3)
		return ;
	ft_printfd(1, "Votre indice : [#g%s#0]\n", hint(data->level, data->level_hint_stat));
	adjust_level_hint(data);
}