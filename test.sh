#! /bin/bash
clear

run () {
	echo "$*"
	if $*
		then echo 'success'
	else echo 'error'
	fi
}

run ./main <<EOF 
"Test string test"
EOF

# Figure out way of supplying commands to make 
# encryption example 
