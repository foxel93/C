#!/bin/sh

ifconfig | grep "ether " | tr -d "\t" | sed "s/^......//" | tr -d " "
