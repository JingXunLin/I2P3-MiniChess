#include <cstdlib>
#include <iostream>
#include "../state/state.hpp"
#include "./alphabeta.hpp"

using namespace std;

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
	int mx = -2e9, mn = 2e9;
	Move ret=actions[0];
	for(auto &next_move: actions)
	{
		State *child = state->next_state(next_move);
		int value = dfs(child, depth, int(-2e9), int(2e9), child->player);
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
int alphabeta::dfs(State *state, int depth, int alpha, int beta, int maximizingPlayer)
{
	if(depth == 0)
		return state->evaluate();

	if(!state->legal_actions.size())
    	state->get_legal_actions();
	auto actions = state->legal_actions;

	int ret;
	if(maximizingPlayer)
	{
		ret = -2e9;
		for(auto &next_move: actions)
		{
			State *child = state->next_state(next_move);
			ret = max(ret, dfs(child, depth-1, alpha, beta, !maximizingPlayer));
			alpha = max(alpha, ret);
			if(alpha >= beta)
				break;
		}
	}
	else
	{
		ret = 2e9;
		for(auto &next_move: actions)
		{
			State *child = state->next_state(next_move);
			ret = min(ret, dfs(child, depth-1, alpha, beta, !maximizingPlayer));
			beta = min(beta, ret);
			if(alpha >= beta)
				break;
		}
	}
	
	return ret;
}