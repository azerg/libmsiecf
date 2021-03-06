/*
 * Python object definition of the items sequence and iterator
 *
 * Copyright (C) 2009-2016, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined( _PYMSIECF_ITEMS_H )
#define _PYMSIECF_ITEMS_H

#include <common.h>
#include <types.h>

#include "pymsiecf_file.h"
#include "pymsiecf_libmsiecf.h"
#include "pymsiecf_python.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct pymsiecf_items pymsiecf_items_t;

struct pymsiecf_items
{
	/* Python object initialization
	 */
	PyObject_HEAD

	/* The file object
	 */
	pymsiecf_file_t *file_object;

	/* The get item by index callback function
	 */
	PyObject* (*get_item_by_index)(
	             pymsiecf_file_t *file_object,
	             int item_index );

	/* The (current) item index
	 */
	int item_index;

	/* The number of items
	 */
	int number_of_items;
};

extern PyTypeObject pymsiecf_items_type_object;

PyObject *pymsiecf_items_new(
           pymsiecf_file_t *file_object,
           PyObject* (*get_item_by_index)(
                        pymsiecf_file_t *file_object,
                        int item_index ),
           int number_of_items );

int pymsiecf_items_init(
     pymsiecf_items_t *pymsiecf_items );

void pymsiecf_items_free(
      pymsiecf_items_t *pymsiecf_items );

Py_ssize_t pymsiecf_items_len(
            pymsiecf_items_t *pymsiecf_items );

PyObject *pymsiecf_items_getitem(
           pymsiecf_items_t *pymsiecf_items,
           Py_ssize_t item_index );

PyObject *pymsiecf_items_iter(
           pymsiecf_items_t *pymsiecf_items );

PyObject *pymsiecf_items_iternext(
           pymsiecf_items_t *pymsiecf_items );

#if defined( __cplusplus )
}
#endif

#endif

