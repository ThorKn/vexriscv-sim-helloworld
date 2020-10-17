# Color definitions -------------------------------

NO_COLOR="\033[0m"
RED="\033[38;5;009m"
GREEN="\033[38;5;010m"
YELLOW="\033[38;5;011m"
ORANGE="\033[38;5;214m"
LIGHTPURPLE="\033[38;5;177m"
PURPLE="\033[38;5;135m"
CYAN="\033[38;5;014m"
LIGHTBLUE="\033[38;5;39m"
BLUE="\033[38;5;75m"
DARKBLUE="\033[38;5;33m"
LIGHTGRAY="\033[38;5;252m"
DARKGRAY="\033[38;5;242m"
BRIGHTRED="\033[91m"
BOLD="\033[1m"

# PATHS (adapt to your system)----------------------

PATH_RISCV=/opt/riscv/
PATH_RISC_BIN=$(PATH_RISCV)bin/
PATH_VERILATOR_BIN?=/usr/local/bin/verilator
PREFIX?=$(PATH_RISC_BIN)riscv64-unknown-elf

# TOOLS --------------------------------------------

AR?=$(PREFIX)-ar
GCC?=$(PREFIX)-gcc
CLANG=clang
GDB?=$(PREFIX)-gdb
OBJDUMP?=$(PREFIX)-objdump
OBJCOPY?=$(PREFIX)-objcopy
RISCVPATH=$(PATH_RISCV)riscv64-unknown-elf
OPENOCD?=$(PATH_RISC_BIN)openocd
ECHO?=echo

# GCC FLAGS ---------------------------------------

CC=$(GCC)

GCC_CFLAGS_COMMON := -g \
                     -O3 \
                     -fno-builtin-printf \
				     -Wno-unused-parameter \
				     -Wall -Wextra -Wredundant-decls \
				     -Wshadow -Wno-unused-function \
				     -fno-common \
				     -I$(RISCVPATH)/include

GCC_CFLAGS_MURAX=-fstrict-volatile-bitfields --specs=nosys.specs

RISCV_ARCH?=rv32im
RISCV_ABI?=ilp32
RISCV_CMODEL?=medany
RISCV_ARCHFLAGS +=-march=$(RISCV_ARCH)
RISCV_ARCHFLAGS +=-mabi=$(RISCV_ABI)
RISCV_ARCHFLAGS +=-mcmodel=$(RISCV_CMODEL)
GCC_RISCV_ARCHFLAGS=$(RISCV_ARCHFLAGS)

CFLAGS  += $(GCC_CFLAGS_COMMON) \
           $(GCC_CFLAGS_MURAX) \
           $(GCC_RISCV_ARCHFLAGS)

# Linker flags --------------------------------------

PLATFORM ?= pqvexriscvsim

LDSCRIPT = $(PLATFORM).ld
LDFLAGS  = -L$(RISCVPATH)/lib/rv32imac/ilp32
LDFLAGS += $(GCC_RISCV_ARCHFLAGS)
LDFLAGS += --specs=nosys.specs
LDFLAGS += -Wl,-T$(LDSCRIPT)
LDFLAGS += -nostartfiles -ffreestanding -Wl,--gc-sections
LDFLAGS += -L.
LDFLAGS += -Wl,--start-group -l$(PLATFORM)bsp -lc -Wl,--end-group

# Object files --------------------------------------

SDK_ASM_SRCS   := $(wildcard *.S)
SDK_C_SRCS     := $(wildcard *.c)
SDK_C_OBJS     := $(SDK_C_SRCS:.c=.o)
SDK_ASM_OBJS   := $(SDK_ASM_SRCS:.S=.o)
SDK_OBJS       := $(SDK_C_OBJS) $(SDK_ASM_OBJS)

# Target all ----------------------------------------

.PHONY: all
all: main.hex main.bin

# LIBWRAP 

include vexriscv/vexriscv.mk

# Targets --------------------------------------------

main.bin: main
	@$(ECHO) $(PURPLE)"obj "$@""$(LIGHTGRAY)
	$(OBJCOPY) -O binary $< $@

main.hex: main
	@$(ECHO) $(PURPLE)"obj "$@""$(LIGHTGRAY)
	$(OBJCOPY) -O ihex $< $@

main: $(LIBWRAP) $(SDK_OBJS) $(LDSCRIPT)
	@$(ECHO) $(LIGHTPURPLE)"building "$@""$(LIGHTGRAY)
	$(GCC) $(GCC_RISCV_ARCHFLAGS) $(GCC_CFLAGS_COMMON) $(SDK_OBJS) -o $@ $(LDFLAGS)

%.o: %.S
	@$(ECHO) $(ORANGE)"building "$@" (.S)"$(LIGHTGRAY)
	$(CC) $(CFLAGS) -c -o $@ $^

%.o: %.c
	@$(ECHO) $(ORANGE)"building "$@" (.c)"$(LIGHTGRAY)
	$(CC) $(CFLAGS) -c -o $@ $^

.PHONY: clean
clean:
	@$(ECHO) $(RED)"cleaning..."$(LIGHTGRAY)
	rm -f main main.bin main.hex $(SDK_OBJS) $(LIBWRAP_OBJS) $(LIBWRAP)

help:
	@$(ECHO) $(RED)"Compile & Simulate"$(LIGHTGRAY)
	@$(ECHO) $(LIGHTGRAY)"1. "$(CYAN)"make"$(LIGHTGRAY)
	@$(ECHO) $(LIGHTGRAY)"2. open 3 terminals"$(LIGHTGRAY)
	@$(ECHO) $(LIGHTGRAY)"3. Terminal 2: "$(CYAN)"make startsim"$(LIGHTGRAY)
	@$(ECHO) $(LIGHTGRAY)"4. Terminal 3: "$(CYAN)"make openocd"$(LIGHTGRAY)
	@$(ECHO) $(LIGHTGRAY)"5. Terminal 1: "$(CYAN)"make flash"$(LIGHTGRAY)

# Targets for starting simulation, openocd and gdb ----------------------------

# startsim:
#	cd ../Building_Tools/pqriscv-vexriscv/ ; sbt "runMain mupq.PQVexRiscvSim --ram 256,128"

# openocd:
#	cd ../Building_Tools/pqriscv-vexriscv/ ; /opt/verilator/bin/openocd --file pqvexriscvsim.cfg

#flash:
#	/opt/riscv/bin/riscv64-unknown-elf-gdb -ex 'set remotetimeout 15' -ex 'target remote :3333' -ex 'load' -ex 'break main' -ex 'continue' main

