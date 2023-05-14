#ifndef CHIP8EMULATOR_CHIP8_H
#define CHIP8EMULATOR_CHIP8_H


#include <cstdint>


void Chip8();

// stuff to keep emulator working properly
typedef struct {
    int window_height;
    int window_width;
    int scale_factor;
} configuration_t;

// hold possible emulator states
typedef enum {
    QUIT,
    PAUSED,
    RUNNING,
} eml_state_t;

// instruction type. making it easier to
// see each part of the opcode.
typedef struct {
    uint16_t opcode;
    uint16_t NNN;
    uint8_t NN;
    uint8_t N;
    uint8_t X;
    uint8_t Y;
} instruction_t;

// chip8 machine:
// holds registers, ram, etc...
typedef struct {
    uint8_t REG[16];        // 16 general purpose registers
    uint16_t I;             // index or address register (actually 12 bits wide)
    uint16_t PC;            // program counter
    uint8_t RAM[4096];      // RAM, use array here
    uint16_t STACK[12];     // "12-levels of nesting"

    uint8_t delay_timer;
    uint8_t sound_timer;



} chip8_t;

#endif //CHIP8EMULATOR_CHIP8_H
