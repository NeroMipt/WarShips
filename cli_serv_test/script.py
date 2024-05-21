import os
import time

pid = os.fork()

if pid == 0:
    os.system("cd server; qmake untitled.pro; make; ./untitled")

else:
    pid1 = os.fork()
    if pid1 == 0:
        os.system("sleep 1")
        os.system("cd client_test; qmake client_test.pro; make; ./client_test; diff -s input.txt output.txt")