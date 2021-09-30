ROOT=..
include $(ROOT)/Make.defines

PROGS = stat lstat fstatat file_type access umask chmod truncate \
		link unlink unlinkat open_and_unlink remove rename symlink futimens \
		mkdir rmdir ftw chdir_getcwd \
		4_1_file_type 4_2_umask 4_6_cp 4_11_ftw 4_16_dir_loop 4_17_unlink_creat

all: $(PROGS)

$(PROGS): $(LIBAPUE) $(PROGS).c
		$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAG) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o *.out foo bar

include $(ROOT)/Make.libapue.inc
