#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "minilzo.h"

#define IN_LEN      (128*1024ul)
#define OUT_LEN     (IN_LEN + IN_LEN / 16 + 64 + 3)
static unsigned char __LZO_MMODEL in  [ IN_LEN ];
static unsigned char __LZO_MMODEL out [ OUT_LEN ];

#define HEAP_ALLOC(var,size) \
    lzo_align_t __LZO_MMODEL var [ ((size) + (sizeof(lzo_align_t) - 1)) / sizeof(lzo_align_t) ]

static HEAP_ALLOC(wrkmem, LZO1X_1_MEM_COMPRESS);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "usage: " << argv[0] << " path" << std::endl;
    return 1;
  }

  if (lzo_init() != LZO_E_OK) {
    printf("internal error - lzo_init() failed !!!\n");
    printf("(this usually indicates a compiler bug - try recompiling\nwithout "
           "optimizations, and enable '-DLZO_DEBUG' for diagnostics)\n");
    return 1;
  }

  int r = -1;
  lzo_uint in_len;
  lzo_uint out_len;
  lzo_uint new_len;

	FILE *fp_in = fopen("/bundle/target.compressed.js", "rb");
	FILE *fp_out = fopen("/bundle/target.decompressed.js", "wb");

  while (!feof(fp_in)) {
    in_len = IN_LEN;
    lzo_memset(in, 0, in_len);
    in_len = fread(in, 1, in_len, fp_in);
    new_len = in_len;
    r = lzo1x_decompress(out, out_len, in, &new_len, NULL);

    if (r != LZO_E_OK) {
      printf("internal error - decompression failed: %d\n", r);
      break;
    }
    printf("decompressed %lu bytes into %lu bytes\n", (unsigned long)in_len,
           (unsigned long)out_len);
    fwrite(out, 1, out_len, fp_out);
  }
  // std::string filename = "/bundle/target.compressed.js";

  // std::cout << "Opening file: " << filename << std::endl;
  // std::ifstream stream(filename);

  // if (stream.is_open()) {
  //   std::cout << "File opened" << std::endl;
  //   for (std::string line; std::getline(stream, line);) {
  //     std::cout << filename << ": " << line << std::endl;
  //   }

  // } else {
  //   std::cout << "Could not open file." << std::endl;
  // }

  return 0;
}