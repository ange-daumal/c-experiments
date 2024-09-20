#include <Python.h>

static PyObject* add(PyObject* self, PyObject* args) {
	int a, b;
	if (!PyArg_ParseTuple(args, "ii", &a, &b)) {
		return NULL;
	}
	
	int result = a + b;
	return PyLong_FromLong(result);
};

static PyMethodDef MyMethods[] = {
	{"add", add, METH_VARARGS, "Add two numbers"},
	{NULL, NULL, 0, NULL}, // Sentinel
};

static struct PyModuleDef mymodule = {
	PyModuleDef_HEAD_INIT,
	"mymodule",
	NULL,		// Doc
	-1,		// Size of per-interpreter state of the module, or -1 if the module keeps state in global variables
	MyMethods
};

PyMODINIT_FUNC PyInit_mymodule(void) {
	return PyModule_Create(&mymodule);
};
