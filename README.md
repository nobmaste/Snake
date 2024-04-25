# Snake
4/25报错：<br>
Building project Snake (NUCLEO_L476RG, ARMC6)<br>
Scan: Snake<br>
Compile [  0.1%]: RTX_Config.c<br>
Compile [  0.2%]: cmsis_os1.c<br>
Compile [  0.3%]: irq_cm4f.S<br>
Compile [  0.4%]: rtx_delay.c<br>
Compile [  0.5%]: rtx_evr.c<br>
Compile [  0.6%]: rtx_evflags.c<br>
Compile [  0.7%]: rtx_lib.c<br>
Compile [  0.8%]: rtx_kernel.c<br>
Compile [  0.9%]: rtx_memory.c<br>
Compile [  1.0%]: Joystick.cpp<br>
[Error] Joystick.cpp@28,26: invalid digit 'f' in decimal constant<br>
[Error] Joystick.cpp@30,28: invalid digit 'f' in decimal constant<br>
[Error] Joystick.cpp@32,28: invalid digit 'f' in decimal constant<br>
[Error] Joystick.cpp@34,28: invalid digit 'f' in decimal constant<br>
[ERROR] ./lib/Joystick.cpp:28:26: error: invalid digit 'f' in decimal constant<br>
} else if (angle < 45f) {  // then keep going in 45 degree increments<br>
^<br>
./lib/Joystick.cpp:30:28: error: invalid digit 'f' in decimal constant<br>
}  else if (angle < 135f) {<br>
^<br>
./lib/Joystick.cpp:32:28: error: invalid digit 'f' in decimal constant<br>
}  else if (angle < 225f) {<br>
^<br>
./lib/Joystick.cpp:34:28: error: invalid digit 'f' in decimal constant<br>
}  else if (angle < 315f) {<br>
^<br>
4 errors generated.<br>