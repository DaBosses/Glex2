EXTRA_DIST = camera.h cube.h shader.h transform.h window.h

bin_PROGRAMS = endcube

endcube_SOURCES = main.cpp cube.cpp shader.cpp window.cpp

AM_CPPFLAGS = -DGL_GLEXT_PROTOTYPES -DGL3_PROTOTYPES
AM_CPPFLAGS += -std=c++11
AM_CPPFLAGS += $(gl_CFLAGS) $(glew_CFLAGS) $(sdl2_CFLAGS)
LIBS += $(gl_LIBS) $(glew_LIBS) $(sdl2_LIBS) 

