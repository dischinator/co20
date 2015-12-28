OS=$(shell uname)

ifneq (,$(findstring MINGW,$(OS)))
	FILE=Makefile.mingw
else
	FILE=Makefile.default
endif

include $(FILE)
