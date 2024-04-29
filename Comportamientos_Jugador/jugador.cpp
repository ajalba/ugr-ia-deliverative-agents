#include "../Comportamientos_Jugador/jugador.hpp"
#include "motorlib/util.h"

#include <iostream>
#include <cmath>
#include <set>
#include <stack>

void DrawTerrain(const list<unsigned char> terrain) {
	auto it = terrain.begin();
	while (it != terrain.end()) {
		cout << *it << " ";
		it++;
	}
	cout << " view\n";
}

bool isAgentPosition(Ubication &agent, int row, int col) {
	return agent.col == col and agent.row == row;
}

bool colaboratorInVision(Ubication &playerUbication, Ubication &colaborator) {
	switch (playerUbication.compass)
	{
	case norte:
		return isAgentPosition(colaborator, playerUbication.row, playerUbication.col) or
		isAgentPosition(colaborator, playerUbication.row-1, playerUbication.col-1) or
		isAgentPosition(colaborator, playerUbication.row-1, playerUbication.col) or
		isAgentPosition(colaborator, playerUbication.row-1, playerUbication.col+1) or
		isAgentPosition(colaborator, playerUbication.row-2, playerUbication.col-2) or
		isAgentPosition(colaborator, playerUbication.row-2, playerUbication.col-1) or
		isAgentPosition(colaborator, playerUbication.row-2, playerUbication.col) or
		isAgentPosition(colaborator, playerUbication.row-2, playerUbication.col+1) or
		isAgentPosition(colaborator, playerUbication.row-2, playerUbication.col+2) or
		isAgentPosition(colaborator, playerUbication.row-3, playerUbication.col-3) or
		isAgentPosition(colaborator, playerUbication.row-3, playerUbication.col-2) or
		isAgentPosition(colaborator, playerUbication.row-3, playerUbication.col-1) or
		isAgentPosition(colaborator, playerUbication.row-3, playerUbication.col) or
		isAgentPosition(colaborator, playerUbication.row-3, playerUbication.col+1) or
		isAgentPosition(colaborator, playerUbication.row-3, playerUbication.col+2) or
		isAgentPosition(colaborator, playerUbication.row-3, playerUbication.col+3);
		break;
	case sur:

		return isAgentPosition(colaborator, playerUbication.row+1,playerUbication.col+1) or
		isAgentPosition(colaborator, playerUbication.row+1,playerUbication.col) or
		isAgentPosition(colaborator, playerUbication.row+1,playerUbication.col-1) or
		
		isAgentPosition(colaborator, playerUbication.row+2,playerUbication.col+2) or
		isAgentPosition(colaborator, playerUbication.row+2,playerUbication.col+1) or
		isAgentPosition(colaborator, playerUbication.row+2,playerUbication.col) or
		isAgentPosition(colaborator, playerUbication.row+2,playerUbication.col-1) or
		isAgentPosition(colaborator, playerUbication.row+2,playerUbication.col-2) or
		
		isAgentPosition(colaborator, playerUbication.row+3,playerUbication.col+3) or
		isAgentPosition(colaborator, playerUbication.row+3,playerUbication.col+2) or
		isAgentPosition(colaborator, playerUbication.row+3,playerUbication.col+1) or
		isAgentPosition(colaborator, playerUbication.row+3,playerUbication.col) or
		isAgentPosition(colaborator, playerUbication.row+3,playerUbication.col-1) or
		isAgentPosition(colaborator, playerUbication.row+3,playerUbication.col-2) or
		isAgentPosition(colaborator, playerUbication.row+3,playerUbication.col-3);
		break;
	case este:
		return isAgentPosition(colaborator, playerUbication.row-1, playerUbication.col+1) or
		isAgentPosition(colaborator, playerUbication.row, playerUbication.col+1) or
		isAgentPosition(colaborator, playerUbication.row+1, playerUbication.col+1) or
		isAgentPosition(colaborator, playerUbication.row-2, playerUbication.col+2) or
		isAgentPosition(colaborator, playerUbication.row-1, playerUbication.col+2) or
		isAgentPosition(colaborator, playerUbication.row, playerUbication.col+2) or
		isAgentPosition(colaborator, playerUbication.row+1, playerUbication.col+2) or
		isAgentPosition(colaborator, playerUbication.row+2, playerUbication.col+2) or
		isAgentPosition(colaborator, playerUbication.row-3, playerUbication.col+3) or
		isAgentPosition(colaborator, playerUbication.row-2, playerUbication.col+3) or
		isAgentPosition(colaborator, playerUbication.row-1, playerUbication.col+3) or
		isAgentPosition(colaborator, playerUbication.row, playerUbication.col+3) or
		isAgentPosition(colaborator, playerUbication.row+1, playerUbication.col+3) or
		isAgentPosition(colaborator, playerUbication.row+2, playerUbication.col+3) or
		isAgentPosition(colaborator, playerUbication.row+3, playerUbication.col+3);
		break;
	case oeste:
		return isAgentPosition(colaborator, playerUbication.row, playerUbication.col) or 
		isAgentPosition(colaborator, playerUbication.row+1, playerUbication.col-1) or 
		isAgentPosition(colaborator, playerUbication.row, playerUbication.col-1) or 
		isAgentPosition(colaborator, playerUbication.row-1, playerUbication.col-1) or 
		isAgentPosition(colaborator, playerUbication.row+2, playerUbication.col-2) or 
		isAgentPosition(colaborator, playerUbication.row+1, playerUbication.col-2) or 
		isAgentPosition(colaborator, playerUbication.row, playerUbication.col-2) or 
		isAgentPosition(colaborator, playerUbication.row-1, playerUbication.col-2) or 
		isAgentPosition(colaborator, playerUbication.row-2, playerUbication.col-2) or 
		isAgentPosition(colaborator, playerUbication.row+3, playerUbication.col-3) or 
		isAgentPosition(colaborator, playerUbication.row+2, playerUbication.col-3) or 
		isAgentPosition(colaborator, playerUbication.row+1, playerUbication.col-3) or 
		isAgentPosition(colaborator, playerUbication.row, playerUbication.col-3) or 
		isAgentPosition(colaborator, playerUbication.row-1, playerUbication.col-3) or 
		isAgentPosition(colaborator, playerUbication.row-2, playerUbication.col-3) or 
		isAgentPosition(colaborator, playerUbication.row-3, playerUbication.col-3);
		break;
	case noreste:
		return isAgentPosition(colaborator, playerUbication.row-1, playerUbication.col) or 
		isAgentPosition(colaborator, playerUbication.row-1, playerUbication.col+1) or 
		isAgentPosition(colaborator, playerUbication.row, playerUbication.col+1) or 

		isAgentPosition(colaborator, playerUbication.row-2, playerUbication.col) or 
		isAgentPosition(colaborator, playerUbication.row-2, playerUbication.col+1) or 
		isAgentPosition(colaborator, playerUbication.row-2, playerUbication.col+2) or 
		isAgentPosition(colaborator, playerUbication.row-1, playerUbication.col+2) or 
		isAgentPosition(colaborator, playerUbication.row, playerUbication.col+2) or 

		isAgentPosition(colaborator, playerUbication.row-3, playerUbication.col) or 
		isAgentPosition(colaborator, playerUbication.row-3, playerUbication.col+1) or 
		isAgentPosition(colaborator, playerUbication.row-3, playerUbication.col+2) or 
		isAgentPosition(colaborator, playerUbication.row-3, playerUbication.col+3) or 
		isAgentPosition(colaborator, playerUbication.row-2, playerUbication.col+3) or 
		isAgentPosition(colaborator, playerUbication.row-1, playerUbication.col+3) or 
		isAgentPosition(colaborator, playerUbication.row, playerUbication.col+3);
		break;
	
	case sureste:
		
		return isAgentPosition(colaborator, playerUbication.row, playerUbication.col+1) or 
		isAgentPosition(colaborator, playerUbication.row+1, playerUbication.col+1) or 
		isAgentPosition(colaborator, playerUbication.row+1, playerUbication.col) or 

		isAgentPosition(colaborator, playerUbication.row, playerUbication.col+2) or 
		isAgentPosition(colaborator, playerUbication.row+1, playerUbication.col+2) or 
		isAgentPosition(colaborator, playerUbication.row+2, playerUbication.col+2) or 
		isAgentPosition(colaborator, playerUbication.row+2, playerUbication.col+1) or 
		isAgentPosition(colaborator, playerUbication.row+2, playerUbication.col) or 

		isAgentPosition(colaborator, playerUbication.row, playerUbication.col+3) or 
		isAgentPosition(colaborator, playerUbication.row+1, playerUbication.col+3) or 
		isAgentPosition(colaborator, playerUbication.row+2, playerUbication.col+3) or 
		isAgentPosition(colaborator, playerUbication.row+3, playerUbication.col+3) or 
		isAgentPosition(colaborator, playerUbication.row+3, playerUbication.col+2) or 
		isAgentPosition(colaborator, playerUbication.row+3, playerUbication.col+1) or 
		isAgentPosition(colaborator, playerUbication.row+3, playerUbication.col); 
		break;
	case noroeste:
		return isAgentPosition(colaborator, playerUbication.row, playerUbication.col-1) or 
		isAgentPosition(colaborator, playerUbication.row-1, playerUbication.col-1) or 
		isAgentPosition(colaborator, playerUbication.row-1, playerUbication.col) or 

		isAgentPosition(colaborator, playerUbication.row, playerUbication.col-2) or 
		isAgentPosition(colaborator, playerUbication.row-1, playerUbication.col-2) or 
		isAgentPosition(colaborator, playerUbication.row-2, playerUbication.col-2) or 
		isAgentPosition(colaborator, playerUbication.row-2, playerUbication.col-1) or 
		isAgentPosition(colaborator, playerUbication.row-2, playerUbication.col) or 

		isAgentPosition(colaborator, playerUbication.row, playerUbication.col-3) or 
		isAgentPosition(colaborator, playerUbication.row-1, playerUbication.col-3) or 
		isAgentPosition(colaborator, playerUbication.row-2, playerUbication.col-3) or 
		isAgentPosition(colaborator, playerUbication.row-3, playerUbication.col-3) or 
		isAgentPosition(colaborator, playerUbication.row-3, playerUbication.col-2) or 
		isAgentPosition(colaborator, playerUbication.row-3, playerUbication.col-1) or 
		isAgentPosition(colaborator, playerUbication.row-3, playerUbication.col);
		break;
	
	case suroeste:
		return isAgentPosition(colaborator, playerUbication.row+1, playerUbication.col) or 
		isAgentPosition(colaborator, playerUbication.row+1, playerUbication.col-1) or 
		isAgentPosition(colaborator, playerUbication.row, playerUbication.col-1) or 

		isAgentPosition(colaborator, playerUbication.row+2, playerUbication.col) or 
		isAgentPosition(colaborator, playerUbication.row+2, playerUbication.col-1) or 
		isAgentPosition(colaborator, playerUbication.row+2, playerUbication.col-2) or 
		isAgentPosition(colaborator, playerUbication.row+1, playerUbication.col-2) or 
		isAgentPosition(colaborator, playerUbication.row, playerUbication.col-2) or 

		isAgentPosition(colaborator, playerUbication.row+3, playerUbication.col) or 
		isAgentPosition(colaborator, playerUbication.row+3, playerUbication.col-1) or 
		isAgentPosition(colaborator, playerUbication.row+3, playerUbication.col-2) or 
		isAgentPosition(colaborator, playerUbication.row+3, playerUbication.col-3) or 
		isAgentPosition(colaborator, playerUbication.row+2, playerUbication.col-3) or 
		isAgentPosition(colaborator, playerUbication.row+1, playerUbication.col-3) or 
		isAgentPosition(colaborator, playerUbication.row, playerUbication.col-3);
	
	default:
		break;
	}
	return false;
}

void DrawPlan(const list<Action> &plan) {
	auto it = plan.begin();
	while (it != plan.end()) {
		if (*it == actWALK) {
			cout << "W ";
		}
		else if (*it == actRUN) {
			cout << "R ";
		}
		else if (*it == actTURN_SR) {
			cout << "SR ";
		}
		else if (*it == actTURN_L) {
			cout << "L ";
		}
		else if (*it == act_CLB_WALK) {
			cout << "CLW ";
		}
		else if (*it == act_CLB_STOP) {
			cout << "CLSTOP ";
		}
		else if (*it == act_CLB_TURN_SR) {
			cout << "CLBSR ";
		}
		else if (*it == actIDLE) {
			cout << "I ";
		} else {
			cout << "-_ ";
		}
		it++;
	}
	cout << " (" << plan.size() << " acciones\n";
}

Ubication nextPlace(const Ubication &pos) {
	Ubication next = pos;
	switch (pos.compass)
	{
	case norte:
		next.row = pos.row - 1;
		break;
	case noreste:
		next.row = pos.row - 1;
		next.col = pos.col + 1;
		break;
	case este:
		next.col = pos.col + 1;
		break;
	case sureste:
		next.row = pos.row + 1;
		next.col = pos.col + 1;
		break;
	case sur:
		next.row = pos.row + 1;
		break;
	case suroeste:
		next.row = pos.row + 1;
		next.col = pos.col -1;
		break;
	case oeste:
		next.col = pos.col - 1;
		break;
	case noroeste:
		next.row = pos.row - 1;
		next.col = pos.col - 1;
		break;
	
	default:
		break;
	}
	return next;
}

void nullMatrix(vector<vector<unsigned char>> &matrix) {
	for (int i=0; i < matrix.size(); i++) {
		for (int j=0; j<matrix[0].size(); j++) {
			matrix[i][j] = 0;
		}
	}
}

void ComportamientoJugador::VisualizePlan(const StateLevel0 &st, const list<Action> &plan) {
	nullMatrix(mapaConPlan);
	StateLevel0 auxState = st;

	auto it = plan.begin();
	while (it != plan.end()) {
		if ((*it != act_CLB_WALK) and (*it != act_CLB_TURN_SR) and (*it != act_CLB_STOP)) {
			switch (auxState.colaboratorLastOrder)
			{
			case act_CLB_WALK:
				auxState.colaborator = nextPlace(auxState.colaborator);
				mapaConPlan[auxState.colaborator.row][auxState.colaborator.col] = 2;
				break;
			case act_CLB_TURN_SR:
				auxState.colaborator.compass = (Orientacion)((auxState.colaborator.compass + 1) % 8);
				break;
			}
		}

		switch (*it)
		{
		case actRUN:
			auxState.player = nextPlace(auxState.player);
			mapaConPlan[auxState.player.row][auxState.player.col] = 3;
			auxState.player = nextPlace(auxState.player);
			mapaConPlan[auxState.player.row][auxState.player.col] = 1;
			/* code */
			break;
		case actWALK:
			auxState.player = nextPlace(auxState.player);
			mapaConPlan[auxState.player.row][auxState.player.col] = 1;
			break;
		case actTURN_SR:
			auxState.player.compass = (Orientacion) ((auxState.player.compass + 1) % 8);
			break;
		case actTURN_L:
			auxState.player.compass = static_cast<Orientacion>((auxState.player.compass+6)%8);
			break;
		case act_CLB_WALK:
			auxState.colaborator = nextPlace(auxState.colaborator);
			auxState.colaboratorLastOrder = act_CLB_WALK;
			mapaConPlan[auxState.colaborator.row][auxState.colaborator.col] = 2;
			break;
		case act_CLB_TURN_SR:
			auxState.colaborator.compass = (Orientacion)((auxState.colaborator.compass + 1) % 8);
			auxState.colaboratorLastOrder = act_CLB_TURN_SR;
			break;
		case act_CLB_STOP:
			auxState.colaboratorLastOrder = act_CLB_STOP;
		default:
			break;
		}
		it++;
	}
}

void ComportamientoJugador::VisualizePlan(const StateLevel1 &st, const list<Action> &plan) {
	nullMatrix(mapaConPlan);
	StateLevel1 auxState = st;

	auto it = plan.begin();
	while (it != plan.end()) {
		if ((*it != act_CLB_WALK) and (*it != act_CLB_TURN_SR) and (*it != act_CLB_STOP)) {
			switch (auxState.colaboratorLastOrder)
			{
			case act_CLB_WALK:
				auxState.colaborator = nextPlace(auxState.colaborator);
				mapaConPlan[auxState.colaborator.row][auxState.colaborator.col] = 2;
				break;
			case act_CLB_TURN_SR:
				auxState.colaborator.compass = (Orientacion)((auxState.colaborator.compass + 1) % 8);
				break;
			}
		}

		switch (*it)
		{
		case actRUN:
			auxState.player = nextPlace(auxState.player);
			mapaConPlan[auxState.player.row][auxState.player.col] = 3;
			auxState.player = nextPlace(auxState.player);
			mapaConPlan[auxState.player.row][auxState.player.col] = 1;
			/* code */
			break;
		case actWALK:
			auxState.player = nextPlace(auxState.player);
			mapaConPlan[auxState.player.row][auxState.player.col] = 1;
			break;
		case actTURN_SR:
			auxState.player.compass = (Orientacion) ((auxState.player.compass + 1) % 8);
			break;
		case actTURN_L:
			auxState.player.compass = static_cast<Orientacion>((auxState.player.compass+6)%8);
			break;
		case act_CLB_WALK:
			auxState.colaborator = nextPlace(auxState.colaborator);
			auxState.colaboratorLastOrder = act_CLB_WALK;
			mapaConPlan[auxState.colaborator.row][auxState.colaborator.col] = 2;
			break;
		case act_CLB_TURN_SR:
			auxState.colaborator.compass = (Orientacion)((auxState.colaborator.compass + 1) % 8);
			auxState.colaboratorLastOrder = act_CLB_TURN_SR;
			break;
		case act_CLB_STOP:
			auxState.colaboratorLastOrder = act_CLB_STOP;
		default:
			break;
		}
		it++;
	}
}


bool isSolutionFoundLevel0(const StateLevel0 &state, const Ubication &final) {
	return state.player.row == final.row and state.player.col == final.col;
}

bool isSolutionFoundLevel1(const StateLevel1 &state, const Ubication &final) {
	// return (rand() % 28000 == 1)or(state.colaborator.row == final.row and state.colaborator.col == final.col);
	return (state.colaborator.row == final.row and state.colaborator.col == final.col);
}

bool isValidPlace(const Ubication &pos, const vector<vector<unsigned char>> map) {
	return (map[pos.row][pos.col] != 'P' and map[pos.row][pos.col] != 'M');
}

bool isSameUbication (const Ubication &pos1, const Ubication &pos2) {
	return pos1.row == pos2.row and pos1.col == pos2.col;
}

StateLevel0 apply(const Action &action, const StateLevel0 &state, const vector<vector<unsigned char>> map) {
	StateLevel0 result = state;
	Ubication oneStepUbication, twoStepsUbication;
	switch (action)
	{
	case actWALK:
		oneStepUbication = nextPlace(state.player);
		if (isValidPlace(oneStepUbication, map) and !isSameUbication(oneStepUbication, state.colaborator)) {
			result.player = oneStepUbication;
		}
		break;
	
	case actRUN:
		oneStepUbication = nextPlace(state.player);
		if (isValidPlace(oneStepUbication, map) and !isSameUbication(oneStepUbication, state.colaborator)) {
			twoStepsUbication = nextPlace(oneStepUbication);
			if (isValidPlace(twoStepsUbication, map) and !isSameUbication(twoStepsUbication, state.colaborator)) {
				result.player = twoStepsUbication;
			}
		}
		break;
	case actTURN_SR:
		result.player.compass = static_cast<Orientacion>((result.player.compass+1)%8);
		break;
	case actTURN_L:
		result.player.compass = static_cast<Orientacion>((result.player.compass+6)%8);
		break;
	default:
		break;
	}
	return result;
}

bool Find(const StateLevel0 &item, const list<NodeLevel0> &nodeList) {
	auto it = nodeList.begin();
	while (it != nodeList.end() and !(it->state == item)){
		it++;
	}
	return (it != nodeList.end());
}

list<Action> WidthSearchLevel0(const StateLevel0 &start, const Ubication &final, const vector<vector<unsigned char>> &mapa) {
	NodeLevel0 currentNode;
	list<NodeLevel0> frontier;
	set<NodeLevel0> explored;
	list<Action> plan;
	currentNode.state = start;

	frontier.push_back(currentNode);
	bool solutionFound = (currentNode.state.player.row == final.row and currentNode.state.player.col == final.col);

	while(!frontier.empty() and !solutionFound) {
		// Delete actual state from frontier and add state to explored
		frontier.pop_front();
		explored.insert(currentNode);

		// Child Node with action ACT_WALK
		NodeLevel0 child_walk = currentNode;
		child_walk.state = apply(actWALK, currentNode.state, mapa);
		child_walk.sequence.push_back(actWALK);
		if (isSolutionFoundLevel0(child_walk.state, final)) {
			currentNode = child_walk;
			solutionFound = true;
		} else if (explored.find(child_walk)==explored.end()){
			frontier.push_back(child_walk);
		}

		if (!solutionFound) {
			// Child Node with action ACT_RUN
			NodeLevel0 child_run = currentNode;
			child_run.state = apply(actRUN, currentNode.state, mapa);
			child_run.sequence.push_back(actRUN);
			if (isSolutionFoundLevel0(child_run.state, final)) {
				currentNode = child_run;
				solutionFound = true;
			} else if (explored.find(child_run)==explored.end()){
				frontier.push_back(child_run);
			}
		}


		if (!solutionFound) {
			// Child Node with action ACT_TURN_L
			NodeLevel0 child_turnL = currentNode;
			child_turnL.state = apply(actTURN_L, currentNode.state, mapa);
			child_turnL.sequence.push_back(actTURN_L);
			if (explored.find(child_turnL)==explored.end()){
				frontier.push_back(child_turnL);
			}
			// Child Node with action ACT_TURN_SR
			NodeLevel0 child_turnSR = currentNode;
			child_turnSR.state = apply(actTURN_SR, currentNode.state, mapa);
			child_turnSR.sequence.push_back(actTURN_SR);
			if (explored.find(child_turnSR)==explored.end()){
				frontier.push_back(child_turnSR);
			}
		}

		if (!solutionFound and !frontier.empty()) {
			currentNode = frontier.front();
			while(!frontier.empty() and explored.find(currentNode) != explored.end()) {
				frontier.pop_front();
				if (!frontier.empty()) {
					currentNode = frontier.front();
				}
			}
		}
	}
	if (solutionFound) {
		plan = currentNode.sequence;
		cout << "PLan found" <<endl;
		DrawPlan(currentNode.sequence); 
	}
	return plan;
}


StateLevel1 applyLevel1(const Action &action, const StateLevel1 &state, const vector<vector<unsigned char>> map) {
	StateLevel1 result = state;
	Ubication oneStepUbication, twoStepsUbication, colaboratorOneStep;
	switch (action)
	{
	case actWALK:
		oneStepUbication = nextPlace(state.player);
		if (isValidPlace(oneStepUbication, map) and !isSameUbication(oneStepUbication, result.colaborator)) {
			result.player = oneStepUbication;
		}

		switch (result.colaboratorLastOrder)
		{
		case act_CLB_TURN_SR:
			result.colaborator.compass = static_cast<Orientacion>((result.colaborator.compass+1)%8);
			break;
		case act_CLB_WALK:
			colaboratorOneStep = nextPlace(state.colaborator);
			if (isValidPlace(colaboratorOneStep, map) and !isSameUbication(colaboratorOneStep, result.player)) {
				result.colaborator = colaboratorOneStep;
			}
			break;
		
		default:
			break;
		}
		break;
	
	case actRUN:
		oneStepUbication = nextPlace(state.player);
		if (isValidPlace(oneStepUbication, map) and !isSameUbication(oneStepUbication, state.colaborator)) {
			twoStepsUbication = nextPlace(oneStepUbication);
			if (isValidPlace(twoStepsUbication, map) and !isSameUbication(twoStepsUbication, state.colaborator)) {
				result.player = twoStepsUbication;
			}
		}

		switch (result.colaboratorLastOrder)
		{
		case act_CLB_TURN_SR:
			result.colaborator.compass = static_cast<Orientacion>((result.colaborator.compass+1)%8);
			break;
		case act_CLB_WALK:
			colaboratorOneStep = nextPlace(state.colaborator);
			if (isValidPlace(colaboratorOneStep, map) and !isSameUbication(colaboratorOneStep, result.player)) {
				result.colaborator = colaboratorOneStep;
			}
			break;
		
		default:
			break;
		}

		break;
	case actTURN_SR:
		result.player.compass = static_cast<Orientacion>((result.player.compass+1)%8);
		switch (result.colaboratorLastOrder)
		{
		case act_CLB_TURN_SR:
			result.colaborator.compass = static_cast<Orientacion>((result.colaborator.compass+1)%8);
			break;
		case act_CLB_WALK:
			colaboratorOneStep = nextPlace(state.colaborator);
			if (isValidPlace(colaboratorOneStep, map) and !isSameUbication(colaboratorOneStep, result.player)) {
				result.colaborator = colaboratorOneStep;
			}
			break;
		
		default:
			break;
		}

		break;
	case actTURN_L:
		result.player.compass = static_cast<Orientacion>((result.player.compass+6)%8);
		
		switch (result.colaboratorLastOrder)
		{
		case act_CLB_TURN_SR:
			result.colaborator.compass = static_cast<Orientacion>((result.colaborator.compass+1)%8);
			break;
		case act_CLB_WALK:
			colaboratorOneStep = nextPlace(state.colaborator);
			if (isValidPlace(colaboratorOneStep, map) and !isSameUbication(colaboratorOneStep, result.player)) {
				result.colaborator = colaboratorOneStep;
			}
			break;
		
		default:
			break;
		}
		break;
	case act_CLB_TURN_SR:
		result.colaborator.compass = static_cast<Orientacion>((result.colaborator.compass+1)%8);
		result.colaboratorLastOrder = act_CLB_TURN_SR;
		break;
	case act_CLB_WALK:
		colaboratorOneStep = nextPlace(state.colaborator);
		if (isValidPlace(colaboratorOneStep, map) and !isSameUbication(colaboratorOneStep, result.player)) {
			result.colaborator = colaboratorOneStep;
			result.colaboratorLastOrder = act_CLB_WALK;
		}
		break;
	case act_CLB_STOP:
		result.colaboratorLastOrder = act_CLB_STOP;
	default:
		break;
	}
	if (isSameUbication(result.player, result.colaborator)) {
		result = state;
	}
	return result;
}

list<Action> WidthSearchLevel1(const StateLevel1 &start, const Ubication &final, const vector<vector<unsigned char>> &mapa) {
	NodeLevel1 currentNode;
	list<NodeLevel1> frontier;
	set<NodeLevel1> explored;
	list<Action> plan;
	currentNode.state = start;

	frontier.push_back(currentNode);
	bool solutionFound = (currentNode.state.colaborator.row == final.row and currentNode.state.colaborator.col == final.col);
	bool hadColaborator = colaboratorInVision(currentNode.state.player, currentNode.state.colaborator);

	while(!frontier.empty() and !solutionFound) {
		// Delete actual state from frontier and add state to explored
		frontier.pop_front();
		explored.insert(currentNode);

		// Child Node with action ACT_WALK
		NodeLevel1 child_walk = currentNode;

		hadColaborator = colaboratorInVision(child_walk.state.player, child_walk.state.colaborator);
		child_walk.state = applyLevel1(actWALK, currentNode.state, mapa);
		child_walk.sequence.push_back(actWALK);

		if (isSolutionFoundLevel1(child_walk.state, final)) {
			currentNode = child_walk;
			solutionFound = true;
		} else {
			// if (hadColaborator and !colaboratorInVision(child_walk.state.player, child_walk.state.colaborator)) {
			// 	child_walk = currentNode;
			// 	child_walk.state = applyLevel1(act_CLB_STOP, child_walk.state, mapa);
			// 	child_walk.state = applyLevel1(actWALK, currentNode.state, mapa);
			// 	child_walk.sequence.pop_back();
			// 	child_walk.sequence.push_back(act_CLB_STOP);
			// 	child_walk.sequence.push_back(actWALK);
			// }
			if (explored.find(child_walk)==explored.end()){
				frontier.push_back(child_walk);
			}
		}


		if (!solutionFound) {
			// Child Node with action ACT_RUN
			NodeLevel1 child_run = currentNode;
			hadColaborator = colaboratorInVision(child_run.state.player, child_run.state.colaborator);
			child_run.state = applyLevel1(actRUN, currentNode.state, mapa);
			child_run.sequence.push_back(actRUN);
			if (isSolutionFoundLevel1(child_run.state, final)) {
				currentNode = child_run;
				solutionFound = true;
			} else {
				// if (hadColaborator and !colaboratorInVision(child_run.state.player, child_run.state.colaborator)) {
				// 	child_run = currentNode;
				// 	child_run.state = applyLevel1(act_CLB_STOP, child_run.state, mapa);
				// 	child_run.state = applyLevel1(actRUN, currentNode.state, mapa);
				// 	child_run.sequence.pop_back();
				// 	child_run.sequence.push_back(act_CLB_STOP);
				// 	child_run.sequence.push_back(actRUN);
				// }
				if (explored.find(child_run)==explored.end()){
					frontier.push_back(child_run);
				}
			}
		}


		if (!solutionFound) {
			// Child Node with action ACT_TURN_L
			NodeLevel1 child_turnL = currentNode;
			hadColaborator = colaboratorInVision(child_turnL.state.player, child_turnL.state.colaborator);
			
			child_turnL.state = applyLevel1(actTURN_L, currentNode.state, mapa);
			child_turnL.sequence.push_back(actTURN_L);
			if (isSolutionFoundLevel1(child_turnL.state, final)) {
				currentNode = child_turnL;
				solutionFound = true;
			} else {
				// if (hadColaborator and !colaboratorInVision(child_turnL.state.player, child_turnL.state.colaborator)) {
				// 	child_turnL = currentNode;
				// 	child_turnL.state = applyLevel1(act_CLB_STOP, child_turnL.state, mapa);
				// 	child_turnL.state = applyLevel1(actTURN_L, currentNode.state, mapa);
				// 	child_turnL.sequence.pop_back();
				// 	child_turnL.sequence.push_back(act_CLB_STOP);
				// 	child_turnL.sequence.push_back(actTURN_L);
				// }
				if (explored.find(child_turnL)==explored.end()){
					frontier.push_back(child_turnL);
				}
			}
			// Child Node with action ACT_TURN_SR
			NodeLevel1 child_turnSR = currentNode;
			hadColaborator = colaboratorInVision(child_turnSR.state.player, child_turnSR.state.colaborator);
			child_turnSR.state = applyLevel1(actTURN_SR, currentNode.state, mapa);
			child_turnSR.sequence.push_back(actTURN_SR);
			if (isSolutionFoundLevel1(child_turnSR.state, final)) {
				currentNode = child_turnSR;
				solutionFound = true;
			}else {
				// if (hadColaborator and !colaboratorInVision(child_turnSR.state.player, child_turnSR.state.colaborator)) {
				// 	child_turnSR = currentNode;
				// 	child_turnSR.state = applyLevel1(act_CLB_STOP, child_turnSR.state, mapa);
				// 	child_turnSR.state = applyLevel1(actTURN_SR, currentNode.state, mapa);
				// 	child_turnSR.sequence.pop_back();
				// 	child_turnSR.sequence.push_back(act_CLB_STOP);
				// 	child_turnSR.sequence.push_back(actTURN_SR);
				// }
				if (explored.find(child_turnSR)==explored.end()){
					frontier.push_back(child_turnSR);
				}
			}
		}

		// Child Node with action ACT_CLB_WALK
		if (!solutionFound and colaboratorInVision(currentNode.state.player, currentNode.state.colaborator)){
			NodeLevel1 child_walk_clb = currentNode;
			child_walk_clb.state = applyLevel1(act_CLB_WALK, currentNode.state, mapa);
			child_walk_clb.sequence.push_back(act_CLB_WALK);
			if (isSolutionFoundLevel1(child_walk_clb.state, final)) {
				currentNode = child_walk_clb;
				solutionFound = true;
			} else if (explored.find(child_walk_clb)==explored.end()){
				frontier.push_back(child_walk_clb);
			}
		}

		if (!solutionFound and colaboratorInVision(currentNode.state.player, currentNode.state.colaborator)){
			// Child Node with action ACT_CLB_STOP
			NodeLevel1 child_walk_clb = currentNode;
			child_walk_clb.state = applyLevel1(act_CLB_STOP, currentNode.state, mapa);
			child_walk_clb.sequence.push_back(act_CLB_STOP);
			if (isSolutionFoundLevel1(child_walk_clb.state, final)) {
				currentNode = child_walk_clb;
				solutionFound = true;
			} else if (explored.find(child_walk_clb)==explored.end()){
				frontier.push_back(child_walk_clb);
			}
		}
		if (!solutionFound and colaboratorInVision(currentNode.state.player, currentNode.state.colaborator)){
			// Child Node with action ACT_CLB_TURNSR
			NodeLevel1 child_walk_clb_turn = currentNode;
			child_walk_clb_turn.state = applyLevel1(act_CLB_TURN_SR, currentNode.state, mapa);
			child_walk_clb_turn.sequence.push_back(act_CLB_TURN_SR);
			if (explored.find(child_walk_clb_turn)==explored.end()){
				frontier.push_back(child_walk_clb_turn);
			}
		}



		if (!solutionFound and !frontier.empty()) {
			currentNode = frontier.front();
			while(!frontier.empty() and explored.find(currentNode) != explored.end()) {
				frontier.pop_front();
				if (!frontier.empty()) {
					currentNode = frontier.front();
				}
			}
		}
	}
	if (solutionFound) {
		plan = currentNode.sequence;
		cout << "PLan found" <<endl;
		DrawPlan(currentNode.sequence); 
	}
	return plan;
}
void DrawTerrainSensor(const vector<unsigned char> terrain) {
	auto it = terrain.begin();
	while (it != terrain.end()) {
		cout << *it << " ";
		it++;
	}
	cout << " sensor\n";
}
// Este es el método principal que se piden en la practica.
// Tiene como entrada la información de los sensores y devuelve la acción a realizar.
// Para ver los distintos sensores mirar fichero "comportamiento.hpp"
Action ComportamientoJugador::think(Sensores sensores)
{
	Action accion = actIDLE;
	switch (sensores.nivel)
	{
	case 0:
		if (!hasPlan){
		// Invocar al método de búsqueda
			levelCurrentState.player.row = sensores.posF;
			levelCurrentState.player.col = sensores.posC;
			levelCurrentState.player.compass = sensores.sentido;
			levelCurrentState.colaborator.row = sensores.CLBposF;
			levelCurrentState.colaborator.col = sensores.CLBposC;
			levelCurrentState.colaborator.compass = sensores.CLBsentido;
			goal.row = sensores.destinoF;
			goal.col = sensores.destinoC;
			actionPlan = WidthSearchLevel0(levelCurrentState, goal, mapaResultado);
			VisualizePlan(levelCurrentState, actionPlan);
			hasPlan = true;
		}
		if (hasPlan and actionPlan.size()>0){
			accion = actionPlan.front();
			actionPlan.pop_front();
		}
		if (actionPlan.size()== 0){
			cout << "plan ended" << endl;
			hasPlan = false;
		}
			break;
	case 1:
		if (!hasPlan) {
			levelOneCurrentState.player.row = sensores.posF;
			levelOneCurrentState.player.col = sensores.posC;
			levelOneCurrentState.player.compass = sensores.sentido;
			levelOneCurrentState.colaborator.row = sensores.CLBposF;
			levelOneCurrentState.colaborator.col = sensores.CLBposC;
			levelOneCurrentState.colaborator.compass = sensores.CLBsentido;
			levelOneCurrentState.colaboratorLastOrder = act_CLB_STOP;
			goal.row = sensores.destinoF;
			goal.col = sensores.destinoC;
			actionPlan = WidthSearchLevel1(levelOneCurrentState, goal, mapaResultado);
			VisualizePlan(levelOneCurrentState, actionPlan);
			hasPlan = true;
			break;
		}
		if (hasPlan and actionPlan.size()>0){
			accion = actionPlan.front();
			actionPlan.pop_front();
		}
		if (actionPlan.size()== 0){
			hasPlan = false;
		}
		break;
	default:
		break;
	}
	return accion;
}


int ComportamientoJugador::interact(Action accion, int valor)
{
	return false;
}
