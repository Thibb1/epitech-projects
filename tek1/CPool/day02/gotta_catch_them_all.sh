#!/bin/bash
DEFAULT="martin"

cut -d: -f5 | cut -d' ' -f2 | grep -c "^${1:-$DEFAULT}"