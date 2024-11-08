CFLAGS ?= -O2 -g

CFLAGS += -std=gnu99

CFLAGS += -Wall -Werror -Wformat-security -Wignored-qualifiers -Winit-self \
	-Wswitch-default -Wpointer-arith -Wtype-limits -Wempty-body \
	-Wstrict-prototypes -Wold-style-declaration -Wold-style-definition \
	-Wmissing-parameter-type -Wmissing-field-initializers -Wnested-externs \
	-Wstack-usage=4096 -Wmissing-prototypes -Wfloat-equal -Wabsolute-value 
	
CFLAGS += -fsanitize=undefined -fsanitize-undefined-trap-on-error

CC += -m32 -no-pie -fno-pie

LDLIBS = -lm

.PHONY: all clean

all: integral

clean:
	rm -f integral functions.o

integral: integral.c functions.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

functions.o: functions.asm
	nasm -f elf32 -o $@ $<

test:
	./integral -R 4:5:0.6:1.5:0.001:1.0
	./integral -R 4:6:0.5:1.5:0.001:1.0
	./integral -R 5:6:0.5:1.3:0.001:1.0
	./integral -I 4:1.0:5.0:0.001:12.0
	./integral -I 5:1.0:10.0:0.001:333.0
	./integral -I 6:1.0:5.0:0.001:6.7869
