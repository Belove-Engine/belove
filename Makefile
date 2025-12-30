#---------------------------------------------------------------------------------
# Clear implicit rules
#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------
ifeq ($(strip $(DEVKITPPC)),)
$(error "Please set DEVKITPPC in your environment. export DEVKITPPC=<path to>devkitPPC")
endif

include $(DEVKITPPC)/wii_rules

#---------------------------------------------------------------------------------
# Project settings
#---------------------------------------------------------------------------------
TARGET      := $(notdir $(CURDIR))
LIBTARGET   := libBeloveEngine.a
BUILD       := build
SOURCES     := source
DATA        := data
INCLUDES    := include

#---------------------------------------------------------------------------------
# Excluded directories
#---------------------------------------------------------------------------------
EXCLUDE_PATHS := /platforms/raylib /platforms/framebuffer /platforms/sdl

#---------------------------------------------------------------------------------
# Compilation flags
#---------------------------------------------------------------------------------
CFLAGS   := -g -O2 -Wall $(MACHDEP) $(INCLUDE) -DPLAT_WII
CXXFLAGS := $(CFLAGS)

#---------------------------------------------------------------------------------
# Libraries (used only by consumers of the lib)
#---------------------------------------------------------------------------------
LIBS := -lgrrlib -lpngu `$(PREFIX)pkg-config freetype2 libpng libjpeg --libs` \
        -lfat -lwiiuse -lbte -lm -lasnd -lmad -logc

LIBDIRS := $(CURDIR)/$(GRRLIB) $(PORTLIBS)

#---------------------------------------------------------------------------------
# Build setup
#---------------------------------------------------------------------------------
ifneq ($(BUILD),$(notdir $(CURDIR)))

export OUTPUT := $(CURDIR)/$(LIBTARGET)

#---------------------------------------------------------------------------------
# Recursive source & include discovery (with exclusions)
#---------------------------------------------------------------------------------
export ALL_SOURCES := $(shell find $(SOURCES) -type d \
	\( -path '*/platforms/raylib*' -o -path '*/platforms/framebuffer*' -o -path '*/platforms/sdl*' \) \
	-prune -o -type d -print 2>/dev/null)

export ALL_INCLUDES := $(shell find $(INCLUDES) -type d \
	\( -path '*/platforms/raylib*' -o -path '*/platforms/framebuffer*' -o -path '*/platforms/sdl*' \) \
	-prune -o -type d -print 2>/dev/null)

export VPATH := $(foreach dir,$(ALL_SOURCES),$(CURDIR)/$(dir)) \
                $(foreach dir,$(DATA),$(CURDIR)/$(dir))

export DEPSDIR := $(CURDIR)/$(BUILD)

#---------------------------------------------------------------------------------
# Source files
#---------------------------------------------------------------------------------
CFILES   := $(foreach dir,$(ALL_SOURCES),$(notdir $(wildcard $(dir)/*.c)))
CPPFILES := $(foreach dir,$(ALL_SOURCES),$(notdir $(wildcard $(dir)/*.cpp)))
sFILES   := $(foreach dir,$(ALL_SOURCES),$(notdir $(wildcard $(dir)/*.s)))
SFILES   := $(foreach dir,$(ALL_SOURCES),$(notdir $(wildcard $(dir)/*.S)))
BINFILES := $(foreach dir,$(DATA),$(notdir $(wildcard $(dir)/*.*)))

export OFILES_BIN := $(addsuffix .o,$(BINFILES))
export OFILES_SRC := $(CPPFILES:.cpp=.o) $(CFILES:.c=.o) \
                     $(sFILES:.s=.o) $(SFILES:.S=.o)
export OFILES := $(OFILES_BIN) $(OFILES_SRC)

export HFILES := $(addsuffix .h,$(subst .,_,$(BINFILES)))

#---------------------------------------------------------------------------------
# Include paths
#---------------------------------------------------------------------------------
export INCLUDE := $(foreach dir,$(ALL_INCLUDES),-iquote $(CURDIR)/$(dir)) \
                  $(foreach dir,$(LIBDIRS),-I$(dir)/include) \
                  -I$(CURDIR)/$(BUILD) \
                  -I$(LIBOGC_INC)

export LIBPATHS := -L$(LIBOGC_LIB) $(foreach dir,$(LIBDIRS),-L$(dir)/lib)

.PHONY: $(BUILD) clean debug all

#---------------------------------------------------------------------------------
all: $(BUILD)

#---------------------------------------------------------------------------------
$(BUILD):
	@[ -d $@ ] || mkdir -p $@
	@$(MAKE) --no-print-directory -C $(BUILD) -f $(CURDIR)/Makefile

#---------------------------------------------------------------------------------
clean:
	@echo clean ...
	@rm -rf $(BUILD) $(LIBTARGET)

#---------------------------------------------------------------------------------
debug:
	@echo "ALL_SOURCES:" && echo "$(ALL_SOURCES)" | tr ' ' '\n'
	@echo ""
	@echo "ALL_INCLUDES:" && echo "$(ALL_INCLUDES)" | tr ' ' '\n'
	@echo ""
	@echo "CFILES:" && echo "$(CFILES)" | tr ' ' '\n'
	@echo ""
	@echo "CPPFILES:" && echo "$(CPPFILES)" | tr ' ' '\n'

#---------------------------------------------------------------------------------
else
#============================= BUILD DIR =========================================

DEPENDS := $(OFILES:.o=.d)

#---------------------------------------------------------------------------------
# Build static library
#---------------------------------------------------------------------------------
$(LIBTARGET): $(OFILES)
	@echo "AR  $@"
	@$(AR) rcs $@ $(OFILES)

all: $(LIBTARGET)

#---------------------------------------------------------------------------------
$(OFILES_SRC): $(HFILES)

#---------------------------------------------------------------------------------
# Binary data rules
#---------------------------------------------------------------------------------
%.png.o %.jpg.o %.bmp.o %.bmf.o:
	@echo $(notdir $<)
	$(bin2o)

-include $(DEPENDS)

#---------------------------------------------------------------------------------
endif
#---------------------------------------------------------------------------------
