FILES=$(find $*)

for f in $FILES
do
    emacs $f --batch -e mark-whole-buffer -e untabify -e save-buffer
done
