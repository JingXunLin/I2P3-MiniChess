#include <cstdlib>

#include "../state/state.hpp"
#include "./random.hpp"


/**
 * @brief Get a legal action by Alpha-Beta Pruning Minimax
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
Move minimax::get_move(State *state, int depth)
{
	if(!state->legal_actions.size())
    state->get_legal_actions();
  
	auto actions = state->legal_actions;
	int mx = -2e9;
	Move ret;
	for(auto next_move: actions)
	{
		State *child = next_state(next_move);
		if(mx < child->evaluate())
		{
			mx = child->evaluate();
			ret = next_move;
		}
	}
	return ret;
}
int minimax::dfs(State *state, int depth, bool maximizingPlayer)
{
	if(depth == 0 || isLeaf(state))
		return state->evaluate();
	auto actions = state->legal_actions;
	int ret;
	if(maximizingPlayer)
	{
		ret = -2e9;
		for(auto next_move: actions)
		{
			State *child = next_state(next_move);
			ret = max(ret, alphabeta(child, depth-1, alpha, beta, !maximizingPlayer));
		}
	}
	else
	{
		ret = 2e9;
		for(auto next_move: actions)
		{
			State *child = next_state(next_move);
			ret = min(ret, alphabeta(child, depth-1, alpha, beta, !maximizingPlayer));
		}
	}
	return ret;
}
