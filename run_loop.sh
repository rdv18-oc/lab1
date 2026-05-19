#!/bin/bash

echo "Starting text_processor loop for Kubernetes..."

while true; do
    rand_val=$((RANDOM % 1000 + 1))
    
    echo "Parsing test string number: $rand_val"
    
    echo "Simulated document text $rand_val for parsing." | /usr/bin/text_processor
    
    sleep $((RANDOM % 5 + 1))
done