#include "../inc/gamestate.h"

#include "../inc/gamestatefactory.h"

#include "../inc/packetgamestate.h"
#include "../inc/packettelemetrydata.h"
#include "../inc/packettelemetrydatav1.h"

#include <iostream>

using namespace std;

namespace pcars {

    void GameState::next(Capture &capture, const GameState::Ptr &state)
    {
        capture.nextGameState(state);
    }

    GamePlayingStateV1::GamePlayingStateV1(const std::shared_ptr<Process> &process) 
        : process_{process} {}

    void GamePlayingStateV1::capture(Capture &capture, Packet::Ptr &data)
    {
        if (data->type() == PACKETTYPE::PACKETTELEMETRYDATAV1) {
            PacketTelemetryDataV1 * packet = dynamic_cast<PacketTelemetryDataV1 *>(data.get());
            if (packet->game_state() != static_cast<unsigned int>(Game_State::GAME_INGAME_PLAYING)) {
                GameState::Ptr state = GameStateFactoryV1()( static_cast<Game_State>(packet->game_state()), process_);
                if (state) {
                    next(capture, state);
                }
            }
            else {
                if (process_.get()) {
                    process_->playing(data);
                }
            }
        }
        else if (process_.get()) {
            process_->playing(data);
        }
        // else do nothing
    }

    GamePlayingStateV2::GamePlayingStateV2(const std::shared_ptr<Process> &process) 
        : process_{process} {}

    void GamePlayingStateV2::capture(Capture &capture, Packet::Ptr &data)
    {
        if (data->type() == PACKETTYPE::PACKETGAMESTATE) {
            PacketGameState * packet = dynamic_cast<PacketGameState *>(data.get());
            if (packet->game_state() != static_cast<unsigned int>(Game_State::GAME_INGAME_PLAYING)) {
                GameState::Ptr state = GameStateFactoryV2()( static_cast<Game_State>(packet->game_state()), process_);
                if (state) {
                    next(capture, state);
                }
            }
            else {
                if (process_.get()) {
                    process_->playing(data);
                }
            }
        }
        else if (process_.get()) {
            process_->playing(data);
        }
        // else do nothing
    }


    GameFrontEndStateV1::GameFrontEndStateV1(const std::shared_ptr<Process> &process) 
        : process_{process} {}

    void GameFrontEndStateV1::capture(Capture &capture,Packet::Ptr &data)
    {
        if (data->type() == PACKETTYPE::PACKETTELEMETRYDATAV1) {
            PacketTelemetryDataV1 * packet = dynamic_cast<PacketTelemetryDataV1 *>(data.get());
            if (packet->game_state() != static_cast<unsigned int>(Game_State::GAME_FRONT_END)) {
                GameState::Ptr state = GameStateFactoryV1()( static_cast<Game_State>(packet->game_state()), process_);
                if (state) {
                    next(capture, state);
                }
            }
        }
    }


    GameFrontEndStateV2::GameFrontEndStateV2(const std::shared_ptr<Process> &process) 
        : process_{process} {}

    void GameFrontEndStateV2::capture(Capture &capture,Packet::Ptr &data)
    {
        if (data->type() == PACKETTYPE::PACKETGAMESTATE) {
            PacketGameState * packet = dynamic_cast<PacketGameState *>(data.get());
            if (packet->game_state() != static_cast<unsigned int>(Game_State::GAME_FRONT_END)) {
                GameState::Ptr state = GameStateFactoryV2()( static_cast<Game_State>(packet->game_state()), process_);
                if (state) {
                    next(capture, state);
                }
            }
            else
            {
                process_->reset(data);
            }
        }
    }


    GameMenuStateV1::GameMenuStateV1(const std::shared_ptr<Process> &process) 
        : process_{process} {}

    void GameMenuStateV1::capture(Capture &capture, Packet::Ptr &data)
    {
        if (data->type() == PACKETTYPE::PACKETTELEMETRYDATAV1) {
            PacketTelemetryDataV1 * packet = dynamic_cast<PacketTelemetryDataV1 *>(data.get());
            if (packet->game_state() != static_cast<unsigned int>(Game_State::GAME_INGAME_INMENU_TIME_TICKING)) {
                GameState::Ptr state = GameStateFactoryV1()( static_cast<Game_State>(packet->game_state()), process_);
                if (state) {
                    next(capture, state);
                }
            }
            else {
                if (process_.get()) {
                    process_->menu(data);
                }
            }
        }
        else if (process_.get()) {
            process_->menu(data);
        }
        // else do nothing
    }


    GameMenuStateV2::GameMenuStateV2(const std::shared_ptr<Process> &process) 
        : process_{process} {}

    void GameMenuStateV2::capture(Capture &capture, Packet::Ptr &data)
    {
        if (data->type() == PACKETTYPE::PACKETGAMESTATE) {
            PacketGameState * packet = dynamic_cast<PacketGameState *>(data.get());
            if (packet->game_state() != static_cast<unsigned int>(Game_State::GAME_INGAME_INMENU_TIME_TICKING)) {
                GameState::Ptr state = GameStateFactoryV2()( static_cast<Game_State>(packet->game_state()), process_);
                if (state) {
                    next(capture, state);
                }
            }
            else {
                if (process_.get()) {
                    process_->menu(data);
                }
            }
        }
        else if (process_.get()) {
            process_->menu(data);
        }
        // else do nothing
    }

} // namespace pcars