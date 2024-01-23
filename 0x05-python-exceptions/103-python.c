#include <Python.h>

/**
 * print_python_list - Prints some basic info about Python lists
 * @p: PyObject pointer to a Python list
 */
void print_python_list(PyObject *p)
{
    Py_ssize_t size, i;
    PyObject *item;

    if (!PyList_Check(p))
    {
        fprintf(stderr, "[ERROR] Invalid List Object\n");
        return;
    }

    size = PyList_Size(p);
    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %zd\n", size);
    printf("[*] Allocated = %zd\n", ((PyListObject *)p)->allocated);

    for (i = 0; i < size; i++)
    {
        item = PyList_GetItem(p, i);
        printf("Element %zd: %s\n", i, Py_TYPE(item)->tp_name);
    }
}

/**
 * print_python_bytes - Prints some basic info about Python bytes
 * @p: PyObject pointer to a Python bytes object
 */
void print_python_bytes(PyObject *p)
{
    Py_ssize_t size, i;
    char *str;

    if (!PyBytes_Check(p))
    {
        fprintf(stderr, "[ERROR] Invalid Bytes Object\n");
        return;
    }

    size = PyBytes_Size(p);
    printf("[.] bytes object info\n");
    printf("  size: %zd\n", size);
    printf("  trying string: %s\n", PyBytes_AsString(p));

    printf("  first 10 bytes: ");
    str = PyBytes_AsString(p);
    for (i = 0; i < size && i < 10; i++)
        printf("%02x ", (unsigned char)str[i]);
    printf("\n");
}

/**
 * print_python_float - Prints some basic info about Python float
 * @p: PyObject pointer to a Python float object
 */
void print_python_float(PyObject *p)
{
    if (!PyFloat_Check(p))
    {
        fprintf(stderr, "[ERROR] Invalid Float Object\n");
        return;
    }

    printf("[.] float object info\n");
    printf("  value: %f\n", PyFloat_AsDouble(p));
}
