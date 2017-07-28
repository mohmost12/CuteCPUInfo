# Cute CPUInfo

# Intro
Cute CPUInfo is an application that reads CPU Information from `/proc/cpuinfo` and  visualize it using modern GUI based on QT Quick Controls

# Technologies Used
C++11, QML, QT Creator, QT Quick, QT 5.9.1, Design Patterns, Regular Expressions, Git

# Requirements
- Linux OS
- QT 5.9.1
- GCC

# Build and run steps
```sh
$ ~/Qt/5.9.1/gcc_64/bin/qmake -o Makefile MMostafaCPUInfo.pro -spec linux-g++
$ make clean
$ make
$ ./MMostafaCPUInfo
```

# UI Usage Guide
There are three main sections in the UI
##### Header 
Has a top right button the display About application menu 
##### Swipeview
- supports swiping left or right to naviagete between pages each displaying info about a single CPU Core
- supports scrolling up and down to disply detailed info about a CPU core
##### Footer
Indiacates the currently shown CPU core info and total number of cores


# Software Design
The Software is implemented according to the QT Model-View Design pattern for supporting decoupling of CPUInfo data encapsulation (C++ Model) from the GUI controls that display the CPUInfo data (View)

The View is implemented in QML as `cpuInfoListView` located in `main.qml`
The C++ Model is implemented as a derived class from QObject: `CPUInfoElement`

`CPUInfoParser` is the main Class in the application which parses the `/proc/cpuinfo` data using regular expressions and store them in the C++ Model.
This class is implemented according to the Singlton Design patten for managing a single instance of the parser as well as a single instance of `CPUInfoList`.

`CPUInfoParser::getCPUInfo()` is static function that returns a `CPUInfoList` which encapsulate the C++ model, the model is passed as a context property in the `main()` function to expose the model to the QML view.
