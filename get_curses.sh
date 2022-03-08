#!/bin/bash

if [ ! -d ./ncurses ]
then
    git clone https://github.com/mirror/ncurses.git
    echo "clone finished."
fi

if [ ! -d ~/ncurses_files ]
then 

    cd ./ncurses
    mkdir ~/ncurses_files
    ./configure --prefix ~/ncurses_files

    make -j                     # parallel processing
    make -j install
    echo "make install finished."

fi

echo "ncurses succesfully set up."