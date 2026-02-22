// Copyright 2025 UNN-CS
#include <cstdint>
#include <stdexcept>
#include <limits>

#include "alg.h"

using namespace std;

#define MAXVAL numeric_limits<uint64_t>::max()

namespace
{
void checkAdditionOverflow(uint64_t a, uint64_t b) {
    if (a > MAXVAL - b) {
        throw overflow_error("Prime sum overflow detected");
    }
}
} // namespace

bool checkPrime(uint64_t value) {
    if (value < 2) {
        return false;
    }
    if (value == 2 || value == 3) {
        return true;
    }


    if (value % 2 == 0 || value % 3 == 0) {
        return false;
    }
    for (uint64_t i = 5; i * i <= value; i += 6) {
        if (value % i == 0 || value % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}

uint64_t nPrime(uint64_t n) {
    if (n == 0) {
        throw invalid_argument("Prime index n must be greater than 0");
    }

    uint64_t count = 0;
    uint64_t candidate = 2;

    while (count < n) {
        if (checkPrime(candidate)) {
            count++;
            if (count == n) {
                return candidate;
            }
        }
        
        if (candidate == MAXVAL) {
            throw overflow_error("Cannot find prime: search overflowed uint64_t");
        }
        candidate++;
    }
    
    return 0;
}

uint64_t nextPrime(uint64_t value) {
    if (value == MAXVAL ) {
        throw std::overflow_error("Input value is already uint64_t max, next prime cannot be found");
    }

    uint64_t candidate = value + 1;

    while (true) {
        if (checkPrime(candidate)) {
            return candidate;
        }

        if (candidate == MAXVAL) {
             throw overflow_error("Next prime exceeds uint64_t limits");
        }
        candidate++;
    }
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    
    if (hbound > 2) {
        sum = 2;
    }

    for (uint64_t i = 3; i < hbound; i += 2) {
        if (checkPrime(i)) {
            checkAdditionOverflow(sum, i);
            sum += i;
        }
    }
    
    return sum;
}
