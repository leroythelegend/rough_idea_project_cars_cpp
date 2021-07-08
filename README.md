# Rough Idea Project Cars C++ Telemetry

## Contents

* [I just want telemetry](#P-JustTelemetry)


## <a name="P-JustTelemetry"></a>I just want telemetry

### Build and Install

- For linux or mac

```
# cd rough_idea_project_cars_cpp-master
# mkdir build; cd build
# cmake ..
# make
# sudo make install
```

- For Windows

This is what I did to build on windows (I'm no expert on windows)

- Installed free version of visual studio 
- Installed vscode
- Open the repo in vscode
- Installed the C++ intelliSense from microsoft
- Installed the CMake Tools plugin from microsoft
- VSCode had a pop-up to configure to use CMake, I clicked yes
- Then clicked the build button at the bottom of VSCode
- This then built the executables in ./build/Debug

### Run




## Description

Simple CPP Classes for capturing and processing Project Cars UDP packets with a working example capturing CSV files.


Also have done some classes in CSharp https://github.com/leroythelegend/rough_idea_project_cars_csharp and swift https://github.com/leroythelegend/rough_idea_project_cars_swift


## Contents

* [Building the repo](#P-Building) Mac Linux and Windows
* [CSV Files](#P-CSV) CSV Files
* [Tutorial](#P-Tutorial)

## <a name="P-Building"></a> Building

### Linux and MAC

```
# mkdir build; cd build
# cmake ..
# make
```

To run cd build

```
./mypcars [-v1|-v2]
```
or
```
./pcarscsv [-v1|-v2]
```

This will not do anything until you go out on the track and then each of the implemented telemetry attributes will be displayed one after the other (this is just an example and it will help to understand what each attribute does, I'm still in the process of updating the attributes)

### Windows

This is what I did to build on windows 

- Installed vscode
- Open the repo in vscode
- Installed the C++ intelliSense from microsoft
- Installed the CMake Tools plugin from microsoft
- VSCode had a pop-up to configure to use CMake, I clicked yes
- Then clicked the build button at the bottom of VSCode
- This then built the executables in ./build/Debug (If you changed from debug to release it will be in Release instead of Debug)
- I then copied the exe pcarscsv to a empty folder.
- Ran pcarscsv from the empty folder (NOTE the very first out lap is not captured, CSV files are created for each lap after the very first out lap).

 
## <a name="P-CSV"></a> CSV Files

To capture set of CSV files run the following after building the source.

NOTE the following is different on Windows see windows section above. Also you can copy pcarscsv to another directory and run from there if you want to save the CSV files in a more permanent dirctory.

```
cd build
./pcarscsv [-v1|-v2]
```

This will produce a set of CSV files for each lap in the current directory, note the very first out lap is NOT recorded.

I use plotjuggler-3 to view the CSV files (https://github.com/facontidavide/PlotJuggler).


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
