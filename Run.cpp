#include "Pong.h"

int Run(void)
{
	Game a;
	a.initAll();
	a.setPlayer();
	a.setText();
	while (a.open)
	{
		a.setScoreAndLine();
		a.keys();
		a.EventAndRender();
		a.DeleteText();
	}
	a.DeleteAll();

	return 0;
}