#!/usr/bin/python3
def no_c(my_string):
    chars = ""
    for i in my_string:
        if (i != 'c' and i != 'C'):
            chars = chars + i
    return chars
