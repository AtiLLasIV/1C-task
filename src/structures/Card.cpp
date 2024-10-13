#include "Card.h"

Card::Card(int value, char suit) : value_(value), suit_(suit) {}

Card::Card(const std::string& str) {
  if (str.substr(0, 2) == "10") {
    value_ = 10;
    suit_ = str[2];
  } else {
    value_ = value_dict_[str[0]];
    suit_ = str[1];
  }
}

bool Card::operator<(const Card& other) const {
  return value_ < other.value_;
}

std::unordered_map<char, int> Card::value_dict_ = {
    {'6', 1}, {'7', 2}, {'8', 3}, {'9', 4},
    {'J', 5}, {'Q', 6}, {'K', 7}, {'A', 8},
};