#!/bin/bash
if [ $# != 1 ]
then
	git add .
	echo "Error : Put a comment !"
	git commit -m "No message entered"
else
	git add .
	git commit -m "$1"
fi
git push