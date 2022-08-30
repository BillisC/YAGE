all: exec

TARGET := gameboyemu
CFLAGS := -Wall
OBJECTFILES := build/main.o build/cpu.o build/instructions_inlines.o build/instructions.o build/table.o build/memory.o build/cartridge.o 

# Checking
exec: linker
	@./${TARGET}

# Linking
linker: build debug ${OBJECTFILES}
	@echo "Linking objects.."
	@g++ -o ${TARGET} ${OBJECTFILES}

# Compiling
build/main.o: src/main.cpp
	@echo "Compiling main.."
	@g++ ${CFLAGS} -c $< -o $@

build/cpu.o: src/cpu.cpp
	@echo "Compiling cpu.."
	@g++ ${CFLAGS} -c $< -o $@

build/instructions.o: src/instructions.cpp
	@echo "Compiling instructions.."
	@g++ ${CFLAGS} -c $< -o $@

build/instructions_inlines.o: src/instructions_inlines.cpp 
	@echo "Compiling inlines.."
	@g++ ${CFLAGS} -c $< -o $@

build/memory.o: src/memory.cpp 
	@echo "Compiling memory.."
	@g++ ${CFLAGS} -c $< -o $@

build/table.o: src/table.cpp 
	@echo "Compiling table.."
	@g++ ${CFLAGS} -c $< -o $@

build/cartridge.o: src/cartridge.cpp
	@echo "Compiling cartridge.."
	@g++ ${CFLAGS} -c $< -o $@

# Folder generation
build:
	@mkdir $@

debug:
	@mkdir $@

# Cleaning
clean:
	@rm -rf build