#ifndef PCARS_CAPTURE_STATE_H_
#define PCARS_CAPTURE_STATE_H_

#include <memory>
#include <vector>

#include "../inc/capture.h"
#include "../inc/process.h"
#include "../inc/packet.h"

namespace pcars { 

    ///
    /// Abstract GameState
    ///

    class GameState
    {
    public:

        using Ptr = std::shared_ptr<GameState>;

        virtual ~GameState() noexcept = default;

		/// Capture packets
		/// \param Capture
		/// \param Packet::Ptr 
        virtual void capture(Capture &, Packet::Ptr &) = 0;

		/// Next state
		/// \param Capture
		/// \param GameState next game state 
        void next(Capture &, const GameState::Ptr &);
    };

    ///
    /// Game playing state for format 1
    ///

    class GamePlayingStateV1 : public GameState
    {
    public:
        /// Constructor
        /// \param process
        GamePlayingStateV1(const Process::Ptr &);
        virtual ~GamePlayingStateV1() noexcept = default;

		/// Capture packets
		/// \param Capture
		/// \param Packet::Ptr 
        void capture(Capture &, Packet::Ptr &) override;

    private:

        Process::Ptr process_;

        GamePlayingStateV1(const GamePlayingStateV1 &) = delete;
        const GamePlayingStateV1 &operator =(const GamePlayingStateV1 &) = delete;
    };


    ///
    /// Game playing state format 2
    ///

    class GamePlayingStateV2 : public GameState
    {
    public:
        /// Constructor
        /// \param process
        GamePlayingStateV2(const Process::Ptr &);
        virtual ~GamePlayingStateV2() noexcept = default;

		/// Capture packets
		/// \param Capture
		/// \param Packet::Ptr 
        void capture(Capture &, Packet::Ptr &) override;

    private:

        Process::Ptr process_;

        GamePlayingStateV2(const GamePlayingStateV2 &) = delete;
        const GamePlayingStateV2 &operator =(const GamePlayingStateV2 &) = delete;
    };

    /// 
    /// Game Front End State format 1
    ///

    class GameFrontEndStateV1 : public GameState
    {
    public:
        /// Constructor
        /// \param process
        GameFrontEndStateV1(const Process::Ptr &);
        virtual ~GameFrontEndStateV1() noexcept = default;

		/// Capture packets
		/// \param Capture
		/// \param Packet::Ptr 
        void capture(Capture &, Packet::Ptr &) override;

    private:

        Process::Ptr process_;

        GameFrontEndStateV1(const GameFrontEndStateV1 &) = delete;
        const GameFrontEndStateV1 &operator =(const GameFrontEndStateV1 &) = delete;     
    };


    ///
    /// Game Front End State format 2
    ///

    class GameFrontEndStateV2 : public GameState
    {
    public:

        /// Constructor
        /// \param process
        GameFrontEndStateV2(const Process::Ptr &);
        virtual ~GameFrontEndStateV2() noexcept = default;

		/// Capture packets
		/// \param Capture
		/// \param Packet::Ptr 
        void capture(Capture &, Packet::Ptr &) override;

    private:

        Process::Ptr process_;

        GameFrontEndStateV2(const GameFrontEndStateV2 &) = delete;
        const GameFrontEndStateV2 &operator =(const GameFrontEndStateV2 &) = delete;    
    };

    ///
    /// Game Menu State Format 1
    ///

    class GameMenuStateV1 : public GameState
    {
    public:
        /// Constructor
        /// \param process
        GameMenuStateV1(const Process::Ptr &);
        virtual ~GameMenuStateV1() noexcept = default;

		/// Capture packets
		/// \param Capture
		/// \param Packet::Ptr 
        void capture(Capture &, Packet::Ptr &) override;

    private:
        Process::Ptr process_;

        GameMenuStateV1(const GameMenuStateV1 &) = delete;
        const GameMenuStateV1 &operator =(const GameMenuStateV1 &) = delete;   
    };

    ///
    /// Game Menu State Format 2
    ///

    class GameMenuStateV2 : public GameState
    {
    public:
        /// Constructor
        /// \param process
        GameMenuStateV2(const Process::Ptr &);
        virtual ~GameMenuStateV2() noexcept = default;

		/// Capture packets
		/// \param Capture
		/// \param Packet::Ptr 
        void capture(Capture &, Packet::Ptr &) override;

    private:
        Process::Ptr process_;

        GameMenuStateV2(const GameMenuStateV2 &) = delete;
        const GameMenuStateV2 &operator =(const GameMenuStateV2 &) = delete;   
    };

} // namespace

#endif