#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"

#include <list>


struct Ubication {
  int row;
  int col;
  Orientacion compass;

  bool operator==(const Ubication &ub) const {
    return (row == ub.row and col == ub.col and compass == ub.compass);
  }
};

struct StateLevel0 {
  Ubication player;
  Ubication colaborator;
  Action colaboratorLastOrder;

  bool operator==(const StateLevel0 &state) const {
    return player == state.player and
        colaborator.row == state.colaborator.row and
        colaborator.col == state.colaborator.col;
  }
};

struct NodeLevel0 {
  StateLevel0 state;
  list<Action> sequence;

  bool operator==(const NodeLevel0 &n) const {
    return (state == n.state);
  }

  bool operator<(const NodeLevel0 &n) const {
    if (state.player.row < n.state.player.row){
      return true;
    } else if(state.player.row == n.state.player.row and state.player.col < n.state.player.col){
      return true;
    } else if(state.player.row == n.state.player.row and state.player.col == n.state.player.col and state.player.compass < n.state.player.compass) {
      return true;
    }
    return false;
  }

};





class ComportamientoJugador : public Comportamiento {
  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size) {
      // Inicializar Variables de Estado
    }
    ComportamientoJugador(std::vector< std::vector< unsigned char> > mapaR) : Comportamiento(mapaR) {
      // Inicializar Variables de Estado
      hasPlan = false;
      goal.col = 0;
      goal.row = 0;
      goal.compass = norte;
    }
    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);
    void VisualizePlan(const StateLevel0 &st, const list<Action> &plan);

  private:
    // Declarar Variables de Estado
    list<Action> actionPlan;
    bool hasPlan;
    StateLevel0 levelCurrentState;
    Ubication goal;

};

#endif
