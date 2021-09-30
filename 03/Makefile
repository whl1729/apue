ROOT=..
include $(ROOT)/Make.defines

PROGS = open lseek file_hole file_nohole io_efficiency write_exceed_limit \
		multi_write write_without_permission lseek_write excl dup two_write \
		one_write atoi read_file_flags set_file_flags sync_io_efficiency my_dup2 \
		open_twice stdout_stderr lseek_append alloc_fd

all: clean $(PROGS)

$(PROGS): $(LIBAPUE)
		$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAG) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o *.out file.hole file.nohole

include $(ROOT)/Make.libapue.inc
