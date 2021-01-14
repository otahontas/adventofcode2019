#include <cassert>
#include <iostream>
#include <vector>
#include "aoc.h"

// Run program from puzzle input with initial input from puzzle. Report output that 
// is not 0, i.e diagnostic code.
int GetDiagnosticCode(std::vector<int> &puzzle_input, int initial_input) {
    aoc::IntCodeComp comp(puzzle_input);
    comp.AddInput(initial_input);
    comp.Run();
    int output = 0;
    while (output == 0) {
        output = comp.GetOutput();
    }
    return output;
}


void Test() {
    std::vector<int>example = { 1002,4,3,4,33 };
    aoc::IntCodeComp first_comp(example);
    first_comp.Run();
    assert(first_comp.ValueAtAddress(4) == 99);

    std::vector<int> larger_example = { 3,21,1008,21,8,20,1005,20,22,107,8,21,20,
                                        1006,20,31,1106,0,36,98,0,0,1002,21,125,
                                        20,4,20,1105,1,46,104, 999,1105,1,46,1101,
                                        1000,1,20,4,20,1105,1,46,98,99
    };
    int inputs[3] = {3,8,13};
    int outputs[3] = {999,1000,1001};
    for (int i = 0; i < 3; i++) {
        aoc::IntCodeComp comp(larger_example);
        comp.AddInput(inputs[i]);
        comp.Run();
        int output = comp.GetOutput();
        assert(output == outputs[i]);
    }
}

void Solve() {
    std::vector<int> puzzle_input = aoc::ReadInputToInts(5);
    aoc::Solution solution;
    solution.part_one = GetDiagnosticCode(puzzle_input, 1);
    solution.part_two = GetDiagnosticCode(puzzle_input, 5);
    std::cout << solution;
}

int main() {
    Test();
    Solve();
}
