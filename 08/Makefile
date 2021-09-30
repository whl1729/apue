ROOT=..
include $(ROOT)/Make.defines

PROGS = getpid fork vfork abort divide_zero exit orphan zombie \
		wait_no_child various_exit waitpid twice_fork waitid \
		wait4 race echoall exec setuid mypasswd exec_interpreter_file \
		mysystem test_system generate_accounting_data pracct getlogin \
		test_nice test_times

all: clean $(PROGS)

$(PROGS): $(LIBAPUE)
		$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o *.out foo bar

include $(ROOT)/Make.libapue.inc
