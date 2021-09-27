# Simulate a Vexriscv and run a hello world in it.

Here is what you can do with this repo:
- Run a simulation of a Vexriscv.
- Connect GDB to the Vexriscv via OpenOCD.
- Compile a C "hello world" and load it into the Vexriscv.
- Step through the "hello world" with GDB and see the UART output.

## Prerequisites:

All the neccessary tools are contained in this Virtual Machine (VM):

[Virtual Machine](https://random-oracles.org/risc-v/)

Download the VM and follow the documentation for starting it up.

**This project is tested with the QuantumRisc VM 2.0.**

## How to do this?

Start the Virtual Machine. From here on you work inside the QuantumRisc Virtual Machine (VM). The VM is based on Ubuntu 20.04 LTS and has a Gnome desktop.

### 0: Clone this repository:
Open up a console and clone this respository.
```
git clone https://github.com/ThorKn/vexriscv-sim-helloworld.git
```

### 1: Build the Vexriscv and start the simulation:

Open up a console (Terminal). From the root folder of the repo, change to the folder ```vexriscv``` and start the Vexriscv Simulation. 
```
cd vexriscv
sbt "runMain mupq.PQVexRiscvSim"
```

### 2: Connect OpenOCD (The Vexriscv version) to the Simulation:

Open up a new console (the second one). From the root folder of the repo, change to the folder ```vexriscv``` and connect OpenOCD to the Vexriscv Simulation. The OpenOCD configuration is stored in the file ```vexriscvsim.cfg```.
```
cd vexriscv
openocd-vexriscv -f vexriscvsim.cfg
```

### 3: Build, upload and run the C application (a simple helloworld):

Open up a new console (the third one). From the root folder of the repo, change to the folder ```c_project```. Build the application via the Makefile. 
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

