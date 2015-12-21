#!/bin/bash

if [ -e libft/.git ]; then
	echo "libft submodule already initialized"
else
	git submodule init && git submodule update
fi
