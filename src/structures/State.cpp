#include "State.h"

State::State(std::vector<std::vector<Card>> stacks, int move)
    : stacks_(std::move(stacks)), move_(move) { Cleaner(); }

std::vector<State> State::GetNeighboringStates() {
  std::vector<State> next_states;

  for (size_t i = 0; i < stacks_.size(); ++i) {
    if (stacks_[i].empty()) {
      continue;
    }
    Card from = stacks_[i].back();
    for (size_t j = i + 1; j < stacks_.size(); ++j) {
      if (stacks_[j].empty()) {
        continue;
      }
      Card to = stacks_[j].back();
      if (from < to) {
        std::vector<std::vector<Card>> new_stacks = stacks_;
        new_stacks[j].push_back(from);
        new_stacks[i].pop_back();
        next_states.emplace_back(new_stacks, move_ + 1);
      }
    }
  }
  return next_states;
}

bool State::IsInOrder(const std::vector<Card>& stack) {
  for (size_t i = 1; i < stack.size(); ++i) {
    if (!(stack[i] < stack[i - 1])) {
      return false;
    }
  }
  return true;
}

void State::Cleaner() {
  for (auto& stack : stacks_) {
    if (stack.size() == 9 && IsInOrder(stack)) {
      stack.clear();
    }
  }
}

bool State::IsAllStacksEmpty() const {
  for (const auto& stack : stacks_) {
    if (!stack.empty()) {
      return false;
    }
  }
  return true;
}

std::vector<std::vector<Card>> State::GetStacks() const{
  return stacks_;
}

int State::GetMove() const {
  return move_;
}

bool State::operator<(const State& other) const {
  if (stacks_ < other.GetStacks()) {
    return true;
  }
  if (stacks_ > other.GetStacks()) {
    return false;
  }
  return move_ < other.GetMove();
}