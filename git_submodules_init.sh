#!/bin/bash
if [ "$(ls libft/)" ]; then
	echo "libft submodule already initialized"
else
	git submodule init && git submodule update
fi
