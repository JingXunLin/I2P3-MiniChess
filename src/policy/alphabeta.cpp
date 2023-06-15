#include <cstdlib>
#include <unistd.h>

#include "../state/state.hpp"
#include "./alphabeta.hpp"

int dfs(State *state, int depth, int alpha, int beta, bool maximizingPlayer)
{
	if(depth == 0)
		return state->evaluate();

	auto actions = state->legal_actions;

	int ret = 0;
	if(maximizingPlayer)
	{
		ret = -2e9;
		for(int i=0; i<actions.size(); i++)
		{
			ret = std::max(ret, dfs(state->next_state(actions[i]), depth-1, alpha, beta, false));
			alpha = std::max(alpha, ret);
			if(alpha >= beta)
				break;
		}
	}
	else
	{
		ret = 2e9;
		for(int i=0; i<actions.size(); i++)
		{
			ret = std::min(ret, dfs(state->next_state(actions[i]), depth-1, alpha, beta, true));
			beta = std::min(beta, ret);
			if(alpha >= beta)
				break;
		}
	}

	return ret;
}
/**
 * @brief Get a legal action by Alpha-Beta Pruning Minimax
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */

Move alphabeta::get_move(State *state, int depth)
{
	if(!state->legal_actions.size())
    	state->get_legal_actions();
  
	auto actions = state->legal_actions;
	int mx = -2e9, ret = 0;

	for(int i=0; i<actions.size(); i++)
	{
		State *child = state->next_state(actions[i]);
		int value = dfs(child, depth, -2e9, 2e9, 0);
		if(mx < value)
		{
			mx = value;
			ret = i;
		}
	}

	return actions[ret];
}