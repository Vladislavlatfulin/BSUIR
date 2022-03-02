from traceback import print_tb
import serial


def serialPorts():
    port1 = serial.Serial('/dev/ttys001')
    port2 = serial.Serial('/dev/ttys002')

    print("Port1 is open: " + str(port1.isOpen()))
    print("Port2 is open: " + str(port2.isOpen()))

    port1.write(b'hello')
    print(port1.inWaiting())

    data = port2.read_all()

    print(data)

    port1.close()
    print("Port1 is closed")
    port2.close()
    print("Port2 is closed")


if __name__ == '__main__':
    serialPorts()
