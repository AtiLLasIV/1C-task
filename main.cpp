#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <queue>

#include "Card.h"
#include "State.h"


int BFS_Solitaire(State& start) {
  std::queue<State> queue;
  std::set<State> visited;
  queue.push(start);
  visited.insert(start);

  while(!queue.empty()) {
    State current = queue.front();
    queue.pop();
    if (current.IsAllStacksEmpty()) {
      return current.move;
    }
    for (State& state : current.GetNeighboringStates()) {
      if (!visited.contains(state)) {
        visited.insert(state);
        queue.push(state);
      }
    }
  }
  return -1;
}


// для тестов
void FastInput(std::vector<std::vector<Card>>& stacks) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 9; j++) {
      std::string card_str;
      std::cin >> card_str;
      stacks[i].emplace_back(card_str);
    }
  }
}

// просто отдельно кучки раскладываем
void BeautyInput(std::vector<std::vector<Card>>& stacks) {
  // to-do
}

// Программа не выключается сама, только после exit, возможность несколько раз ввести разные ситуации
void ProgramLoop() {
  // to-do
}

int main() {
  /// Сделать функцию:
  std::vector<std::vector<Card>> stacks(8);
  FastInput(stacks);
  // BeautyInput(stacks);

  State start_state(stacks, 0);
  int result = BFS_Solitaire(start_state);

  if (result == -1) {
    std::cout << "Нерешаемо" << std::endl;
  } else {
    std::cout << "Решается за " << result << " ходов" << std::endl;
  }

}
