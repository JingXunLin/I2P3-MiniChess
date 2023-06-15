#include <cstdlib>
<<<<<<< HEAD
#include <fstream>
=======

>>>>>>> parent of fddce1a (完成minimax和alphabeta)
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
<<<<<<< HEAD
	int mx = -2e9, ret = 0;

	for(int i=0; i<actions.size(); i++)
	{
		State *child = state->next_state(actions[i]);
		int value = dfs(child, depth, -2e9, 2e9, 0);
		if(mx < value)
=======
	int mx = -2e9, mn = 2e9;
	Move ret;
	for(auto next_move: actions)
	{
		State *child = state->next_state(next_move);
		int value = dfs(child, depth, int(-2e9), int(2e9), state->player);
		if(state->player && mx < value)
>>>>>>> parent of fddce1a (完成minimax和alphabeta)
		{
			mx = value;
			ret = i;
		}
	}
<<<<<<< HEAD

	return actions[ret];
=======
	return ret;
>>>>>>> parent of fddce1a (完成minimax和alphabeta)
}
int alphabeta::dfs(State *state, int depth, int alpha, int beta, int maximizingPlayer)
{
	if(depth == 0)
		return state->evaluate();
	auto actions = state->legal_actions;
<<<<<<< HEAD

	int ret = 0;
	if(maximizingPlayer)
	{
		ret = -2e9;
		for(int i=0; i<actions.size(); i++)
=======
	int ret;
	if(maximizingPlayer)
	{
		ret = -2e9;
		for(auto next_move: actions)
>>>>>>> parent of fddce1a (完成minimax和alphabeta)
		{
			State *child = state->next_state(actions[i]);
			ret = max(ret, dfs(child, depth-1, alpha, beta, !maximizingPlayer));
			alpha = max(alpha, ret);
			if(alpha >= beta)
				break;
		}
	}
	else
	{
		ret = 2e9;
<<<<<<< HEAD
		for(int i=0; i<actions.size(); i++)
=======
		for(auto next_move: actions)
>>>>>>> parent of fddce1a (完成minimax和alphabeta)
		{
			State *child = state->next_state(actions[i]);
			ret = min(ret, dfs(child, depth-1, alpha, beta, !maximizingPlayer));
			beta = min(beta, ret);
			if(alpha >= beta)
				break;
		}
	}
<<<<<<< HEAD

=======
>>>>>>> parent of fddce1a (完成minimax和alphabeta)
	return ret;
}