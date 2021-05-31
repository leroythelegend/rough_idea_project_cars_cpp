#ifndef PCARS_GAME_STATE_FACTORY_H_
#define PCARS_GAME_STATE_FACTORY_H_

#include <memory>

#include "../inc/gamestate.h"
#include "../inc/process.h"
#include "../inc/consts.h"

namespace pcars { 

    class GameStateFactoryV1
    {
    public:
        
        using GameStatePtr = std::shared_ptr<GameState>;
        using ProcessPtr = std::shared_ptr<Process>;

        const GameStatePtr operator()(Game_State, const ProcessPtr &) const;
    };

    class GameStateFactoryV2
    {
    public:
        
        using GameStatePtr = std::shared_ptr<GameState>;
        using ProcessPtr = std::shared_ptr<Process>;

        const GameStatePtr operator()(Game_State, const ProcessPtr &) const;
    };

} // namespace

#endif