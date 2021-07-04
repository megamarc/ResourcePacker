#include <stdint.h>
#include "ResPack.h"

//#define KEY  NULL
#define KEY	"My_AES128_Key"

int main(int argc, char* argv[])
{
	uint32_t size = 0;
	ResPack_Build("list.txt", KEY);
	ResPack pack = ResPack_Open("list.dat", KEY);
	printf("%p\n", pack);
	char* as1 = ResPack_LoadAsset(pack, "background.png", &size);
	char* as2 = ResPack_LoadAsset(pack, "hero.txt", &size);
	char* as3 = ResPack_LoadAsset(pack, "jump.wav", &size);
	printf("as1 = %p\n", as1);
	printf("as2 = %p\n", as2);
	printf("as3 = %p\n", as3);
	printf(as2);
	ResPack_Close(pack);
}
