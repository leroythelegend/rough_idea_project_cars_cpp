#include "gamestate.h"

#include "packetgamestate.h"
#include "packettelemetrydata.h"
#include "packettelemetrydatav1.h"


using namespace std;

namespace pcars {

    void GameState::next(Capture &capture, const GameState::GameStatePtr &state)
    {
        capture.nextGameState(state);
    }

    GamePlayingStateV1::GamePlayingStateV1(const std::shared_ptr<Process> &process) 
        : process_{process} {}

    void GamePlayingStateV1::capture(Capture &capture, PacketPtr &data)
    {
        if (data->type() == "PacketTelemetryDataV1") {
            PacketTelemetryDataV1 * packet = dynamic_cast<PacketTelemetryDataV1 *>(data.get());
            if (packet->game_state() == static_cast<unsigned int>(Game_State::GAME_FRONT_END)) {
                next(capture, make_shared<GameFrontEndStateV1>(process_));
            }
            else if (packet->game_state() == static_cast<unsigned int>(Game_State::GAME_INGAME_INMENU_TIME_TICKING)) {
                next(capture, make_shared<GameMenuStateV1>(process_));
            }
        }

        if (process_.get()) {
            process_->playing(data);
        }
    }

    GamePlayingStateV2::GamePlayingStateV2(const std::shared_ptr<Process> &process) 
        : process_{process} {}

    void GamePlayingStateV2::capture(Capture &capture, PacketPtr &data)
    {
        if (data->type() == "PacketGameState") {
            PacketGameState * packet = dynamic_cast<PacketGameState *>(data.get());
            if (packet->game_state() == static_cast<unsigned int>(Game_State::GAME_FRONT_END)) {
                next(capture, make_shared<GameFrontEndStateV2>(process_));
            }
            else if (packet->game_state() == static_cast<unsigned int>(Game_State::GAME_INGAME_INMENU_TIME_TICKING)) {
                next(capture, make_shared<GameMenuStateV2>(process_));
            }
        }

        if (process_.get()) {
            process_->playing(data);
        }
    }


    GameFrontEndStateV1::GameFrontEndStateV1(const std::shared_ptr<Process> &process) 
        : process_{process} {}

    void GameFrontEndStateV1::capture(Capture &capture,PacketPtr &data)
    {
        if (data->type() == "PacketTelemetryDataV1") {
            PacketTelemetryDataV1 * packet = dynamic_cast<PacketTelemetryDataV1 *>(data.get());
            if (packet->game_state() == static_cast<unsigned int>(Game_State::GAME_INGAME_PLAYING)) {
                next(capture, make_shared<GamePlayingStateV1>(process_));
            }
            else if (packet->game_state() == static_cast<unsigned int>(Game_State::GAME_INGAME_INMENU_TIME_TICKING)) {
                next(capture, make_shared<GameMenuStateV1>(process_));
            }
        } 
    }


    GameFrontEndStateV2::GameFrontEndStateV2(const std::shared_ptr<Process> &process) 
        : process_{process} {}

    void GameFrontEndStateV2::capture(Capture &capture,PacketPtr &data)
    {
        if (data->type() == "PacketGameState") {
            PacketGameState * packet = dynamic_cast<PacketGameState *>(data.get());
            if (packet->game_state() == static_cast<unsigned int>(Game_State::GAME_INGAME_PLAYING)) {
                next(capture, make_shared<GamePlayingStateV2>(process_));
            }
            else if (packet->game_state() == static_cast<unsigned int>(Game_State::GAME_INGAME_INMENU_TIME_TICKING)) {
                next(capture, make_shared<GameMenuStateV2>(process_));
            }
        }
    }


    GameMenuStateV1::GameMenuStateV1(const std::shared_ptr<Process> &process) 
        : process_{process} {}

    void GameMenuStateV1::capture(Capture &capture, PacketPtr &data)
    {
        if (data->type() == "PacketTelemetryDataV1") {
            PacketTelemetryDataV1 * packet = dynamic_cast<PacketTelemetryDataV1 *>(data.get());
            if (packet->game_state() == static_cast<unsigned int>(Game_State::GAME_INGAME_PLAYING)) {
                next(capture, make_shared<GamePlayingStateV1>(process_));
            }
            else if (packet->game_state() == static_cast<unsigned int>(Game_State::GAME_FRONT_END)) {
                next(capture, make_shared<GameMenuStateV1>(process_));
            }
        }

        if (process_.get()) {
            process_->menu(data);
        }
    }


    GameMenuStateV2::GameMenuStateV2(const std::shared_ptr<Process> &process) 
        : process_{process} {}

    void GameMenuStateV2::capture(Capture &capture, PacketPtr &data)
    {
        if (data->type() == "PacketGameState") {
            PacketGameState * packet = dynamic_cast<PacketGameState *>(data.get());
            if (packet->game_state() == static_cast<unsigned int>(Game_State::GAME_INGAME_PLAYING)) {
                next(capture, make_shared<GamePlayingStateV2>(process_));
            }
            else if (packet->game_state() == static_cast<unsigned int>(Game_State::GAME_FRONT_END)) {
                next(capture, make_shared<GameMenuStateV2>(process_));
            }
        }

        if (process_.get()) {
            process_->menu(data);
        }
    }

} // namespace pcars