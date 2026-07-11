#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUL '\0'

int main(int argc, char **argv) {
        FILE* file;
        char buf[16];
        size_t bytes_read;
        int offset = 0;

        if (argc < 2) {
                fprintf(stderr, "usage: %s <file>\n", argv[0]);
                return 1;
        }

        if ((file = fopen(argv[1], "rb")) == NULL) {
                fprintf(stderr, "%s: %s\n", argv[1], strerror(errno));
                return 1;
        }

        while ((bytes_read = fread(buf, 1, 16, file)) > 0) {
                if (bytes_read < 16) {
                        for (int i = bytes_read; i < 16; i++)
                                buf[i] = NUL;
                }

                printf("%08X: ", (unsigned int)(offset));

                for (int i = 0; i < 16; i++) {
                        printf("%02X ", (unsigned char)buf[i]);
                }
                printf(" ");

                for (int i = 0; i < bytes_read; i++) {
                        unsigned char c = buf[i];
                        printf("%c", isprint(c) ? c : '.');
                }
                printf("\n");

                offset += 16;
        }

        return 0;
}

