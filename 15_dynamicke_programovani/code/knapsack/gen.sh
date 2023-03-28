#!/bin/bash

generate() {
  MAX_WEIGHT=$1
  MAX_COST=$2

  ITEMS=$3

  for ((i = 0; i < $ITEMS; i++)); do
    if ((i % 100 == 0)); then
      echo "R $i"
    fi

    WEIGHT=$(($RANDOM % MAX_WEIGHT))
    COST=$(($RANDOM % MAX_COST))

    echo $WEIGHT $COST >>in.txt
  done
}

echo $1 >> in.txt
echo $3 >> in.txt

generate $@