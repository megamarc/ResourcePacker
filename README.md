# ResourcePacker
General purpose asset packer with optional AES-128 encryption

## Features
* Deploy all your assets in a single file
* Keeps original folder structure
* Retrieve assets from its original path inside the virtual filesystem
* Optional AES-128 encryption
* Used in Tilengine - 2D graphic engine

## Creating packages
To create asset package, the `respack` command-line tool is used. Visual Studio 2017 project and precompiled binary for windows is supplied, can be built from source.

```
respack input_list [aes_key]\n");
  input_list : text file with list of assets, one per line\n");
  aes_key    : optional AES-128 key for encryption\n\n");
```
## Accessing package assets
To use created packages, include all contents inside the `src` folder and `include/ResPack.h` file inside your project. Test subproject shows example usage.

## Acknowledgements
This project uses AES128 encryption code by Brad Conte (brad@bradconte.com) and crc32 implementation by Gary S. Brown.