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
 * More info (spanish):
 *    http://www.menudoproblema.es/blog/entries/2012/03/27/bindings-python-para-bibliotecas-c-parte-3/
 *    http://www.menudoproblema.es/blog/entries/2012/03/28/bindings-python-para-bibliotecas-c-parte-4/
 *
 */
#include <Python.h>

PyObject *mema_hello(PyObject *self, PyObject* args)
{
	char *name = NULL;

	if (PyArg_ParseTuple(args, "|s", &name))
	{
		if (name)
		{
			printf("Hello %s!\n", name);
		}
		else
		{
			printf("Hello mema!\n");
		}
		return Py_BuildValue("");
	}

	return NULL;
}

PyObject *mema_add(PyObject *self, PyObject* args)
{
	PyObject *result = NULL;
	long a, b;

	if (PyArg_ParseTuple(args, "ii", &a, &b))
	{
		result = Py_BuildValue("i", a + b);
	}

	return result;
}

PyMethodDef methods[] = {
	{"add", mema_add, METH_VARARGS, "Sum two numbers."},
	{"hello", mema_hello, METH_VARARGS, "Hello world!"},
	{NULL},
};

void initmema_functions()
{
	(void)Py_InitModule("mema_functions", methods);
}
