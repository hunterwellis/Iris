# Iris -- Minimal Smart Home

This repo contains the [software](#software) and [hardware instructions](#hardware) necessary to set up my custom, minimal home automation system, Iris.

> Iris is an [anadrome](https://en.wikipedia.org/wiki/Anadrome) of another popular personal assistant.

## Quick start
[requirements](#requirements)


Build the project using CMake.
```
git clone https://github.com/hunterwellis/iris.git
cd iris
mkdir build && cd build
cmake ..
make
./iris  # run the software
```


## Software

The software is written in a combination of C++ and Python.

**GUI.** The user interface was built using the Qt framework, written in C++.
> Add Qt widgets via the ```main_window``` files

**Natural Language Processing.** The Iris system uses a wake word to begin every interaction, this word is "iris" by default. 

After Iris is _activated_ natural language inputs are tokenized and predicted commands are exectued. 
> Commands can be added and modified in the ```commands.hpp``` and ```commands.json``` files  
> (Note: The model will need to be retrained using the ```train.py``` script for edited commands to take effect)

**Home Automation Interface.** I set up a basic interface to interact with and control 


## Hardware

Much of the hardware inspiration came from [this repo](https://github.com/olm3ca/mirror).

In my implementation of Iris, I used a Raspberry Pi and a Lululemon Mirror. These Lululemon mirrors are no longer manufactured and require a subsciption fee to use, so they have become quite cheap online. In order to setup the hardware I had to install a custom display driver board and make other minor hardware modifications which I will document in the following section.

### Hardware Instuctions
_TODO:_  still need to put a detailed instruction guide here

## Requirements
- CMake
- Qt 6
