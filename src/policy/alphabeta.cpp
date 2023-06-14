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
Move minimax::get_move(State *state, int depth, int alpha, int beta, bool maximizingPlayer)
{
	if(!state->legal_actions.size())
    state->get_legal_actions();
  
	auto actions = state->legal_actions;
	int alpha=-2e9 int beta=2e9;
	bool maximizingPlayer=state->player;

	Move
	for(auto next_move: actions)
		{
			ret = max(ret, alphabeta(next_move, depth-1, alpha, beta, !maximizingPlayer));
			alpha = max(alpha, ret);
			if(alpha >= beta)
				break;
		}
	return actions[(rand()+depth)%actions.size()];
}
int minimax::alphabeta(State *state, int depth, int alpha, int beta, bool maximizingPlayer)
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
			alpha = max(alpha, ret);
			if(alpha >= beta)
				break;
		}
	}
	else
	{
		ret = 2e9;
		for(auto next_move: actions)
		{
			State *child = next_state(next_move);
			ret = min(ret, alphabeta(child, depth-1, alpha, beta, !maximizingPlayer));
			beta = max(beta, ret);
			if(beta >= alpha)
				break;
		}
	}
	return ret;
}
bool minimax::isLeaf(State *state)
{
	return state->game_state;
}