#!/bin/bash
fromfile=$1
tofile=$2

if ! [ -f $fromfile ]
	then
		echo "File $fromfile does not exist. Abort."
		exit 1
	else
		if [ -f $tofile ]; then
				echo "File $tofile already exists. Overwrite? [Y/n]"
				echo -n " >"
				read yourcommand
				if [ "$yourcommand" != "Y" ]; then
					echo "Abort."
					exit 1
				fi
		fi
		# executed when tofile does not exist or you said 'yep, overwrite it.'
		cat "$fromfile" > "$tofile" 
fi

# known issues:
# handling of the permission denial, especially when reading from fromfile (L20).  
