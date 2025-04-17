
# OpenOCD & Telnet Debugging Guide

## Introduction
This guide explains how to use OpenOCD with Telnet for debugging an ARM-based microcontroller. You will learn how to reset, flash, run, halt, and debug code using OpenOCD and Telnet commands.

---

## Prerequisites
Ensure you have the following installed and set up:

- **OpenOCD** installed on your system
- **A supported ARM microcontroller board**
- **A working OpenOCD configuration file**
- **Telnet client (Linux/macOS: built-in, Windows: use PuTTY or similar)**

---

## 1. Start OpenOCD

Before using Telnet, start OpenOCD with the correct configuration file:

```bash
openocd -f interface/<debug_adapter>.cfg -f target/<mcu_target>.cfg
```

Example:
```bash
openocd -f interface/stlink.cfg -f target/stm32f4x.cfg
```

If OpenOCD starts successfully, you should see output similar to:
```
Open On-Chip Debugger 0.11.0
Licensed under GNU GPL v2
For bug reports, read
http://openocd.org/doc/doxygen/bugs.html
```

---

## 2. Connect to OpenOCD via Telnet
Once OpenOCD is running, open a new terminal and connect via Telnet:

```bash
telnet localhost 4444
```

This opens an interactive OpenOCD shell where you can execute debugging commands.

---

## 3. Basic Debugging Commands

### **Reset and Halt the Microcontroller**
```bash
reset init   # Reset and initialize
reset halt   # Reset and halt execution
reset run    # Reset and continue execution
```

### **Flashing Code to the Microcontroller**

#### **Using ELF File (Recommended)**
```bash
program myprogram.elf verify reset
```
- **Flashes** the ELF file
- **Verifies** correctness
- **Resets** the board after flashing

#### **Using Raw Binary File**
If you have a `.bin` file, specify the flash memory address:
```bash
write_flash 0x08000000 myprogram.bin
```

To erase and verify:
```bash
write_flash erase 0x08000000 myprogram.bin verify
```

### **Running the Code**
```bash
resume        # Continue execution from current position
resume 0x08000000   # Start execution from a specific address
continue      # Continue execution after halt
```

### **Halting Execution**
```bash
halt          # Pause execution
```

---

## 4. Breakpoints & Stepping

### **Setting a Breakpoint**
```bash
bp <address>  # Set a hardware breakpoint at a specific address
bp 0x08000400 4 hw  # Example: Breakpoint at address 0x08000400
```

### **Removing a Breakpoint**
```bash
rbp <breakpoint-number>  # Remove a specific breakpoint
```

### **Step Execution**
```bash
stepi    # Step one assembly instruction
step     # Step one source line (if debug symbols available)
```

---

## 5. Inspecting Registers & Memory

### **Viewing Registers**
```bash
reg      # Display all CPU registers
reg pc   # Show only the Program Counter (PC)
```

### **Reading Memory**
```bash
mdw 0x20000000 10  # Read 10 words from address 0x20000000
```

### **Writing to Memory**
```bash
mww 0x20000000 0x12345678  # Write 0x12345678 to address 0x20000000
```

---

## 6. Debugging Information

### **Checking Flash Memory Info**
```bash
flash info 0  # Show flash memory details
```

### **Checking Target Status**
```bash
target state  # Show CPU state
```

---

## 7. Exiting OpenOCD & Telnet

### **Exit Telnet**
```bash
exit
```

### **Stop OpenOCD**
Press `Ctrl+C` in the OpenOCD terminal or terminate the process:
```bash
pkill openocd
```

---

## Summary of Key Commands

| Action | Command |
|--------|---------|
| Start OpenOCD | `openocd -f interface/<debug_adapter>.cfg -f target/<mcu_target>.cfg` |
| Connect via Telnet | `telnet localhost 4444` |
| Reset Board | `reset init` / `reset halt` / `reset run` |
| Flash ELF File | `program myprogram.elf verify reset` |
| Flash Binary File | `write_flash 0x08000000 myprogram.bin verify` |
| Run Code | `resume` / `continue` |
| Halt Execution | `halt` |
| Set Breakpoint | `bp <address>` |
| Remove Breakpoint | `rbp <num>` |
| Step Execution | `stepi` / `step` |
| View Registers | `reg` |
| Read Memory | `mdw <addr> <count>` |
| Write Memory | `mww <addr> <value>` |
| Check Flash Info | `flash info 0` |
| Exit Telnet | `exit` |

---

## Conclusion
This guide provides essential commands for debugging using OpenOCD and Telnet. By following these steps, you can efficiently flash, debug, and analyze your ARM microcontroller. 🚀

