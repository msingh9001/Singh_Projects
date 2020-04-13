#!/bin/sh
# Name: Mandeep Singh
# Date: 01/09/20
# Title: Lab1 – Linux Familiarization
# Description: This program gives the area of a circle and rectangle

echo Executing $0
echo $(/bin/ls | wc -l) files
wc -l $(/bin/ls)
#Print various paths such as home, user, and current directories
echo "HOME="$HOME
echo "USER="$USER
echo "PATH="$PATH
echo "PWD="$PWD
echo "\$\$"=$$
user=`whoami`
numusers=`who | wc -l`
#Print current user logged in and the number of users logged on
echo "Hi $user! There are $numusers users logged on."
#If the current user is msingh9001 continue or print current user logged on
if [ $user = "msingh9001" ]
then
        echo "Now you can proceed!"
else
        echo "Check who logged in!"
        exit 1
fi

response="Yes"
while [ $response != "No" ]
#User gives inputs for height, width, and radius for calculations
do
        echo "Enter height of rectangle: "
        read height
        echo "Enter width of rectangle: "
        read width
        area=`expr $height \* $width`
        echo "The area of the rectangle is $area"
        echo "Enter the radius of the circle: "
        read radius
        #Use basic calculator in order for float calculation and print results
        circle_area=$(echo "3.14*$radius*$radius" | bc )
        echo "The are of the circle is $circle_area"
        echo "Would you like to repeat for another rectangle or square [Yes/No]?"
        read response
#If response yes, loop|If response no, exit
done
