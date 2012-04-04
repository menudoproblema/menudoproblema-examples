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
 *    http://www.menudoproblema.es/blog/entries/2012/03/26/bindings-python-para-bibliotecas-c-parte-2/
 *
 */
#include <Python.h>

static PyMethodDef methods[] = {
	{NULL},
};

void initmema_bare()
{
	(void)Py_InitModule("mema_bare", methods);
}
