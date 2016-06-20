#include "stdafx.h"
#include "TTMS_SCU_Studio_Srv_Mod.h"

void Studio_Srv_Mod(STUDIO * studio, char NewName[], int row, int col)
{
	studio->data.colsCount = col;
	studio->data.rowsCount = row;
	strcpy_s(studio->data.name,30, NewName);
	Studio_Perst_Mod(studio);
}
