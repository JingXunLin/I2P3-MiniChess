#include <cstdlib>

#include "../state/state.hpp"
#include "./minimax.hpp"

using namespace std;

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
	int mx = -2e9, mn = 2e9;
	Move ret;
	for(auto next_move: actions)
	{
		State *child = state->next_state(next_move);
		int value = dfs(child, depth, state->player);
		if(state->player && mx < value)
		{
			mx = value;
			ret = next_move;
		}
		if(!state->player && mn > value)
		{
			mn = value;
			ret = next_move;
		}
	}
	return ret;
}
int minimax::dfs(State *state, int depth, bool maximizingPlayer)
{
	if(depth == 0)
		return state->evaluate();
	auto actions = state->legal_actions;
	int ret;
	if(maximizingPlayer)
	{
		ret = -2e9;
		for(auto next_move: actions)
		{
			State *child = state->next_state(next_move);
			ret = max(ret, dfs(child, depth-1, !maximizingPlayer));
		}
	}
	else
	{
		ret = 2e9;
		for(auto next_move: actions)
		{
			State *child = state->next_state(next_move);
			ret = min(ret, dfs(child, depth-1, !maximizingPlayer));
		}
	}
	return ret;
}
