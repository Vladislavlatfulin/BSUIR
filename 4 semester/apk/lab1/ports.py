from traceback import print_tb
import serial
import time


def ports():
    firstPortsDevTtys = serial.Serial('/dev/ttys001')
    secondPortsDevTtys = serial.Serial('/dev/ttys002')

    print("first com port is open: " + str(firstPortsDevTtys.isOpen()))
    print("second com port is open: " + str(secondPortsDevTtys.isOpen()) + "\n")

    firstPortsDevTtys.write(b'sun')
    time.sleep(1)

    data = secondPortsDevTtys.read_all()

    print("second ports read: " + data + "\n")

    firstPortsDevTtys.close()
    print("first com port is open: " + str(firstPortsDevTtys.isOpen()))
    secondPortsDevTtys.close()
    print("second com port is open: " + str(secondPortsDevTtys.isOpen()))


if __name__ == '__main__':
    ports()
