import mema_exceptions


try:
    mema_exceptions.simple_exception()
except TypeError:
    print('``simple_exception``: No arguments')

try:
    mema_exceptions.simple_exception('string')
except TypeError:
    print('``simple_exception``: String argument')


mema_exceptions.simple_exception(True)
mema_exceptions.simple_exception(2)


try:
    mema_exceptions.bad_example()
except SystemError:
    print('``bad_example``: SystemError')
