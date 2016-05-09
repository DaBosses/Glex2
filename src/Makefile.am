EXTRA_DIST = GameWorld.h GameAssetManager.h GameAsset.h CubeAsset.h Camera.h BoundingBox.h ColourManager.h PythonBindings.h

bin_PROGRAMS = bosscube
bosscube_SOURCES = main.cc GameWorld.cc GameAssetManager.cc CubeAsset.cc Camera.cc BoundingBox.cc GameAsset.cc ColourManager.cc PythonBindings.o

AM_CPPFLAGS = -DGL_GLEXT_PROTOTYPES -DGL3_PROTOTYPES
AM_CPPFLAGS += -std=c++11 -I/usr/include/python2.7
AM_CPPFLAGS += $(gl_CFLAGS) $(glew_CFLAGS) $(sdl2_CFLAGS) $(BOOST_CPPFLAGS)
LIBS += $(gl_LIBS) $(glew_LIBS) $(sdl2_LIBS) $(BOOST_THREAD_LIBS) $(BOOST_PROGRAM_OPTIONS_LIBS)
