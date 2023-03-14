#include "wc.h"

int main(int argc, const char * argv[]) {
    if (argc < 2) {
        printf("Error - Need Filename as argument!\n");
        return 1;
    }
    for (int idx = 1; idx < argc; ++idx) {
        if (print_wc(argv[idx])) {
            return 2;
        };
    }
    return 0;
}
