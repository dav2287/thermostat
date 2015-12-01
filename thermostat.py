from htu21df import HTU21D
import time

def __init__(self):
    self.htu = HTU21D()

def get_temp_c():
    return htu.read_tmperature()

def get_temp_f():
    return htu.read_tmperature()*1.8+32

if __name__ == "__main__":
    while 1:
	print 'temperature', get_temp_f() 
	time.sleep(1)