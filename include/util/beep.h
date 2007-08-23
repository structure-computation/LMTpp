#ifndef BEEP_H
#define BEEP_H

#include <vector>

struct Beep {
    double *data;
    unsigned col;
    unsigned size;
};

struct LineOfBeeps {
    std::vector<Beep> small_size_beeps;
    std::vector<Beep> large_size_beeps;
};

void semi_morse_lsolve_( double *Y, unsigned nb_beep_lines, const LineOfBeeps *beep_lines ); ///
void semi_morse_ltsolve_( double *Y, unsigned nb_beep_lines, const LineOfBeeps *beep_lines ); ///

#endif //     BEEP_H
