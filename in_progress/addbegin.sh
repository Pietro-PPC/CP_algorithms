TEMP_FILE="t.cpp"

if [ $# -ne 1 ] ; then
	echo -e "Usage: ./add_begin.sh <begin_name>"
	exit 1
fi

BEGIN=$1

for f in $(ls *.cpp) ; do
	if [ $f != $TEMP_FILE ] ; then
		echo "mv $f $1$f"
		mv $f $1$f
	fi
done

