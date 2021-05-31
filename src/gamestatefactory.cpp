#include "../inc/gamestatefactory.h"
#include "../inc/exception.h"

using namespace std;

namespace pcars {

    const GameStateFactoryV1::GameStatePtr GameStateFactoryV1::operator()(Game_State state, const ProcessPtr & process) const
    {
        switch (state) {
            case Game_State::GAME_FRONT_END :
                return make_shared<GameFrontEndStateV1>(process);
            case Game_State::GAME_INGAME_PLAYING :
                return make_shared<GamePlayingStateV1>(process);
            case Game_State::GAME_INGAME_INMENU_TIME_TICKING :
                return make_shared<GameMenuStateV1>(process);
            case Game_State::GAME_EXITED :
            case Game_State::GAME_FRONT_END_REPLAY :
            case Game_State::GAME_INGAME_PAUSED :
            case Game_State::GAME_INGAME_REPLAY :
            case Game_State::GAME_INGAME_RESTARTING :
            case Game_State::GAME_MAX :
            default :
                return nullptr; 
        }
    }

    const GameStateFactoryV2::GameStatePtr GameStateFactoryV2::operator()(Game_State state, const ProcessPtr & process) const
    {
        switch (state) {
            case Game_State::GAME_FRONT_END :
                return make_shared<GameFrontEndStateV2>(process);
            case Game_State::GAME_INGAME_PLAYING :
                return make_shared<GamePlayingStateV2>(process);
            case Game_State::GAME_INGAME_INMENU_TIME_TICKING :
                return make_shared<GameMenuStateV2>(process);
            case Game_State::GAME_EXITED :
            case Game_State::GAME_FRONT_END_REPLAY :
            case Game_State::GAME_INGAME_PAUSED :
            case Game_State::GAME_INGAME_REPLAY :
            case Game_State::GAME_INGAME_RESTARTING :
            case Game_State::GAME_MAX :
            default :
                return nullptr; 
        }
    }

}