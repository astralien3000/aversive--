HEADERS +=  include/avr/device/output.hpp include/avr/device/input.hpp include/avr/device/stream/formatted_stream.hpp include/avr/device/stream/random_access_stream.hpp include/avr/device/stream/fpga_uart_stream.hpp include/avr/device/stream/buffered_stream.hpp include/avr/device/stream/buffered_uart_stream.hpp include/avr/device/stream/internal_buffered_stream.hpp include/avr/device/stream/eeprom_stream.hpp include/avr/device/stream/stream.hpp include/avr/device/stream/uart_stream.hpp include/avr/device/stream/binary_stream.hpp include/avr/device/controller/robot_controller.hpp include/avr/device/controller/motor_controller.hpp include/avr/device/device.hpp include/avr/device/servomotor/fpga_servomotor.hpp include/avr/device/servomotor/servomotor_pin.hpp include/avr/device/servomotor/servomotor.hpp include/avr/device/eirbot2014/odometer.hpp include/avr/device/eirbot2014/motor.hpp include/avr/device/eirbot2014/position_manager.hpp include/avr/device/eirbot2014/encoder.hpp include/avr/device/eirbot2014/gp2.hpp include/avr/device/eirbot2014/rds.hpp include/avr/device/eirbot2014/ax12.hpp include/avr/device/output_device.hpp include/avr/device/motor/motor.hpp include/avr/device/motor/fpga_motor.hpp include/avr/device/io_device.hpp include/avr/device/encoder/encoder.hpp include/avr/device/encoder/fpga_encoder.hpp include/avr/device/input_device.hpp include/avr/device/other/fpga_timer.hpp include/avr/device/other/pin.hpp include/avr/system/scheduler.hpp include/avr/system/task.hpp include/avr/math/sqrt.hpp include/avr/math/matrix.hpp include/avr/math/safe_integer.hpp include/avr/math/random.hpp include/avr/math/vect.hpp include/avr/math/fixed_point.hpp include/avr/math/saturate.hpp include/avr/math/extract.hpp include/avr/math/trigo.hpp include/avr/container/queue.hpp include/avr/container/buffer.hpp include/avr/container/list.hpp include/avr/container/stack.hpp include/avr/container/heap.hpp include/avr/aversive.hpp include/avr/base/function.hpp include/avr/base/alloc.hpp include/avr/base/integer.hpp include/avr/base/pair.hpp include/avr/base/array.hpp include/avr/base/singleton.hpp include/avr/geometry/point.hpp include/avr/geometry/collision.hpp include/avr/geometry/shape.hpp include/avr/geometry/aabb.hpp include/avr/geometry/segment.hpp include/avr/geometry/circle.hpp include/avr/geometry/world.hpp include/avr/geometry/triangle.hpp include/avr/geometry/quadrilateral.hpp include/avr/filter/feedback_loop_filter.hpp include/avr/filter/kalman_filter.hpp include/avr/filter/quadramp_filter.hpp include/avr/filter/composed_filter.hpp include/avr/filter/filter.hpp include/avr/filter/diff_filter.hpp include/avr/filter/pid_filter.hpp include/avr/hardware/interrupts.hpp include/avr/hardware/adc.hpp include/avr/hardware/architecture.hpp include/avr/hardware/eeprom.hpp include/avr/hardware/uart.hpp include/avr/hardware/xmem.hpp include/avr/hardware/config.hpp include/avr/hardware/timer.hpp include/avr/hardware/part/atmega32.hpp include/avr/hardware/part/atmega2560.hpp include/avr/hardware/part/atmega128.hpp include/avr/hardware/register.hpp include/avr/hardware/hardware_event.hpp include/avr/hardware/pinmap.hpp
SOURCES +=  src/avr/system/scheduler.cpp src/avr/aversive.cpp src/avr/hardware/interrupts.cpp src/avr/hardware/timer.cpp src/avr/hardware/uart.cpp
