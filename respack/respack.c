#include "ResPack.h"

int main(int argc, char* argv[])
{
	int count;
	char* key = NULL;

	printf("respack - packages resources with optional AES-128 encryption\n");
	printf("built on %s %s\n", __DATE__, __TIME__);
	printf("(c) 2019-2021 megamarc\n\n");

	/* validate input */
	if (argc < 2)
	{
		printf("Syntax: respack input_list [aes_key]\n");
		printf("  input_list : text file with list of assets, one per line\n");
		printf("  aes_key    : optional AES-128 passphrase\n\n");
		return 0;
	}

	if (argc > 2)
		key = argv[2];
	count = ResPack_Build(argv[1], key);

	printf("%d assets packed\n\n", count);
	return 0;
}