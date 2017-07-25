CC = gcc

SOURCE_FILE = ../common/src/file_op.c
SOURCE_FILE += ../hex_bin_convert/src/hex_bin_convert.c

CFLAGS = -I../common/inc
CFLAGS += -I../hex_bin_convert/inc
CFLAGS += -g3

hbconvert::
	$(CC) $(SOURCE_FILE) h_b_convert.c $(CFLAGS) -o $@
