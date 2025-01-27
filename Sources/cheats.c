#include <3ds.h>
#include "cheats.h"
#include <stdbool.h>
#include "hid.h"
#include "values.h"
#include <string.h>

u32 offset = 0;
u32 data = 0;
u32 patch_address = 0;

void	Save_Whenever_You_Want(void)
{
	u32 kDown = hidKeysDown();
	offset = 0x00000000;
	WRITEU8(offset + 0x1E81000, 0x00);
	WRITEU8(offset + 0x1E81001, 0x00);
	if (is_pressed(kDown & KEY_ZR))
	{
		WRITEU8(offset + 0x1E81000, 0x01);
	}
	if (is_pressed(kDown & KEY_ZR))
	{
		WRITEU8(offset + 0x1E81001, 0x01);
	}
	if (READU16(offset + 0x1E81000) == 0x0101)
	{
		WRITEU32(offset + 0xA3103C, 0x31);
	}
	offset = 0x00000000;
	data = 0x00000000;
}

