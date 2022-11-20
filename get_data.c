#include "inc/PicoShell.h"

DATA	*get_data(DATA	*data)
{
	static DATA	*s_data;
	if (data)
		s_data = data;
	return (s_data);
}
