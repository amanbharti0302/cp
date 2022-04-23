#!/bin/bash

if [[ "$1" == "" ]]
    then 
        echo "Please enter name of destination file"
else 
        echo "Copying template to $1"
        cd ..
        echo "Taking backup of $1 to commands/backup_$1"
        cp "$1" "commands/backup_$1"
        echo "Backup completed"
        rm $1
        cp "commands/template.cpp" "$1"
        ls -l *.cpp
        echo "new template created with file name $1"
fi