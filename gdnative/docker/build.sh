#!/usr/bin/env bash

apt-get update && apt-get install -y build-essential scons pkg-config libx11-dev libxcursor-dev libxinerama-dev \
    libgl1-mesa-dev libglu-dev libasound2-dev libpulse-dev libfreetype6-dev libssl-dev libudev-dev \
    libxi-dev libxrandr-dev yasm cmake libc6-dev-i386 gcc-multilib g++-multilib

# cd /var/app/godot-cpp && scons platform=<your platform> generate_bindings=yes

mkdir -p /var/app/cmake-build-debug
mkdir -p /var/app/cmake-build-release

# cd /var/app && cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_FLAGS="-fPIC" -DCMAKE_CXX_FLAGS="-fPIC" -G "CodeBlocks - Unix Makefiles" .
cd /var/app && cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_FLAGS="-fPIC" -DCMAKE_CXX_FLAGS="-fPIC" -G "CodeBlocks - Unix Makefiles" .
cd /var/app && cmake --build /var/app --target EOMLib --
