#include "State.h"

State::State(std::vector<std::vector<Card>> stacks, int move)
    : stacks(std::move(stacks)), move(move) { Cleaner(); }

std::vector<State> State::GetNeighboringStates() {
  std::vector<State> next_states;

  for (size_t i = 0; i < stacks.size(); ++i) {
    if (stacks[i].empty()) {
      continue;
    }
    Card from = stacks[i].back();
    for (size_t j = i + 1; j < stacks.size(); ++j) {
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

bool State::IsInOrder(const std::vector<Card>& stack) const {
  for (size_t i = 1; i < stack.size(); ++i) {
    if (!(stack[i] < stack[i - 1])) {
      return false;
    }
  }
  return true;
}

void State::Cleaner() {
  for (auto& stack : stacks) {
    if (stack.size() == 9 && IsInOrder(stack)) {
      stack.clear();
    }
  }
}

bool State::IsAllStacksEmpty() const {
  for (const auto& stack : stacks) {
    if (!stack.empty()) {
      return false;
    }
  }
  return true;
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