ROOT=..
include $(ROOT)/Make.defines

PROGS = fopen getc fgetc ungetc fgets fread ftell printf scanf \
		scanf_int scanf_string stdio_buffer tmpnam mkstemp fmemopen \
		5_1_setbuf 5_2_fgets 5_3_printf

all: clean $(PROGS)

$(PROGS): $(LIBAPUE)
		$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o *.out foo bar

include $(ROOT)/Make.libapue.inc
