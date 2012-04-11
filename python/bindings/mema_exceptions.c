/*
 * This file is an example named ``This example``.
 *
 * ``This example`` is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * ``This example`` is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with ``This example``.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 * Copyright 2012 Vicente Ruiz Rodríguez <vruiz2.0@gmail.com>. All rights reserved.
 * http://www.menudoproblema.com/
 *
 */
#include <Python.h>

static PyObject*
mema_simple_exception(PyObject *self, PyObject* args)
{
	PyObject* bool_value = NULL;

	if(!PyArg_ParseTuple(args, "O", &bool_value))
	{
		return NULL;
	}

	if(!PyBool_Check(bool_value) && !PyInt_Check(bool_value))
	{
		PyErr_SetString(PyExc_TypeError, "bool_value must be bool or integer");
		return NULL;
	}

	Py_RETURN_NONE;
}

static PyObject*
mema_bad_example(PyObject *self, PyObject* args)
{
	PyObject* bool_value = NULL;

	if(!PyArg_ParseTuple(args, "O", &bool_value))
	{
		return NULL;
	}

	if(!PyBool_Check(bool_value) && !PyInt_Check(bool_value))
	{
		// It will show ``SystemError: error return without exception set`` because
		// you do not inform the python interpreter what exception you wanted to raise
		//PyErr_SetString(PyExc_TypeError, "bool_value must be bool or integer"); <-- It's missing
		return NULL;
	}

	Py_RETURN_NONE;
}

PyMethodDef methods[] = {
	{"simple_exception", mema_simple_exception, METH_VARARGS, "Simple exception."},
	{"bad_example", mema_bad_example, METH_VARARGS, "Bad example."},
	{NULL},
};

void initmema_exceptions()
{
	(void)Py_InitModule("mema_exceptions", methods);
}
