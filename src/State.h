#ifndef STATE_H
#define STATE_H

#include <vector>
#include "Card.h"

class State {
 public:
  std::vector<std::vector<Card>> stacks;
  int move;

  State(std::vector<std::vector<Card>> stacks, int move);
  std::vector<State> GetNeighboringStates();
  bool operator<(const State& other) const;
  bool IsAllStacksEmpty() const;
};

#endif //STATE_H
