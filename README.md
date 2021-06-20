# Rough Idea Project Cars C++

# Current poject

Currently in the process of producing csv files of each lap.

After building, run the following to get a basic unfinshed csv file: 
```
cd build
./pcarscsv -v2
```
Then I have been loading the csv files into plotJuggler-3.

## Description

Simpler CPP Classes for capturing and processing Project Cars UDP packets.

Example of all the format 1 and format 2 attributes can be seen in myprocess.cpp.

NOTE: I'm still updating the comments for the Packets.

Also have done some classes in CSharp https://github.com/leroythelegend/rough_idea_project_cars_csharp and swift https://github.com/leroythelegend/rough_idea_project_cars_swift


## Contents

* [Building the repo](#P-Building) Mac Linux and Windows
* [Tutorial](#P-Tutorial)

## <a name="P-Building"></a> Building

### MAC

Have not tried since changing to cmake

### Linux

```
# mkdir build; cd build
# cmake ..
# make
```

To run cd build

```
./mypcars [-v1|-v2]
```

This will not do anything until you go out on the track and then each of the implemented telemetry attributes will be displayed one after the other (this is just an example and it will help to understand what each attribute does, I'm still in the process of updating the attributes)

### Windows

No idea, use visual studio, I'll have  to get around to running this on windows I'm little worried about windows does not export symbols from a dll which would be problamatic I'm sure there must be a compiler flag that flips this behaviour and you can flip it back if need be. I have added some win socket code so I'm hoping if it compiles it will work. Never Tested on win :-(

## <a name="P-Tutorial"></a> Tutorial

The Classes are broken up into Process, Packet, Decode, Telemetry, GameState(Capture) and Transport (STILL WIP)

### Process

```
    class Process {
    public:

        using PacketPtr = std::shared_ptr<Packet>;

        /// \brief Process playing packets
        ///
        ///     Process packets when game is in state playing
        ///
        /// \param Packet
        /// \return void
        /// \throw nothing

        virtual void playing(PacketPtr &) = 0;

        /// \brief Process menu packets
        ///
        ///     Process menu when game is in state menu time ticking
        ///
        /// \param Packet
        /// \return void
        /// \throw nothing

        virtual void menu(PacketPtr &) = 0;
    };
```

The most important class is process, if you look at the ./bin/main.cpp you will see that telemetry v1 and v2 take a process e.g. MyProcessV1 and MyProcessV2. Take a look at the myprocess.cpp to see where I have been adding all the different telemetry outputs from pcars udp packets. This is still WIP but you can see that while in playing i.e. driving the playing method is printing to the console the implemented telemetry and in the menu it just prints the size of the packets captured when the game is in the menu time ticking state e.g. when in pits. 

So to roll your own derive your own class from process and pass it to telemetry depending on which version of pcars you are interested in capturing. 

Brief Summary while I try and finish this

myprocess.cpp shows how to use the attributes, playing is during the game and menu is when you go back to the pits the state of the game can be modified with the gamestate.cpp if required. i.e. more granulated state e.g. pit mode, race mode.
