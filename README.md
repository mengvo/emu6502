# emu6502

This is a minimalist 6502 CPU emulator written in C. This project primarily serves as a learning exercise for understanding low-level CPU emulation, memory interaction, and software architecture fundamentals. The ultimate goal is to build the foundational skills necessary to emulate more complex systems, such as the Game Boy.

Currently, the emulator supports:
- **LDA Immediate (`LDA #imm`)** instruction
- **Basic memory management**
- **Unit testing framework** for the CPU and memory components

> This project is in its very early stages and is not a complete 6502 emulator.
> I will be discontinuing this project as I feel its prepared me enough

## How to Build and Run

### Requirements
- GCC or any standard C compiler
- `make` utility

### Build/Run the Emulator and Tests

```bash
make        # builds the emulator
make run    # runs the emulator
make test   # builds and runs the test runner
```
