# Rough Idea Project Cars C++ Telemetry

Uses the UDP output to write telemetry for either Project Cars version 1 or version 2 telemetry to a set CSV files for each lap.

The CSV files include telemerty for the tyres, suspension, raceline, force, engine, weather and inputs.

### Build and Install

- For linux or mac

```
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

Create a directory to store the csv files and run the pcarscsv exe, for example on linux or mac
```
# mkdir bathurst-p1
# cd bathurst-p1
# pcarscsv -v2
```
and for version 1 telemetry (default is version 2)
```
# pcarscsv -v1
```
I then use plotjuggler-3 to view the CSV files (https://github.com/facontidavide/PlotJuggler).

![Alt text](images/plotjuggler.jpg?raw=true "PlotJuggler-3")
