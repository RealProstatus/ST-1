// Copyright 2025 UNN-CS

#include <gtest/gtest.h>
#include <cstdint>
#include <limits>
#include <stdexcept>

#include "alg.h"

// ==========================================
// Тесты для функции checkPrime
// ==========================================

TEST(CheckPrimeTest, NonPrimes) {
    EXPECT_FALSE(checkPrime(0));
    EXPECT_FALSE(checkPrime(1));
    EXPECT_FALSE(checkPrime(4));
    EXPECT_FALSE(checkPrime(9));
    EXPECT_FALSE(checkPrime(100));
    EXPECT_FALSE(checkPrime(49));
    EXPECT_FALSE(checkPrime(7921));
}

TEST(CheckPrimeTest, Primes) {
    EXPECT_TRUE(checkPrime(2));
    EXPECT_TRUE(checkPrime(3));
    EXPECT_TRUE(checkPrime(5));
    EXPECT_TRUE(checkPrime(7));
    EXPECT_TRUE(checkPrime(7919));
}

// ==========================================
// Тесты для функции nPrime
// ==========================================

TEST(NPrimeTest, SmallIndices) {
    EXPECT_EQ(nPrime(1), 2);
    EXPECT_EQ(nPrime(2), 3);
    EXPECT_EQ(nPrime(3), 5);
    EXPECT_EQ(nPrime(4), 7);
    EXPECT_EQ(nPrime(5), 11);
}

TEST(NPrimeTest, LargeIndices) {
    EXPECT_EQ(nPrime(100), 541);
    EXPECT_EQ(nPrime(1000), 7919);
}

TEST(NPrimeTest, InvalidArgument) {
    EXPECT_THROW(nPrime(0), std::invalid_argument);
}

// ==========================================
// Тесты для функции nextPrime
// ==========================================

TEST(NextPrimeTest, Logic) {
    // После простых
    EXPECT_EQ(nextPrime(2), 3);
    EXPECT_EQ(nextPrime(11), 13);

    // После составных
    EXPECT_EQ(nextPrime(4), 5);
    EXPECT_EQ(nextPrime(14), 17);
    EXPECT_EQ(nextPrime(20), 23);
}

TEST(NextPrimeTest, OverflowHandling) {
    uint64_t upperBound = std::numeric_limits<uint64_t>::max();

    EXPECT_THROW(nextPrime(upperBound), std::overflow_error);
    EXPECT_THROW(nextPrime(upperBound - 1), std::overflow_error);
}

// ==========================================
// Тесты для функции sumPrime
// ==========================================

TEST(SumPrimeTest, EdgeAndSmallBounds) {
    EXPECT_EQ(sumPrime(0), 0);
    EXPECT_EQ(sumPrime(1), 0);
    EXPECT_EQ(sumPrime(2), 0);
    EXPECT_EQ(sumPrime(10), 17);  // 2+3+5+7
    EXPECT_EQ(sumPrime(20), 77);  // 2+3+5+7+11+13+17+19
}

TEST(SumPrimeTest, MediumBounds) {
    EXPECT_EQ(sumPrime(100), 1060);
    EXPECT_EQ(sumPrime(1000), 76127);
}

TEST(SumPrimeTest, LargeBound) {
    // Проверка суммы для 1 млн
    EXPECT_EQ(sumPrime(1000000), 37550402023ull);
}
