SRC=$1
shift
DST=$1
shift

while [ $# -gt 0 ]
do
sed "s/$SRC/$DST/" $1 > $1.tmp
mv $1.tmp $1
shift
done
