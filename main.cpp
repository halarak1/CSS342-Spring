#include <iostream>

void test();
void test_power_of_two();
void test_is_prime();

class Fraction;

class Fraction {
public:
    int numerator;
    int denominator;

    Fraction(int numerator, int denominator): numerator(numerator), denominator(denominator) {}

    std::string to_string() {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }

    // operator overload
    bool operator == (Fraction &other) {
        return this->numerator == other.numerator &&
               this->denominator == other.denominator;
    }
};

Fraction reduce(Fraction input) {
    int divider = 2;
    while (divider <= input.numerator && divider <= input.denominator) {
        if (input.numerator % divider == 0 &&
            input.denominator % divider == 0) {
            input.numerator /= divider;
            input.denominator /= divider;
            continue;
        }
        divider++;
    }
    return input;
}

// Power of two - loop method
bool is_power_of_two_loop(int n) {
    if (n < 1) return false;
    while (n > 1) {
        if (n % 2 != 0) return false;
        n /= 2;
    }
    return true;
}

// Power of two - non-loop method
bool is_power_of_two_nonloop(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

// Prime number check
bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    test();
    test_power_of_two();
    test_is_prime();
}

// Test reduce()
void test() {
    Fraction inputs[4] = {
        Fraction(1, 2),
        Fraction(2, 4),
        Fraction(4, 2),
        Fraction(6, 8)
    };
    Fraction outputs[4] = {
        Fraction(1, 2),
        Fraction(1, 2),
        Fraction(2, 1),
        Fraction(3, 4)
    };

    for (int i = 0; i < 4; i++) {
        Fraction input = inputs[i];
        Fraction expect = outputs[i];
        Fraction actual = reduce(input);

        if (expect == actual) {
            std::cout << "PASS" << std::endl;
        } else {
            std::cout << "FAIL case is: " << input.to_string() << std::endl;
        }
    }
}

// Test is_power_of_two functions
void test_power_of_two() {
    int test_vals[] = {1, 2, 3, 4, 5, 8, 16, 18, 32, 33};
    bool expected[]  = {true, true, false, true, false, true, true, false, true, false};

    for (int i = 0; i < 10; i++) {
        bool result1 = is_power_of_two_loop(test_vals[i]);
        bool result2 = is_power_of_two_nonloop(test_vals[i]);

        if (result1 == expected[i] && result2 == expected[i]) {
            std::cout << "PASS" << std::endl;
        } else {
            std::cout << "FAIL case is: " << test_vals[i] << std::endl;
        }
    }
}

// Test is_prime
void test_is_prime() {
    int test_vals[] = {1, 2, 3, 4, 5, 6, 7, 9, 11, 15};
    bool expected[] = {false, true, true, false, true, false, true, false, true, false};

    for (int i = 0; i < 10; i++) {
        if (is_prime(test_vals[i]) == expected[i]) {
            std::cout << "PASS" << std::endl;
        } else {
            std::cout << "FAIL case is: " << test_vals[i] << std::endl;
        }
    }
}