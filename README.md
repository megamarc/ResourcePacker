# ResourcePacker
General purpose asset packer with optional AES-128 encryption

## Features
* Deploy all your assets in a single file
* Keeps original folder structure
* Retrieve assets from its original path inside the virtual filesystem
* Optional AES-128 encryption
* Used in Tilengine - 2D graphic engine

## Building
There's a simple makefile for building both the library and the command-line tool. It's hard-coded to use GNU gcc and make, so it requires standard build tools for linux, or mingw for windows. 

To build on linux:
```
make
```

To build on Windows: 
```
mingw32-make
```

If everything works as expected, directory lib will contain librespack.a and directory bin will contain respack command-line tool.
 
## Creating packages
To create asset package, the `respack` command-line tool is used:

```
respack input_list [aes_key]
  input_list : text file with list of assets, one per line
  aes_key    : optional AES-128 key for encryption
```

## Accessing package assets
To use created packages, include `librespack.a` and `include/ResPack.h` file inside your project. Test subproject shows example usage.

## Acknowledgements
This project uses AES128 encryption code by Brad Conte (brad@bradconte.com) and crc32 implementation by Gary S. Brown.
