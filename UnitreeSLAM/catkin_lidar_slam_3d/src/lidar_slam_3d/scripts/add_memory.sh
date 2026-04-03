#!/bin/bash

sudo dd if=/dev/zero of=/swapfile bs=64M count=256 status=progress

sudo chmod 600 /swapfile

sudo mkswap /swapfile

sudo swapon /swapfile

free -h

