# Rough Idea Project Cars C++

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

Prerequiste you MUST have installed xcode and xcode command line tools, google this and follow the instructions from the Apple website.

* Open a Terminal
* Change Directory (CD) to your new local repo "src" directory (dir).

```
USER# cd /Users/You/rough_idea_project_cars_cpp/src
```

* Set up obj and lib dirs, this only needs to be done once.

```
USER# make install
```

* Make library

```
USER# make 
```

* To make and run the sample executable CD to the bin dir.

```
USER# cd ../bin
```

* Make exe

```
USER# make 
```

* Set up the DYLD_LIBRARY_PATH

```
USER# export DYLD_LIBRARY_PATH=/Users/You/rough_idea_project_cars_cpp/lib
```

* Depending on what Project Cars Format you are using (This can be found in the System settings I think)
* Format 1
```
USER# ./pcars -v1
```
* Format 2
```
USER# ./pcars -v2
```

This will not do anything until you go out on the track and then each of the implemented telemetry attributes will be displayed one after the other (this is just an example and it will help to understand what each attribute does, I'm still in the process of updating the attributes)

### Linux

Prerequiste you MUST have installed g++, use apt-get or yum.

* Open a Terminal
* Change Directory (CD) to your new local repo "src" directory (dir).

```
USER# cd /Home/You/rough_idea_project_cars_cpp/src
```

* Set up obj and lib dirs, this only needs to be done once.

```
USER# make install
```

* Make library

```
USER# make 
```

* To make and run the sample executable CD to the bin dir.

```
USER# cd ../bin
```

* Make exe

```
USER# make 
```

* Set up the LD_LIBRARY_PATH

```
USER# export LD_LIBRARY_PATH=/Users/You/rough_idea_project_cars_cpp/lib
```

* Depending on what Project Cars Format you are using (This can be found in the System settings I think)

* Format 1
```
USER# ./pcars -v1
```
* Format 2
```
USER# ./pcars -v2
```

This will not do anything until you go out on the track and then each of the implemented telemetry attributes will be displayed one after the other (this is just an example and it will help to understand what each attribute does, I'm still in the process of updating the attributes)

### Windows

No idea, use visual studio, I'll have to get around to running this on windows I'm little worried about windows does not export symbols from a dll which would be problamatic I'm sure there must be a compiler flag that flips this behaviour and you can flip it back if need be. I have added some win socket code so I'm hoping if it compiles it will work. Never Tested on win :-(

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
