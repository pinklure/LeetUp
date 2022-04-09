#include <array>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
  enum Character { Numeric, Dot, Sign, Ee, Alphabeta };

  enum State {
    Empty,
    PureDot,
    PureSign,
    Digit,
    tobeFloat,
    Float,
    tobePower,
    tobeSignPower,
    Power,
    SignDot,
    Fail,
  };

  const std::vector<std::vector<int>> Table{
      {State::Digit, State::PureDot, State::PureSign, State::Fail, State::Fail},
      {State::Float, State::Fail, State::Fail, State::Fail, State::Fail},
      {State::Digit, State::SignDot, State::Fail, State::Fail, State::Fail},
      {State::Digit, State::tobeFloat, State::Fail, State::tobePower,
       State::Fail},
      {State::Float, State::Fail, State::Fail, State::tobePower, State::Fail},
      {State::Float, State::Fail, State::Fail, State::tobePower, State::Fail},
      {State::Power, State::Fail, State::tobeSignPower, State::Fail,
       State::Fail},
      {State::Power, State::Fail, State::Fail, State::Fail, State::Fail},
      {State::Power, State::Fail, State::Fail, State::Fail, State::Fail},
      {State::Float, State::Fail, State::Fail, State::Fail, State::Fail}};

  std::size_t getCharType(char const c) {
    if (c >= '0' && c <= '9')
      return Character::Numeric;
    if (c == '.')
      return Character::Dot;
    if (c == '+' || c == '-')
      return Character::Sign;
    if (c == 'E' || c == 'e')
      return Character::Ee;

    return Character::Alphabeta;
    // should never come here
    abort();
  }

public:
  bool isNumber(string s) {
    int state = State::Empty;
    for (auto it : s) {
      if ((state = Table[state][getCharType(it)]) == State::Fail)
        return false;
    }

    switch (state) {
		case State::Empty:
    case State::PureDot:
    case State::PureSign:
    /* case State::tobeFloat: */
    case State::tobePower:
    case State::tobeSignPower:
    case State::SignDot:
      return false;
    default:
      return true;
    }
  }
};

int main() {
  Solution test;
  /* std::cout << test.isNumber("123") << std::endl; */
  /* std::cout << test.isNumber("12.3") << std::endl; */
  /* std::cout << test.isNumber("+123") << std::endl; */
  /* std::cout << test.isNumber("+1.23") << std::endl; */
  /* std::cout << test.isNumber("-123") << std::endl; */
  /* std::cout << test.isNumber("-123.") << std::endl; */
  /* std::cout << test.isNumber("-123E12") << std::endl; */
  /* std::cout << test.isNumber("-12E3") << std::endl; */
  /* std::cout << test.isNumber("-123") << std::endl; */
  /* std::cout << test.isNumber("-123") << std::endl; */
  /* std::cout << test.isNumber("3.") << std::endl; */
  /* std::cout << test.isNumber("3.") << std::endl; */
  /* std::cout << test.isNumber("abc") << std::endl; */
  /* std::cout << test.isNumber("1a") << std::endl; */
  /* std::cout << test.isNumber("1e") << std::endl; */
  /* std::cout << test.isNumber("e3") << std::endl; */
  /* std::cout << test.isNumber("99e2.5") << std::endl; */
  /* std::cout << test.isNumber("--6") << std::endl; */
  /* std::cout << test.isNumber("-+3") << std::endl; */
  /* std::cout << test.isNumber("95a54e53") << std::endl; */
  /* std::cout << test.isNumber("+.") << std::endl; */
  /* std::cout << test.isNumber("+.e") << std::endl; */
  std::cout << test.isNumber("46.e3") << std::endl;
}

