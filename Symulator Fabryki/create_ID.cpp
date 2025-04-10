#include "create_ID.h"

int create_ID()
{
	static int ID = 0;
	ID++;
	return ID;
}