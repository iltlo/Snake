#!/bin/bash

echo -n "Your score history will be deleted, do you want to continue [Y/n]?  "
confirm="n"
read confirm
if [ "$confirm" == "Y" ]
then
    echo "         ===  LEADERBOARD  ===       " > ./log/leaderboard.txt
    echo " SCORE                           DATE" >> ./log/leaderboard.txt
    echo "Score history deleted."
else
    echo "Abort."
fi
