#############################################################################
# Makefile for building: libaversive_sasiae.a
# Generated by qmake (2.01a) (Qt 4.8.1) on: Tue Jul 1 09:33:55 2014
# Project:  project/sasiae.pro
# Template: lib
# Command: /usr/bin/qmake-qt4 -o Makefile project/sasiae.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_CORE_LIB
CFLAGS        = -m64 -pipe -O2 -fPIC -D_REENTRANT $(DEFINES)
CXXFLAGS      = -std=c++11 -O3 -fPIC -O2 -fPIC -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -Iproject -I/usr/include/qt4/QtCore -I/usr/include/qt4 -Iinclude/sasiae -I. -Iproject -I.
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = build/sasiae/

####### Files

SOURCES       = src/sasiae/device/stream/eeprom_stream.cpp \
		src/sasiae/system/scheduler.cpp \
		src/sasiae/aversive.cpp \
		src/sasiae/client_thread.cpp \
		src/common/device/stream/internal_buffered_stream.cpp \
		src/common/device/stream/binary_stream_read.cpp \
		src/common/device/stream/stream.cpp \
		src/common/device/stream/formatted_stream_read.cpp \
		src/common/device/stream/formatted_stream_write.cpp \
		src/common/device/stream/binary_stream_write.cpp \
		src/common/math/random.cpp \
		src/common/geometry/quadrilateral_collision.cpp \
		src/common/geometry/triangle_collision.cpp \
		src/common/geometry/circle_collision.cpp \
		src/common/geometry/point_collision.cpp \
		src/common/geometry/aabb_collision.cpp \
		src/common/geometry/segment_collision.cpp \
		src/common/filter/pid_filter.cpp \
		src/common/filter/quadramp_filter.cpp \
		src/common/filter/diff_filter.cpp 
OBJECTS       = build/sasiae/eeprom_stream.o \
		build/sasiae/scheduler.o \
		build/sasiae/aversive.o \
		build/sasiae/client_thread.o \
		build/sasiae/internal_buffered_stream.o \
		build/sasiae/binary_stream_read.o \
		build/sasiae/stream.o \
		build/sasiae/formatted_stream_read.o \
		build/sasiae/formatted_stream_write.o \
		build/sasiae/binary_stream_write.o \
		build/sasiae/random.o \
		build/sasiae/quadrilateral_collision.o \
		build/sasiae/triangle_collision.o \
		build/sasiae/circle_collision.o \
		build/sasiae/point_collision.o \
		build/sasiae/aabb_collision.o \
		build/sasiae/segment_collision.o \
		build/sasiae/pid_filter.o \
		build/sasiae/quadramp_filter.o \
		build/sasiae/diff_filter.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		project/project/generated/sasiae.files.pro \
		project/project/generated/common.files.pro \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/staticlib.prf \
		/usr/share/qt4/mkspecs/features/static.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		project/sasiae.pro
QMAKE_TARGET  = aversive_sasiae
DESTDIR       = build/
TARGET        = libaversive_sasiae.a

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile build/$(TARGET) 

staticlib: build/$(TARGET)

build/$(TARGET):  $(OBJECTS) $(OBJCOMP) 
	@$(CHK_DIR_EXISTS) build/ || $(MKDIR) build/ 
	-$(DEL_FILE) $(TARGET)
	$(AR) $(TARGET) $(OBJECTS)
	-$(DEL_FILE) build/$(TARGET)
	-$(MOVE) $(TARGET) build/


Makefile: project/sasiae.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		project/generated/sasiae.files.pro \
		project/generated/common.files.pro \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/staticlib.prf \
		/usr/share/qt4/mkspecs/features/static.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf
	$(QMAKE) -o Makefile project/sasiae.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
project/generated/sasiae.files.pro:
project/generated/common.files.pro:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/staticlib.prf:
/usr/share/qt4/mkspecs/features/static.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
qmake:  FORCE
	@$(QMAKE) -o Makefile project/sasiae.pro

dist: 
	@$(CHK_DIR_EXISTS) build/sasiae/aversive_sasiae1.0.0 || $(MKDIR) build/sasiae/aversive_sasiae1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) build/sasiae/aversive_sasiae1.0.0/ && $(COPY_FILE) --parents include/sasiae/device/output.hpp include/sasiae/device/input.hpp include/sasiae/device/stream/formatted_stream.hpp include/sasiae/device/stream/random_access_stream.hpp include/sasiae/device/stream/fpga_uart_stream.hpp include/sasiae/device/stream/buffered_stream.hpp include/sasiae/device/stream/buffered_uart_stream.hpp include/sasiae/device/stream/internal_buffered_stream.hpp include/sasiae/device/stream/eeprom_stream.hpp include/sasiae/device/stream/stream.hpp include/sasiae/device/stream/uart_stream.hpp include/sasiae/device/stream/binary_stream.hpp include/sasiae/device/controller/robot_controller.hpp include/sasiae/device/controller/motor_controller.hpp include/sasiae/device/device.hpp include/sasiae/device/servomotor/fpga_servomotor.hpp include/sasiae/device/servomotor/servomotor_pin.hpp include/sasiae/device/servomotor/servomotor.hpp include/sasiae/device/eirbot2014/odometer.hpp include/sasiae/device/eirbot2014/motor.hpp include/sasiae/device/eirbot2014/position_manager.hpp include/sasiae/device/eirbot2014/encoder.hpp include/sasiae/device/eirbot2014/gp2.hpp include/sasiae/device/eirbot2014/rds.hpp include/sasiae/device/eirbot2014/ax12.hpp include/sasiae/device/output_device.hpp include/sasiae/device/motor/motor.hpp include/sasiae/device/motor/fpga_motor.hpp include/sasiae/device/io_device.hpp include/sasiae/device/encoder/encoder.hpp include/sasiae/device/encoder/fpga_encoder.hpp include/sasiae/device/input_device.hpp include/sasiae/device/other/fpga_timer.hpp include/sasiae/device/other/pin.hpp include/sasiae/system/scheduler.hpp include/sasiae/system/task.hpp include/sasiae/math/sqrt.hpp include/sasiae/math/matrix.hpp include/sasiae/math/safe_integer.hpp include/sasiae/math/random.hpp include/sasiae/math/vect.hpp include/sasiae/math/fixed_point.hpp include/sasiae/math/saturate.hpp include/sasiae/math/extract.hpp include/sasiae/math/trigo.hpp include/sasiae/container/queue.hpp include/sasiae/container/buffer.hpp include/sasiae/container/list.hpp include/sasiae/container/stack.hpp include/sasiae/container/heap.hpp include/sasiae/client_thread.hpp include/sasiae/aversive.hpp include/sasiae/base/function.hpp include/sasiae/base/alloc.hpp include/sasiae/base/integer.hpp include/sasiae/base/pair.hpp include/sasiae/base/array.hpp include/sasiae/base/singleton.hpp include/sasiae/geometry/point.hpp include/sasiae/geometry/collision.hpp include/sasiae/geometry/shape.hpp include/sasiae/geometry/aabb.hpp include/sasiae/geometry/segment.hpp include/sasiae/geometry/circle.hpp include/sasiae/geometry/world.hpp include/sasiae/geometry/triangle.hpp include/sasiae/geometry/quadrilateral.hpp include/sasiae/filter/feedback_loop_filter.hpp include/sasiae/filter/kalman_filter.hpp include/sasiae/filter/quadramp_filter.hpp include/sasiae/filter/composed_filter.hpp include/sasiae/filter/filter.hpp include/sasiae/filter/diff_filter.hpp include/sasiae/filter/pid_filter.hpp include/common/device/output.hpp include/common/device/input.hpp include/common/device/stream/formatted_stream.hpp include/common/device/stream/random_access_stream.hpp include/common/device/stream/fpga_uart_stream.hpp include/common/device/stream/buffered_stream.hpp include/common/device/stream/buffered_uart_stream.hpp include/common/device/stream/internal_buffered_stream.hpp include/common/device/stream/eeprom_stream.hpp include/common/device/stream/stream.hpp include/common/device/stream/uart_stream.hpp include/common/device/stream/binary_stream.hpp include/common/device/controller/robot_controller.hpp include/common/device/controller/motor_controller.hpp include/common/device/device.hpp include/common/device/servomotor/fpga_servomotor.hpp include/common/device/servomotor/servomotor_pin.hpp include/common/device/servomotor/servomotor.hpp include/common/device/eirbot2014/odometer.hpp include/common/device/eirbot2014/motor.hpp include/common/device/eirbot2014/position_manager.hpp include/common/device/eirbot2014/encoder.hpp include/common/device/eirbot2014/gp2.hpp include/common/device/eirbot2014/rds.hpp include/common/device/eirbot2014/ax12.hpp include/common/device/motor/motor.hpp include/common/device/motor/fpga_motor.hpp include/common/device/encoder/encoder.hpp include/common/device/encoder/fpga_encoder.hpp include/common/device/other/fpga_timer.hpp include/common/device/other/pin.hpp include/common/system/scheduler.hpp include/common/system/task.hpp include/common/math/sqrt.hpp include/common/math/matrix.hpp include/common/math/safe_integer.hpp include/common/math/random.hpp include/common/math/vect.hpp include/common/math/fixed_point.hpp include/common/math/saturate.hpp include/common/math/extract.hpp include/common/math/trigo.hpp include/common/container/queue.hpp include/common/container/buffer.hpp include/common/container/list.hpp include/common/container/stack.hpp include/common/container/heap.hpp include/common/aversive.hpp include/common/base/function.hpp include/common/base/alloc.hpp include/common/base/integer.hpp include/common/base/pair.hpp include/common/base/array.hpp include/common/base/singleton.hpp include/common/geometry/point.hpp include/common/geometry/collision.hpp include/common/geometry/shape.hpp include/common/geometry/aabb.hpp include/common/geometry/segment.hpp include/common/geometry/circle.hpp include/common/geometry/world.hpp include/common/geometry/triangle.hpp include/common/geometry/quadrilateral.hpp include/common/filter/feedback_loop_filter.hpp include/common/filter/kalman_filter.hpp include/common/filter/quadramp_filter.hpp include/common/filter/composed_filter.hpp include/common/filter/filter.hpp include/common/filter/diff_filter.hpp include/common/filter/pid_filter.hpp build/sasiae/aversive_sasiae1.0.0/ && $(COPY_FILE) --parents src/sasiae/device/stream/eeprom_stream.cpp src/sasiae/system/scheduler.cpp src/sasiae/aversive.cpp src/sasiae/client_thread.cpp src/common/device/stream/internal_buffered_stream.cpp src/common/device/stream/binary_stream_read.cpp src/common/device/stream/stream.cpp src/common/device/stream/formatted_stream_read.cpp src/common/device/stream/formatted_stream_write.cpp src/common/device/stream/binary_stream_write.cpp src/common/math/random.cpp src/common/geometry/quadrilateral_collision.cpp src/common/geometry/triangle_collision.cpp src/common/geometry/circle_collision.cpp src/common/geometry/point_collision.cpp src/common/geometry/aabb_collision.cpp src/common/geometry/segment_collision.cpp src/common/filter/pid_filter.cpp src/common/filter/quadramp_filter.cpp src/common/filter/diff_filter.cpp build/sasiae/aversive_sasiae1.0.0/ && (cd `dirname build/sasiae/aversive_sasiae1.0.0` && $(TAR) aversive_sasiae1.0.0.tar aversive_sasiae1.0.0 && $(COMPRESS) aversive_sasiae1.0.0.tar) && $(MOVE) `dirname build/sasiae/aversive_sasiae1.0.0`/aversive_sasiae1.0.0.tar.gz . && $(DEL_FILE) -r build/sasiae/aversive_sasiae1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

/usr/bin/moc-qt4:
	(cd $(QTDIR)/src/tools/moc && $(MAKE))

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all:
compiler_moc_header_clean:
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_clean: 

####### Compile

build/sasiae/eeprom_stream.o: src/sasiae/device/stream/eeprom_stream.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/sasiae/eeprom_stream.o src/sasiae/device/stream/eeprom_stream.cpp

build/sasiae/scheduler.o: src/sasiae/system/scheduler.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/sasiae/scheduler.o src/sasiae/system/scheduler.cpp

build/sasiae/aversive.o: src/sasiae/aversive.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/sasiae/aversive.o src/sasiae/aversive.cpp

build/sasiae/client_thread.o: src/sasiae/client_thread.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/sasiae/client_thread.o src/sasiae/client_thread.cpp

build/sasiae/internal_buffered_stream.o: src/common/device/stream/internal_buffered_stream.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/sasiae/internal_buffered_stream.o src/common/device/stream/internal_buffered_stream.cpp

build/sasiae/binary_stream_read.o: src/common/device/stream/binary_stream_read.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/sasiae/binary_stream_read.o src/common/device/stream/binary_stream_read.cpp

build/sasiae/stream.o: src/common/device/stream/stream.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/sasiae/stream.o src/common/device/stream/stream.cpp

build/sasiae/formatted_stream_read.o: src/common/device/stream/formatted_stream_read.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/sasiae/formatted_stream_read.o src/common/device/stream/formatted_stream_read.cpp

build/sasiae/formatted_stream_write.o: src/common/device/stream/formatted_stream_write.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/sasiae/formatted_stream_write.o src/common/device/stream/formatted_stream_write.cpp

build/sasiae/binary_stream_write.o: src/common/device/stream/binary_stream_write.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/sasiae/binary_stream_write.o src/common/device/stream/binary_stream_write.cpp

build/sasiae/random.o: src/common/math/random.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/sasiae/random.o src/common/math/random.cpp

build/sasiae/quadrilateral_collision.o: src/common/geometry/quadrilateral_collision.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/sasiae/quadrilateral_collision.o src/common/geometry/quadrilateral_collision.cpp

build/sasiae/triangle_collision.o: src/common/geometry/triangle_collision.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/sasiae/triangle_collision.o src/common/geometry/triangle_collision.cpp

build/sasiae/circle_collision.o: src/common/geometry/circle_collision.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/sasiae/circle_collision.o src/common/geometry/circle_collision.cpp

build/sasiae/point_collision.o: src/common/geometry/point_collision.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/sasiae/point_collision.o src/common/geometry/point_collision.cpp

build/sasiae/aabb_collision.o: src/common/geometry/aabb_collision.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/sasiae/aabb_collision.o src/common/geometry/aabb_collision.cpp

build/sasiae/segment_collision.o: src/common/geometry/segment_collision.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/sasiae/segment_collision.o src/common/geometry/segment_collision.cpp

build/sasiae/pid_filter.o: src/common/filter/pid_filter.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/sasiae/pid_filter.o src/common/filter/pid_filter.cpp

build/sasiae/quadramp_filter.o: src/common/filter/quadramp_filter.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/sasiae/quadramp_filter.o src/common/filter/quadramp_filter.cpp

build/sasiae/diff_filter.o: src/common/filter/diff_filter.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/sasiae/diff_filter.o src/common/filter/diff_filter.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

