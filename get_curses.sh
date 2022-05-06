#!/bin/bash

if [ ! -d ./ncurses ] || [ "`ls $./ncurses | wc -l`" -eq "0" ]   # directory exists or is empty
then
    git clone https://github.com/mirror/ncurses.git
    echo "Cloning finished."
fi

if [ ! -d ~/ncurses_files ] || [ "`ls $~/ncurses_files | wc -l`" -eq "0" ]
then 

    cd ./ncurses
    mkdir ~/ncurses_files
    ./configure --prefix ~/ncurses_files

    make -j                     # parallel processing
    make -j install
    echo "Ncurses succesfully set up."

fi
