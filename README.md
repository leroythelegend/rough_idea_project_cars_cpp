# Rough Idea Project Cars C++

## Description

Simpler CPP Classes for capturing and processing Project Cars UDP packets.

NOTE: I'm still updating the comments for the Packets.

Also have done some classes in CSharp https://github.com/leroythelegend/rough_idea_project_cars_csharp

## Contents

* [Building the repo](#P-Building MaC Linux and Windows)
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

myprocess.cpp shows how to use the attributes, playing is during the game and menu is when you go back to the pits the state of the game can be modified with the capturestate.cpp if required. i.e. more granulated state e.g. pit mode, race mode.

Tutorial is Still WIP

Sorry I'll have to finish this later
