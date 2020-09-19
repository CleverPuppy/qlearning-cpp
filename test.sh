#! /bin/sh

set -x
LOGFILE=./logs/loss.txt
EXEC=./build/qlearning
mkdir -p ./logs/
$EXEC > ${LOGFILE}
python3 draw_loss.py $LOGFILE