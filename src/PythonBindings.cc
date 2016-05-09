#include "PythonBindings.h"

PythonBindings::PythonBindings(){}

BOOST_PYTHON_MODULE(bosscube)
{
	boost::python::class_<GameAssetManager>("GameAssetManager")
                            .def("AddAsset", &GameAssetManager::AddAsset)
                            .def("UpdateCameraPosition", &GameAssetManager::UpdateCameraPosition)
    ;
}

// g++ -DGL_GLEXT_PROTOTYPES -DGL3_PROTOTYPES -std=c++11 -I/usr/include/python2.7 -fPIC -shared *.cc *.h -o py.so
