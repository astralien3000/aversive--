#!/bin/bash

function explode
{
    old="$IFS"
    IFS="$1"
    tab=( $2 )
    IFS="$old"
    declare -p tab | sed -e 's/^declare -a [^=]*=//'
}

echo "-- Welcome to the creating .hpp file tool --"
echo
echo "First, what is your new hpp file's path, followed by [ENTER]:"
echo "(Example: base/pair.hpp)"
echo -n "> "
read relative_file_path

if [ -e "include/common/$relative_file_path" ]
then # That file already exists !
    echo "This file already exists."
    echo "You may have to execute \"make exporthpp\" to automatically make the missing .hpp files in the platform-dependent include directories."
    exit 0
fi

echo "Creating the new .hpp file in include/common/"

# Let's explode the given path to build the path without the file's name and get the file's file on its own
ret=`explode "/" $relative_file_path`
eval "declare -a tab=${ret}"
file_path="include/common"
file_name=""
length=${#tab[*]}

for (( i=0 ; i<length ; i++ )) ; do
    if [ $i -lt $((length-1)) ]
    then
	file_path="$file_path/${tab[$i]}"
    else
	file_name="${tab[$i]}"
    fi
done

# Let's build the shiny macro's name for endless include protection
define=`echo $file_name | tr '[:lower:].' '[:upper:]_'`

# Let's build the generic .hpp file in common dir
mkdir -p "$file_path"
touch "$file_path/$file_name"

echo "#ifndef $define" >> "$file_path/$file_name"
echo "#define $define" >> "$file_path/$file_name"

echo >> "$file_path/$file_name"
echo >> "$file_path/$file_name"
echo >> "$file_path/$file_name"

echo "#endif//$define" >> "$file_path/$file_name"

# And then, let's build the platform-specific .hpp files that include the generic one
while read dir
do
    if [ "$dir" != "common" ]
    then # We skip the common dir obviously
	echo "Creating the new .hpp file in include/$dir/"
	file_path2=`echo $file_path | sed "s/common/$dir/g"`
	define2=`echo ${dir}_$define | tr '[:lower:]' '[:upper:]'`

	mkdir -p "$file_path2"
	touch "$file_path2/$file_name"
	
	echo "#ifndef $define2" >> "$file_path2/$file_name"
	echo "#define $define2" >> "$file_path2/$file_name"

	echo >> "$file_path2/$file_name"

	echo -n "#include \"" >> "$file_path2/$file_name"
	for (( i=0 ; i<length ; i++ )) ; do
	    echo -n "../" >> "$file_path2/$file_name"
	done
	echo "common/$relative_file_path\"" >> "$file_path2/$file_name"

	echo >> "$file_path2/$file_name"
	echo >> "$file_path2/$file_name"
	echo >> "$file_path2/$file_name"

	echo "#endif//$define2" >> "$file_path2/$file_name"
    fi
done < <(ls -1 "include/")
