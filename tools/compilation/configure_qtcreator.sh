AVERSIVE_ROOT=.

QTCREATOR_FILES=$AVERSIVE_ROOT/aversive--.files
QTCREATOR_INCLUDES=$AVERSIVE_ROOT/aversive--.includes
QTCREATOR_CONFIG=$AVERSIVE_ROOT/aversive--.config

QTCREATOR_CREATOR=$AVERSIVE_ROOT/aversive--.creator

#Files
echo -n "" > $QTCREATOR_FILES

find $AVERSIVE_ROOT -name "*.hpp" >> $QTCREATOR_FILES
find $AVERSIVE_ROOT -name "*.cpp" >> $QTCREATOR_FILES

find $AVERSIVE_ROOT -name "Makefile" >> $QTCREATOR_FILES
find $AVERSIVE_ROOT -name "*.pro" | grep "generated" -v >> $QTCREATOR_FILES

find $AVERSIVE_ROOT -name "*.archi" >> $QTCREATOR_FILES

find $AVERSIVE_ROOT -name "*.dox" >> $QTCREATOR_FILES

find $AVERSIVE_ROOT -name "*.h" >> $QTCREATOR_FILES
find $AVERSIVE_ROOT -name "*.c" >> $QTCREATOR_FILES

find $AVERSIVE_ROOT -name "*.sh" >> $QTCREATOR_FILES

find $AVERSIVE_ROOT -name "*.y" >> $QTCREATOR_FILES
find $AVERSIVE_ROOT -name "*.l" >> $QTCREATOR_FILES

#Includes
echo -n "" > $QTCREATOR_INCLUDES

echo "include/common" >> $QTCREATOR_INCLUDES
echo "include/avr" >> $QTCREATOR_INCLUDES
echo "include/sasiae" >> $QTCREATOR_INCLUDES
echo "include/stm32" >> $QTCREATOR_INCLUDES

#Config
echo -n "" > $QTCREATOR_CONFIG

#Config
echo "[General]" > $QTCREATOR_CREATOR
