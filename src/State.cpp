#include "State.h"

#include <queue>
#include <set>

State::State(std::vector<std::vector<Card>> stacks, int move)
    : stacks(std::move(stacks)), move(move) {}

std::vector<State> State::GetNeighboringStates() {
  std::vector<State> next_states;

  for (size_t i = 0; i < 8; ++i) {
    if (stacks[i].empty()) {
      continue;
    }
    Card from = stacks[i].back();
    for (size_t j = i + 1; j < 8; ++j) {
      if (stacks[j].empty()) {
        continue;
      }
      Card to = stacks[j].back();
      if (from < to) {
        std::vector<std::vector<Card>> new_stacks = stacks;
        new_stacks[j].push_back(from);
        new_stacks[i].pop_back();
        next_states.emplace_back(new_stacks, move + 1);
      }
    }
  }
  return next_states;
}

bool State::operator<(const State& other) const {
  if (stacks < other.stacks) {
    return true;
  }
  if (stacks > other.stacks) {
    return false;
  }
  return move < other.move;
}

bool State::IsAllStacksEmpty() const {
  for (const auto& stack : stacks) {
    if (!stack.empty()) {
      return false;
    }
  }
  return true;
}