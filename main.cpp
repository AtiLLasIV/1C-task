#include <vector>

#include "src/structures/Card.h"
#include "src/structures/State.h"
#include "src/algorithms/bfs_solitaire.h"
#include "src/inputs/inputs.h"

void Loop(bool is_beauty) {
  std::vector<std::vector<Card>> stacks(2);
  if (is_beauty) {
    BeautyInput(stacks);
  } else {
    FastInput(stacks);
  }

  State start_state(stacks, 0);
  int result = BFS_Solitaire(start_state);

  if (result == -1) {
    std::cout << "Нерешаемо" << std::endl;
  } else {
    std::cout << "Решается за " << result << " ходов" << std::endl;
  }
}

void ProgramLoop() {
  std::cout << "Данная программа определяет, возможно ли выиграть в пасьянс" << std::endl;
  std::cout << "Карты вводится в формате: ЗначениеМасть (к примеру JH - Валет Червей)" << std::endl;
  std::cout << "Значения: J - Валет, Q - Королева, K - Король, A - туз" << std::endl;
  std::cout << "(числа соответствуют сами себе)" << std::endl;
  std::cout << "-------------------------------" << std::endl;
  while(true) {
    std::cout << "Какой режим ввода Вы хотите выбрать: ускоренный(0), обычный(1), выйти из программы (exit)" << std::endl;
    std::string input_type;
    bool is_beauty;
    std::cin >> input_type;
    if (input_type == "exit") {
      break;
    }
    if (input_type == "0") {
      is_beauty = false;
    } else if (input_type == "1") {
      is_beauty = true;
    } else {
      continue;
    }
    Loop(is_beauty);
  }
}


int main() {
  ProgramLoop();
}
