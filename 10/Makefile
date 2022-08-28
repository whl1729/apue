ROOT=..
include $(ROOT)/Make.defines

PROGS = divide_zero access_null_ptr abort ignore_abort handle_abort \
		handle_term signal_returns sigusr two_handlers sleep1 sleep2 \
		sleep2_sigint read_timeout read_timeout_jmp pr_mask sigpending \
		sigsetjmp sigsetjmp_0 setjmp sigsuspend sigsuspend_quit \
		abort_catch abort_longjmp stop_and_kill system_ed mysystem_ed \
		psignal strsignal

all: clean $(PROGS)

$(PROGS): $(LIBAPUE)
		$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o *.out foo bar

include $(ROOT)/Make.libapue.inc
