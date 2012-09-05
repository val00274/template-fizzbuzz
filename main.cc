#include <iostream>

template<int n, bool fizz, bool buzz>
class FizzBuzzItem;

template<int n>
class FizzBuzzItem<n, true, true> {
public:
  inline static void print() {
    std::cout << "FizzBuzz" << std::endl;
  }
};
template<int n>
class FizzBuzzItem<n, true, false> {
public:
  inline static void print() {
    std::cout << "Fizz" << std::endl;
  }
};
template<int n>
class FizzBuzzItem<n, false, true> {
public:
  inline static void print() {
    std::cout << "Buzz" << std::endl;
  }
};
template<int n>
class FizzBuzzItem<n, false, false> {
public:
  inline static void print() {
    std::cout << n << std::endl;
  }
};

template<int n>
class FizzBuzz {
public:
  inline static void print_all() {
    FizzBuzz<n - 1>::print_all();
    FizzBuzzItem<n, n % 3 == 0, n % 5 == 0>::print();
  }
};
template<>
class FizzBuzz<1> {
public:
  inline static void print_all() {
    FizzBuzzItem<1, false, false>::print();
  }
};

int main() {
  FizzBuzz<100>::print_all();
  return 0;
}

