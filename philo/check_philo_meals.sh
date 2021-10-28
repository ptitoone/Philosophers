#!/bin/bash

read -p "philo count: " COUNT
read -p "time to die: " DIE
read -p "time to eat: " EAT
read -p "time to sleep: " SLEEP
read -p "meal count: " MEALS

NUMBER=1

./philo $COUNT $DIE $EAT $SLEEP $MEALS > log
	((COUNT++))
while [ $NUMBER -ne $COUNT ]
do
	echo ""
	echo "__ Philo number $NUMBER __"
	cat log | grep "$NUMBER is eating"
	echo -n "count:"
	cat log | grep "$NUMBER is eating" | wc -l
	((NUMBER++))
done
