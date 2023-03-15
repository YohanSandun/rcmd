ifeq ($(OS),Windows_NT)
	RM := rmdir /Q /S
	OUT := bin/rcmd.exe
	CP := copy /Y
	MKTEST := if not exist
	MKDIR := mkdir
else
	RM := rm -f
	OUT := bin/rcmd
	CP := cp
	MKTEST := 
	MKDIR := mkdir -p
endif

all: dirs main.o Command.o
	g++ -o $(OUT) obj/main.o obj/Command.o -s -static
	$(CP) "commands.txt" "bin/commands.txt"

dirs:
	$(MKTEST) obj $(MKDIR) obj
	$(MKTEST) bin $(MKDIR) bin

main.o: main.cpp
	g++ -Wall -fexceptions -O2 -Iinclude -c main.cpp -o obj/main.o

Command.o: src/Command.cpp
	g++ -Wall -fexceptions -O2 -Iinclude -c src/Command.cpp -o obj/Command.o

clean:
	$(RM) obj bin