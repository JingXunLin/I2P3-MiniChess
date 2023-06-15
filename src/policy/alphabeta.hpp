#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for Alpha-Beta Pruning Minimax policy, 
 */
class alphabeta{
public:
  static Move get_move(State *state, int depth);
};