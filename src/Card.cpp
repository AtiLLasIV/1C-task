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
    {'A', 1}, {'6', 2}, {'7', 3}, {'8', 4},
    {'9', 5}, {'J', 6}, {'Q', 7}, {'K', 8}
};