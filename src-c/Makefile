# CS263 System Security: Secure Web Server
# This file includes automatic dependency tracking
all: parser server

# C-compiler settings
CC = gcc -std=c99 -g -ggdb3 -D_XOPEN_SOURCE

# Default optimization level
O ?= 3

# Flags and other libraries
override CFLAGS += -Wall -Wextra -pedantic -pthread -O$(O) -I$(INCLUDES)
LDFLAGS =
LIBS =
INCLUDES = http-parser

####### Automatic dependency magic #######
# Set-up dependency directory
DEPSDIR := .deps
BUILDSTAMP := $(DEPSDIR)/rebuildstamp
DEPFILES := $(wildcard $(DEPSDIR)/*.d)
ifneq ($(DEPFILES),)
include $(DEPFILES)
endif
DEPCFLAGS = -MD -MF $(DEPSDIR)/$*.d -MP

# Dependency compilation
ifneq ($(DEP_CC),$(CC) $(CFLAGS) $(DEPCFLAGS) $(O))
DEP_CC := $(shell mkdir -p $(DEPSDIR); echo >$(BUILDSTAMP); echo "DEP_CC:=$(CC) $(CFLAGS) $(DEPCFLAGS) $(O)" >$(DEPSDIR)/_cc.d)
endif

# Make sure dependency directories are generated
$(DEPSDIR)/stamp $(BUILDSTAMP):
	mkdir -p $(@D)
	touch $@

####### Automatic dependency magic #######

%.o : %.c $(BUILDSTAMP)
	$(CC) $(CFLAGS) $(DEPCFLAGS) -O$(O) -o $@ -c $<

parser: $(BUILDSTAMP)
	$(MAKE) -C http-parser package

server: server.o http-parser/http_parser.o utils.o vector.o socket-base.o socket-systems.o sockets.o events.o
	$(CC) $(CFLAGS) $(DEPCFLAGS) -o $@ $^ $(LDFLAGS) $(LIBS)


clean:
	rm -f client server *.o *~ *.bak core *.core
	rm -rf .deps
	@$(MAKE) -s -C http-parser clean

distclean: clean
	rm -rf $(DEPSDIR)

.PHONY: all clean distclean
