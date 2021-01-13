#!/usr/bin/env bash

rm -r /var/lib/apt/lists/* && apt update
apt-get update && apt-get install -y python3 python3-pip vim git && \
python3 -m pip install scons

ln -sfn /usr/bin/python3 /usr/bin/python

cd godot-cpp && scons -c && scons platform=linux generate_bindings=yes bits=64
