#include <stdint.h>
#include <stdlib.h>
#include "ResPack.h"

int main(int argc, char* argv[])
{
	char* filename = NULL;
	char* passphrase = NULL;
	uint8_t retval = 3;
	
	filename = argv[1];
	if (argc == 3)
		passphrase = argv[2];
	
	printf("test %s %s\n", filename, passphrase);
	ResPack pack = ResPack_Open(filename, passphrase);
	if (pack)
	{
		uint32_t sizes[3] = {0};
		char* assets[3] = {0};
		int c = 0;
		
		/* load assets */
		assets[0] = ResPack_LoadAsset(pack, "assets/asset1.txt", &sizes[0]);
		assets[1] = ResPack_LoadAsset(pack, "assets/asset2.txt", &sizes[1]);
		assets[2] = ResPack_LoadAsset(pack, "assets/asset3.txt", &sizes[2]);
		
		/* show assets */
		for (c = 0; c < 3; c += 1)
		{
			if (assets[c])
			{
				printf("asset %d size = %d:\n", c + 1, sizes[c]);
				printf("  %s\n", assets[c]);
				free(assets[c]);
				retval -= 1;
			}
			else
				printf("unable to load asset %c!\n", c + 1);
		}
		ResPack_Close(pack);
	}
	else
		printf("Unable to load resources!\n");
	
	return retval;
}
