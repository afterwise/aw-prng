
PROGRAMS += Test

TESTLIBS =

Test.%: test/libtest.%$(LIBSUF) $(patsubst %, extern/%$(EXESUF)$(LIBSUF), $(TESTLIBS))
	$(link)

