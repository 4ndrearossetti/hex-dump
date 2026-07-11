# hex-dump

A minimal hex dumper in C — like `xxd` or `hexdump -C`. Prints the bytes of a
file as hex alongside their printable ASCII representation.

## Build

```sh
gcc -o main main.c
```

## Usage

```sh
./main <file>
```

## Example

```
00000000: 4C 6F 72 65 6D 20 69 70 73 75 6D 20 64 6F 6C 6F  Lorem ipsum dolo
00000010: 72 20 73 69 74 20 61 6D 65 74 2C 20 63 6F 6E 73  r sit amet, cons
00000020: 65 63 74 65 74 75 72 20 61 64 69 70 69 73 63 69  ectetur adipisci
00000030: 6E 67 20 65 6C 69 74 2C 20 73 65 64 20 64 6F 20  ng elit, sed do 
00000040: 65 69 75 73 6D 6F 64 20 74 65 6D 70 6F 72 20 69  eiusmod tempor i
00000050: 6E 63 69 64 69 64 75 6E 74 20 75 74 20 6C 61 62  ncididunt ut lab
00000060: 6F 72 65 20 65 74 20 64 6F 6C 6F 72 65 20 6D 61  ore et dolore ma
00000070: 67 6E 61 20 61 6C 69 71 75 61 2E 0A 00 00 00 00  gna aliqua..
```

Each row shows the offset, 16 bytes in hex, then those bytes as ASCII —
non-printable characters are shown as `.`.

