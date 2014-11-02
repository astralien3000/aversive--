#!/bin/bash

echo "-- Welcome to the exporting .hpp file tool --"

common_path="include/common"

# Listting the platform-specific directories
impl=""
while read dir
do
    if [ $dir != "common" ]
    then
	impl="$impl $dir"
    fi
done < <(ls -1 "include/")
impl=( $impl )
length=${#impl[*]}

function exhpp
{
    # $1: current dir path
    # $2: depth, to know how many ../ we have to add in the new .hpp files we create
    while read file
    do
	if [ -d "$common_path/$1$file" ]
	then # It's a directory
	    # Let's make the dir in the platform-specific just to be sure it exists
	    for (( i=0 ; i<length ; i++ )) ; do
		mkdir -p "include/${impl[$i]}/$1$file"
	    done
	    # And then, let's do a recursive call
	    exhpp "$1$file/" $(($2+1))
	else # It's a file, let's see if it is there in the platform-specific directories too
	    for (( i=0 ; i<length ; i++ )) ; do
		file_path="include/${impl[$i]}/$1$file"
		
		if [ ! -e "$file_path" ]
		then # It isn't there so we need to create the .hpp file there
		    echo "Creating missing $file_path"
		    define=`echo ${impl[$i]}_$file | tr '[:lower:].' '[:upper:]_'`
		    
		    touch "$file_path"
		    echo "#ifndef $define" >> "$file_path"
		    echo "#define $define" >> "$file_path"
		    
		    echo >> "$file_path"
		    
		    echo -n "#include \"" >> "$file_path"
		    for (( j=0 ; j<$2 ; j++ )) ; do
			echo -n "../" >> "$file_path"
		    done
		    echo "common/$1$file\"" >> "$file_path"
		    
		    echo >> "$file_path"
		    echo >> "$file_path"
		    echo >> "$file_path"
		    
		    echo "#endif//$define" >> "$file_path"
		fi
	    done
	fi
    done < <(ls -1 "$common_path/$1")
}

exhpp "" 1
