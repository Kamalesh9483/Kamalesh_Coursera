#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Make file for HOST and MSP432
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      build, clean, compile-all
#
# Platform Overrides:
#      HOST, MSP432
#
#------------------------------------------------------------------------------
include sources.mk

# Architectures Specific Flags
LINKER_FILE = 
CPU = cortex-m4
ARCH = 
SPECS = 

ifeq ($(PLATFORM),HOST)
# Compiler Flags and Defines for HOST
	CC = gcc
	LD = 
	LDFLAGS = -Xlinker -Map=c1m2.map
	CFLAGS = -g -Wall -Werror -O0 -std=c99
	PFLAG = -DHOST
		
else
# Compiler Flags and Defines for MSP432
	CC = arm-none-eabi-gcc
	LD = msp432p401r
	LDFLAGS = -T msp432p401r.lds -Xlinker -Map=c1m2.map
	CFLAGS = -g -Wall -Werror -O0 -std=c99 -mcpu=cortex-m4 -mthumb\
				-march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16\
				--specs=nosys.specs
	CPPFLAGs =
	PFLAG = -DMSP432
endif

OBJS:=$(SOURCES:.c=.o)
DEPS:=$(SOURCES:.c=.d)

%.i: $(SOURCES)
	$(CC) $(CFLAGS) $(LDFLAGS) $(PFLAG) -E $(INCLUDES) $^

%.asm: $(SOURCES) 
	$(CC) $(CFLAGS) $(LDFLAGS) $(PFLAG) -S $(INCLUDES) $^

%.o: $(SOURCES)
	$(CC) $(CFLAGS) $(LDFLAGS) $(PFLAG) $(INCLUDES) -c $^

%.d: $(SOURCES)
	$(CC) $(CCFLAGS) -MF"$@" -MG -MM -MP -MT"$@" -MT"$(<:.c=.o)" "$<"

.PHONY: compile-all
compile-all: 
	$(CC) $(CFLAGS) $(LDFLAGS) $(PFLAG) -c $(INCLUDES) $(SOURCES)

.PHONY: build
build: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o c1m2.out $(OBJS)

.PHONY: clean
clean:
	rm -rf *.o *.s *.out *.i *.map *.d
