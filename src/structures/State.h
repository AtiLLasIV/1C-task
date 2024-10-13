#ifndef STATE_H
#define STATE_H

#include <vector>
#include "Card.h"

class State {
 public:
  State(std::vector<std::vector<Card>> stacks, int move);

  std::vector<State> GetNeighboringStates();
  static bool IsInOrder(const std::vector<Card>& stack) ;
  void Cleaner();
  [[nodiscard]] bool IsAllStacksEmpty() const;

  [[nodiscard]] std::vector<std::vector<Card>> GetStacks() const;
  [[nodiscard]] int GetMove() const;

  bool operator<(const State& other) const;

 private:
  std::vector<std::vector<Card>> stacks_;
  int move_;
};

#endif //STATE_H
