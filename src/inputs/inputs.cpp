#include "inputs.h"

void FastInput(std::vector<std::vector<Card>>& stacks) {
  for (auto& stack : stacks) {
    for (size_t j = 0; j < 8; j++) {
      std::string card_str;
      std::cin >> card_str;
      stack.emplace_back(card_str);
    }
  }
}

void BeautyInput(std::vector<std::vector<Card>>& stacks) {
  std::cout << "Каждая кучка вводится снизу вверх (т.е как-будто мы кладём карты одну на одну" << std::endl;
  for (size_t i = 0; i < 8; i++) {
    std::cout << "Введите карты " << i + 1 << "-ой кучки:" << std::endl;
    for (size_t j = 0; j < 8; j++) {
      std::string card_str;
      std::cin >> card_str;
      stacks[i].emplace_back(card_str);
    }
  }
}