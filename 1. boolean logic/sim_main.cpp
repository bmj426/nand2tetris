#include "Vnand_gate.h"
#include "verilated.h"
#include <cstdio>

int main(int argc, char** argv) 
{
    Verilated::commandArgs(argc, argv);
    
    Vnand_gate* dut = new Vnand_gate;

    int combos[4][2] = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1}
    };

    for (int i = 0; i < 4; i++) {
        dut->a = combos[i][0];
        dut->b = combos[i][1];
        dut->eval();
        printf("a: %d, b: %d => out: %d\n", dut->a, dut->b, dut->y);
    }
    delete dut;
    return 0;
}