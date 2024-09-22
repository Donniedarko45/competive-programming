#!/bin/bash

# Set up environment variables
export MY_CONFIG_VAR="value"

# Compile the file
g++ -std=c++17 my_file.cpp -o my_file

# Run the executable
./my_file