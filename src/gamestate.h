#ifndef PCARS_CAPTURE_STATE_H_
#define PCARS_CAPTURE_STATE_H_

#include <memory>
#include <vector>

#include "capture.h"
#include "process.h"
#include "packet.h"

namespace pcars { 

    /// \class GameState
    /// \breif Abstract GameState
    ///
    ///     Current GameSates

    class GameState
    {
    public:

        using PacketPtr = std::shared_ptr<Packet>;
        using GameStatePtr = std::shared_ptr<GameState>;

        /// Destructor
        virtual ~GameState() {}

		/// \brief capture packets
		///
		///
		/// \param Capture this
		/// \param PacketPtr 
		/// \return void
		/// \throw nothing

        virtual void capture(Capture &, PacketPtr &) = 0;

		/// \brief capture packets
		///
		///
		/// \param Capture this
		/// \param GameState next game state 
		/// \return void
		/// \throw nothing

        void next(Capture &, const GameStatePtr &);
    };

    /// \class GamePlayingStateV1
    /// \brief Game playing state for format 1

    class GamePlayingStateV1 : public GameState
    {
    public:

        using ProcessPtr = std::shared_ptr<Process>;

        /// Constructor
        ///
        /// \param process

        GamePlayingStateV1(const ProcessPtr &);
        
        /// Destructor
        virtual ~GamePlayingStateV1() {}

		/// \brief capture packets
		///
		///
		/// \param Capture this
		/// \param PacketPtr 
		/// \return void
		/// \throw nothing

        void capture(Capture &, PacketPtr &) override;

    private:

        ProcessPtr process_; 
    };


    /// \class GamePlayingStateV2
    /// \brief Game playing state format 2

    class GamePlayingStateV2 : public GameState
    {
    public:

        using ProcessPtr = std::shared_ptr<Process>;

        /// Constructor
        ///
        /// \param process

        GamePlayingStateV2(const ProcessPtr &);
        
        /// Destructor
        virtual ~GamePlayingStateV2() {}

		/// \brief capture packets
		///
		///
		/// \param Capture this
		/// \param PacketPtr 
		/// \return void
		/// \throw nothing

        void capture(Capture &, PacketPtr &) override;

    private:

        ProcessPtr process_; 
    };

    /// \class GameFrontEndStateV1
    /// \brief Game Front End State format 1

    class GameFrontEndStateV1 : public GameState
    {
    public:

        using ProcessPtr = std::shared_ptr<Process>;

        /// Constructor
        ///
        /// \param process
        
        GameFrontEndStateV1(const ProcessPtr &);
        /// Destructor
        virtual ~GameFrontEndStateV1() {}

		/// \brief capture packets
		///
		///
		/// \param Capture this
		/// \param PacketPtr 
		/// \return void
		/// \throw nothing

        void capture(Capture &, PacketPtr &) override;

    private:

        ProcessPtr process_;
    };


    /// \class GameFrontEndStateV2
    /// \brief Game Front End State format 2

    class GameFrontEndStateV2 : public GameState
    {
    public:

        using ProcessPtr = std::shared_ptr<Process>;

        /// Constructor
        ///
        /// \param process
        
        GameFrontEndStateV2(const ProcessPtr &);
        /// Destructor
        virtual ~GameFrontEndStateV2() {}

		/// \brief capture packets
		///
		///
		/// \param Capture this
		/// \param PacketPtr 
		/// \return void
		/// \throw nothing

        void capture(Capture &, PacketPtr &) override;

    private:

        ProcessPtr process_;
    };

    /// \class GameMenuStateV1
    /// \brief Game Menu State Format 1
    
    class GameMenuStateV1 : public GameState
    {
    public:

        using ProcessPtr = std::shared_ptr<Process>;

        /// Constructor
        ///
        /// \param process

        GameMenuStateV1(const ProcessPtr &);
        /// Destructor
        virtual ~GameMenuStateV1() {}

		/// \brief capture packets
		///
		///
		/// \param Capture this
		/// \param PacketPtr 
		/// \return void
		/// \throw nothing

        void capture(Capture &, PacketPtr &) override;

    private:
        ProcessPtr process_;
    };

    /// \class GameMenuStateV2
    /// \brief Game Menu State Format 2
    
    class GameMenuStateV2 : public GameState
    {
    public:

        using ProcessPtr = std::shared_ptr<Process>;

        /// Constructor
        ///
        /// \param process

        GameMenuStateV2(const ProcessPtr &);
        /// Destructor
        virtual ~GameMenuStateV2() {}

		/// \brief capture packets
		///
		///
		/// \param Capture this
		/// \param PacketPtr 
		/// \return void
		/// \throw nothing

        void capture(Capture &, PacketPtr &) override;

    private:
        ProcessPtr process_;
    };

} // namespace

#endif