#ifndef CARD_H
#define CARD_H

#include <string>
#include <unordered_map>

class Card {
 public:
  Card(int value, char suit);
  Card(const std::string& str);
  bool operator<(const Card& other) const;

 private:
  int value_;
  char suit_;
  static std::unordered_map<char, int> value_dict_;
};

#endif // CARD_H
