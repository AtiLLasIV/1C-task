#include "bfs_solitaire.h"

int BFS_Solitaire(State& start) {
  std::queue<State> queue;
  std::set<State> visited;
  queue.push(start);
  visited.insert(start);

  while(!queue.empty()) {
    State current = queue.front();
    queue.pop();
    if (current.IsAllStacksEmpty()) {
      return current.GetMove();
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