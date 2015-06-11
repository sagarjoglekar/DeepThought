ARTIFACT_NAME    := cloud-infrastructure-shell
ARTIFACT_VERSION := 1.0.0

PWD := $(shell pwd)

SRC_SHELL_DIR := $(PWD)/src
SRC_IMPL_DIR  := $(PWD)/src/impl
INC_DIR       := $(PWD)/include
TST_DIR       := $(PWD)/test
TARGET_DIR    := $(PWD)/build

SOURCES  := $(SRC_SHELL_DIR)/interview.cpp $(SRC_IMPL_DIR)/hosttypeimpl.cpp \
            $(SRC_IMPL_DIR)/grouptypeimpl.cpp $(SRC_IMPL_DIR)/hostimpl.cpp \
            $(SRC_IMPL_DIR)/groupimpl.c

OBJS     := $(TARGET_DIR)/interview.o $(TARGET_DIR)/hosttypeimpl.o \
            $(TARGET_DIR)/grouptypeimpl.o $(TARGET_DIR)/hostimpl.o \
            $(TARGET_DIR)/groupimpl.o

INCLUDES := -I$(INC_DIR)

CXXFLAGS := -D_REENTRANT -fPIC -DPIC -Wall -pedantic -std=c++11 $(INCLUDES) $(CXXFLAGS)

ifeq ($(shell uname -s),Darwin)
    CXXFLAGS   := -D_DARWIN -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -stdlib=libc++ $(CXXFLAGS)
	LDLIBS     := -lc++ $(COMMON_LIBS)
else
	LDLIBS     := -lrt -lstdc++ $(COMMON_LIBS)
endif

PREFIX = /usr/local

ifeq ($(DEBUG),1)
	CXXFLAGS := -g -O0 -D_DEBUG $(CXXFLAGS)
	LDFLAGS  := -g $(LDFLAGS)
else
	CXXFLAGS := -O2 $(CXXFLAGS)
endif

TARGET  := $(ARTIFACT_NAME)-$(ARTIFACT_VERSION)

all: clean $(TARGET_DIR) $(TARGET)

$(TARGET_DIR):
	@echo --- Creating $@ ---
	@mkdir $@

$(TARGET): $(OBJS)
	@echo --- Linking $@ ---
	@g++ $< $(LDFLAGS) $(LOADLIBES) $(LDLIBS) -o $@

$(TARGET_DIR)/interview.o: $(SRC_SHELL_DIR)/interview.cpp
	@echo --- Compiling $< ---
	@g++ $(CXXFLAGS) -Wno-unused -c $< -o $@

$(TARGET_DIR)/hosttypeimpl.o: $(SRC_IMPL_DIR)/hosttypeimpl.cpp
	@echo --- Compiling $< ---
	@g++ $(CXXFLAGS) -Wno-unused -c $< -o $@

$(TARGET_DIR)/grouptypeimpl.o: $(SRC_IMPL_DIR)/grouptypeimpl.cpp
	@echo --- Compiling $< ---
	@g++ $(CXXFLAGS) -Wno-unused -c $< -o $@

$(TARGET_DIR)/hostimpl.o: $(SRC_IMPL_DIR)/hostimpl.cpp
	@echo --- Compiling $< ---
	@g++ $(CXXFLAGS) -Wno-unused -c $< -o $@

$(TARGET_DIR)/groupimpl.o: $(SRC_IMPL_DIR)/groupimpl.cpp
	@echo --- Compiling $< ---
	@g++ $(CXXFLAGS) -Wno-unused -c $< -o $@

clean:
	@echo --- Cleaning everything ---
	@rm -rf $(TARGET)
	@rm -rf $(TARGET_DIR)

install:
	install -d $(DESTDIR)$(PREFIX)/bin
	install -m 0755 $(TARGET) $(DESTDIR)$(PREFIX)/bin

uninstall:
	rm -rf $(DESTDIR)$(PREFIX)/bin/$(TARGET)
