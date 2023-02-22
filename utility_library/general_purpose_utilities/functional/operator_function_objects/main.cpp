#include <iostream>

// define a function object that adds two values
struct plus {
    template <typename T>
    constexpr T operator()(const T &lhs, const T &rhs) const 
    {
        return lhs + rhs;
    }
};

// define a function object that subtracts two values
struct minus {
    template <typename T>
    constexpr T operator()(const T &lhs, const T &rhs) const 
    {
        return lhs - rhs;
    }
};

// define a function object that multiplies two values
struct multiplies {
    template <typename T>
    constexpr T operator()(const T &lhs, const T &rhs) const 
    {
        return lhs * rhs;
    }
};

// define a function object that divides two values
struct divides {
    template <typename T>
    constexpr T operator()(const T &lhs, const T &rhs) const 
    {
        return lhs / rhs;
    }
};

// define a function object that computes the remainder of two values
struct modulus {
    template <typename T>
    constexpr T operator()(const T &lhs, const T &rhs) const 
    {
        return lhs % rhs;
    }
};

// define a function object that negates a value
struct negate {
    template <typename T>
    constexpr T operator()(const T &val) const 
    {
        return -val;
    }
};

// define a function object to compare two values for equality
struct equal_to {
    template <typename T>
    constexpr bool operator()(const T &lhs, const T &rhs) const 
    {
        return lhs == rhs;
    }
};

// define a function object to compare two values for inequality
struct not_equal_to {
    template <typename T>
    constexpr bool operator()(const T &lhs, const T &rhs) const 
    {
        return lhs != rhs;
    }
};

// define a function object to compare two values for greater than
struct greater {
    template <typename T>
    constexpr bool operator()(const T &lhs, const T &rhs) const 
    {
        return lhs > rhs;
    }
};

// define a function object to compare two values for less than
struct less {
    template <typename T>
    constexpr bool operator()(const T &lhs, const T &rhs) const 
    {
        return lhs < rhs;
    }
};

// define a function object to compare two values for greater than or equal to
struct greater_equal {
    template <typename T>
    constexpr bool operator()(const T &lhs, const T &rhs) const 
    {
        return lhs >= rhs;
    }
};

// define a function object to compare two values for less than or equal to
struct less_equal {
    template <typename T>
    constexpr bool operator()(const T &lhs, const T &rhs) const 
    {
        return lhs <= rhs;
    }
};

// define a function object to compute the logical AND of two values
struct logical_and {
    template <typename T>
    constexpr bool operator()(const T &lhs, const T &rhs) const 
    {
        return lhs && rhs;
    }
};

// define a function object to compute the logical OR of two values
struct logical_or {
    template <typename T>
    constexpr bool operator()(const T &lhs, const T &rhs) const 
    {
        return lhs || rhs;
    }
};

// define a function object to compute the logical NOT of a value
struct logical_not {
    template <typename T>
    constexpr bool operator()(const T &val) const 
    {
        return !val;
    }
};

// define a function object to compute the logical XOR of two values
struct logical_xor {
    template <typename T>
    constexpr bool operator()(const T &lhs, const T &rhs) const 
    {
        return lhs ^ rhs;
    }
};

// define a function object to compute the bitwise AND of two values
struct bitwise_and {
    template <typename T>
    constexpr T operator()(const T &lhs, const T &rhs) const 
    {
        return lhs & rhs;
    }
};

// define a function object to compute the bitwise OR of two values
struct bitwise_or {
    template <typename T>
    constexpr T operator()(const T &lhs, const T &rhs) const 
    {
        return lhs | rhs;
    }
};

// define a function object to compute the bitwise XOR of two values
struct bitwise_xor {
    template <typename T>
    constexpr T operator()(const T &lhs, const T &rhs) const 
    {
        return lhs ^ rhs;
    }
};

// define a function object to compute the bitwise NOT of a value
struct bitwise_not {
    template <typename T>
    constexpr T operator()(const T &val) const 
    {
        return ~val;
    }
};




int main()
{
    std::cout << plus()(1, 2) << '\n';
    std::cout << minus()(1, 2) << '\n';
    std::cout << multiplies()(1, 2) << '\n';
    std::cout << divides()(1, 2) << '\n';
    std::cout << modulus()(1, 2) << '\n';
    std::cout << negate()(10) << '\n';
    std::cout << equal_to()(2, 2) << '\n';
    std::cout << not_equal_to()(2, 2) << '\n';
    std::cout << greater()(3, 2) << '\n';
    std::cout << less()(2, 3) << '\n';
    std::cout << greater_equal()(2, 2) << '\n';
    std::cout << less_equal()(2, 2) << '\n';
    std::cout << logical_and()(true, false) << '\n';
    std::cout << logical_or()(true, false) << '\n';
    std::cout << logical_not()(true) << '\n';
    std::cout << logical_xor()(false, true) << '\n';
    std::cout << bitwise_and()(0b1010, 0b1100) << '\n';
    std::cout << bitwise_or()(0b1010, 0b1100) << '\n';
    std::cout << bitwise_xor()(0b1010, 0b1100) << '\n';
    std::cout << bitwise_not()(0b1010) << '\n';

}
