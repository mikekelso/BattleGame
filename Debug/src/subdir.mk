################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BattleGameDriver.cpp \
../src/EnemyType.cpp \
../src/HeroType.cpp 

CPP_DEPS += \
./src/BattleGameDriver.d \
./src/EnemyType.d \
./src/HeroType.d 

OBJS += \
./src/BattleGameDriver.o \
./src/EnemyType.o \
./src/HeroType.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/BattleGameDriver.d ./src/BattleGameDriver.o ./src/EnemyType.d ./src/EnemyType.o ./src/HeroType.d ./src/HeroType.o

.PHONY: clean-src

