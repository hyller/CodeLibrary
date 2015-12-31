@echo off
echo ELF to BIN file generation ...

"C:\Program Files (x86)\Atollic\TrueSTUDIO for ARM Pro 5.1.1\ARMTools\bin\arm-atollic-eabi-objcopy.exe" -O binary .\Debug\STM3210E_EVAL.elf .\STM3210E_EVAL_SysTick.bin

echo ELF to BIN file generation completed.

pause