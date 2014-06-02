if [ $# -lt 1 ]
then
echo "Usage : license_header.sh LICENSE_HEADER [FILE(S) ...]"
fi

HEADER=$1
shift

while [ $# -gt 0 ]
do

cat $HEADER > $1.tmp
cat $1 >> $1.tmp

mv $1.tmp $1

shift
done
