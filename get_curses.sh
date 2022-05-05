#!/bin/bash

if [ ! -d ./ncurses ]
then
    git clone https://github.com/mirror/ncurses.git
    echo "Cloning finished."
fi

if [ ! -d ~/ncurses_files ]
then 

    cd ./ncurses
    mkdir ~/ncurses_files
    ./configure --prefix ~/ncurses_files

    make -j                     # parallel processing
    make -j install
    echo "Ncurses succesfully set up."

fi
