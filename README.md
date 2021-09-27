# vexriscv-sim-helloworld

Here is what you can do with this repo:
- Run a simulation of a Vexriscv.
- Connect GDB to the Vexriscv via OpenOCD.
- Compile a C "hello world" and load it into the Vexriscv.
- Step through the "hello world" with GDB and see the UART output.

# Prerequisites:

All the neccessary tools are contained in this Virtual Machine (VM):

[Virtual Machine](https://random-oracles.org/risc-v/)

Download the VM and follow the documentation for starting it up.


# How to do this?

Build the Vexriscv and start the simulation:

From the root of the repo, enter 
```
cd vexriscv
sbt "runMain mupq.PQVexRiscvSim"
```

Then connect OpenOCD to the Vexriscv (from a new console window, insider the folder ```vexriscv```):
```
cd vexriscv
openocd-vexriscv -f vexriscvsim.cfg
```

Now the Vexriscv is running and ready to take and run an application.
So you should open a new (the third one) console and change to the folder ```c_project``` and build the application:
```
cd c_project
make
```

After building you can upload the application (main) to the Vexriscv via GDB:
```
riscv64-unknown-elf-gdb -tui -ex 'set remotetimeout 15' -ex 'target remote :3333' -ex 'load' -ex 'break main' -ex 'continue' main
```

When the application is loaded, you might want to set another breakpoint in the endless-loop inside the main:
```
b 11
```

Then you can continue the program for one run of the loop with GDB:
```
c
```






