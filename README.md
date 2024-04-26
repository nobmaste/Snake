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

4/26报错:<br>
Joystick.h<br>
Unknown type name 'PinName' (fix available)clang(unknown_typename)[60, 14]
Unknown type name 'PinName' (fix available)clang(unknown_typename)[60, 30]
Unknown type name 'AnalogIn'clang(unknown_typename)[72, 5]
Unknown type name 'AnalogIn'clang(unknown_typename)[73, 5]<br>

snake.cpp<br>
Using declaration cannot refer to a template specializationclang(using_decl_template_id)[3, 12]
In template: no member named 'value' in 'std::__is_referenceable<int>'clang(no_member)[10, 20]
No matching function for call to 'make_pair'clang(ovl_no_viable_function_in_call)[10, 20]
No matching function for call to 'make_pair'clang(ovl_no_viable_function_in_call)[11, 20]
No matching function for call to 'make_pair'clang(ovl_no_viable_function_in_call)[12, 20]
In template: no type named 'type' in 'std::add_lvalue_reference<int>'clang(typename_nested_not_found)[28, 25]
Use of undeclared identifier 'isEaten'clang(undeclared_var_use)[56, 9]
'isEaten' is a private member of 'food'clang(access)[61, 12]
'isEaten' is a private member of 'food'clang(access)[65, 11]
Expected unqualified-idclang(expected_unqualified_id)[102, 1]<br>

snake.h<br>
In included file: no type named 'pointer' in 'std::allocator_traits<std::allocator<std::vector<int>>>'clang(typename_nested_not_found)[7, 10]
In template: no type named 'difference_type' in 'std::allocator_traits<std::allocator<std::vector<int>>>'clang(typename_nested_not_found)[24, 35]<br>

Joystick.cpp<br>
Unknown type name 'PinName'clang(unknown_typename)[5, 20]
Unknown type name 'PinName'clang(unknown_typename)[5, 36]
Unknown type name 'AnalogIn'clang(unknown_typename)[7, 16]
Unknown type name 'AnalogIn'clang(unknown_typename)[8, 17]
Out-of-line definition of 'get_direction' does not match any declaration in 'Joystick'clang(member_decl_does_not_match)[22, 21]
Out-of-line definition of 'get_mag' does not match any declaration in 'Joystick'clang(member_decl_does_not_match)[46, 17]
Out-of-line definition of 'get_angle' does not match any declaration in 'Joystick'clang(member_decl_does_not_match)[52, 17]
Out-of-line definition of 'get_coord' does not match any declaration in 'Joystick'clang(member_decl_does_not_match)[64, 20]
Out-of-line definition of 'get_mapped_coord' does not match any declaration in 'Joystick'clang(member_decl_does_not_match)[78, 20]
Out-of-line definition of 'get_polar' does not match any declaration in 'Joystick'clang(member_decl_does_not_match)[91, 17]<br>

main.cpp<br>
Too many errors emitted, stopping nowclang(fatal_too_many_errors)[1, 1]
Unknown type name 'PC_7'clang(unknown_typename)[36, 11]
Unknown type name 'PA_9'clang(unknown_typename)[36, 17]
Unknown type name 'PB_10'clang(unknown_typename)[36, 23]
Unknown type name 'PB_5'clang(unknown_typename)[36, 30]
Unknown type name 'PB_3'clang(unknown_typename)[36, 36]
Unknown type name 'PA_10'clang(unknown_typename)[36, 42]
Unknown type name 'Joystick'clang(unknown_typename)[37, 1]
Unknown type name 'PC_1'clang(unknown_typename)[37, 19]
Unknown type name 'PC_0'clang(unknown_typename)[37, 25]
Unknown type name 'DigitalIn'clang(unknown_typename)[38, 1]
Unknown type name 'BUTTON1'clang(unknown_typename)[38, 19]
Unknown type name 'snake'clang(unknown_typename)[39, 1]
Unknown type name 'food'clang(unknown_typename)[40, 1]
Use of undeclared identifier 'thread_sleep_for'clang(undeclared_var_use)[55, 5]
Use of undeclared identifier 'thread_sleep_for'clang(undeclared_var_use)[66, 9]
Use of undeclared identifier 'ThisThread'clang(undeclared_var_use)[98, 10]
No matching literal operator for call to 'operator""ms' with argument of type 'unsigned long long' or 'const char *', and no matching literal operator templateclang(ovl_no_viable_literal_operator)[98, 35]
Use of undeclared identifier 'ThisThread'clang(undeclared_var_use)[108, 9]
No matching literal operator for call to 'operator""ms' with argument of type 'unsigned long long' or 'const char *', and no matching literal operator templateclang(ovl_no_viable_literal_operator)[108, 34]<br>