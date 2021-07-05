##
## EPITECH PROJECT, 2021
## Corewar - Bonus
## File description:
## Mouli ASM
##

import os
import subprocess
import sys
import string
import time
from tkinter import *
from tkinter.ttk import Label
from datetime import datetime
import subprocess

def helper():
    print("Graphical moulinette\npython mouli.py [FLAG]\n\nFLAG : \n\n\t-h : Print helper.\n\t-r : Print logs in console.\n\n Check logs in /logs folder.\n")

def switch_logs(wrapper_logs):
    if wrapper_logs[0].get() == "OFF":
        wrapper_logs[0].set("ON")
    else:
        wrapper_logs[0].set("OFF")

def launch_error_test(raw, logs, wrapper):
    error = os.listdir('input_error')
    err = 0
    nbr_total = len(error)
    if raw == 1:
        print("\nERROR TEST\n")
    if (raw == 0 and logs[0].get() == "ON"):
        now = datetime.now()
        current_time = now.strftime("%d:%m:%Y:%H-%M-%S")
        file = open("./logs/errors/" + current_time + ".txt", "w")
        file.write("ERRROR TEST\n\n")

    for i in error:
        result = subprocess.run(
        ["./../../asm/asm", "./input_error/" + i], capture_output=True, text=True
        )
        if (int(result.returncode) != 84):
            print(i + " -> " + str(result.stderr))
            err += 1
        if (raw == 0 and logs[0].get() == "ON"):
            if (int(result.returncode) != 84):
                file.write("\t" + i + "->" + str(result.stderr) + " : Failed !\n")
            else:
                file.write("\t" + i + "->" + " : Passed !\n")


    result = "Test handle error : " + str(nbr_total - err) + " / " + str(nbr_total)
    if raw == 1:
        print(result)
    if raw == 0 and logs[0].get() == "ON":
        file.write("\n\n" + result + "\n")
    if err == 0 and raw == 1:
        print("Toutes les erreurs ont été detecté.\n\n")
    if err == 0 and raw == 0 and logs[0].get() == "ON":
        file.write("Toutes les erreurs ont été detecté.")
        file.close()
    if (raw == 0):
        wrapper[0].set(result)



def launch_compilation_test(raw, logs, wrapper):
    input_champ = os.listdir('input')
    correct_champ = os.listdir('correct')
    nbr_total = len(input_champ)
    err = 0
    file = 0
    if (raw == 0 and logs[0].get() == "ON"):
        now = datetime.now()
        current_time = now.strftime("%d:%m:%Y:%H-%M-%S")
        file = open("./logs/compilation/" + current_time + ".txt", "w")
        file.write("COMPILATION TEST\n\n")

    for x,y in zip(input_champ, correct_champ):
        result = subprocess.run(
        ["./../../asm/asm", "./input/" + x], capture_output=True, text=True
        )
        if (int(result.returncode) == 84):
            print(x + " -> " + str(result.stderr) + "\n" + str(result.stdout))
            err += 1
            continue
        if (raw == 0 and logs[0].get() == "ON"):
            if (int(result.returncode) == 84):
                file.write("\t" + x + "->" + str(result.stderr) + " : Failed !\n")
            else:
                file.write("\t" + x + "->" + " : Passed !\n")
        result = subprocess.run(
        ["./binaire_ref/asm", "./correct/" + y], capture_output=True, text=True
        )
    if (raw == 0 and logs[0].get() == "ON"):
        file.write("\n\nDIFF FILE\n\n")
    result = launch_diff_test(raw, logs, file)
    if (raw == 0):
        wrapper[0].set(result)
    if (raw == 0 and logs[0].get() == "ON"):
        file.close()

def launch_diff_test(raw, logs, file):
    input_champ = os.listdir('input')
    correct_champ = os.listdir('correct')
    nbr_total = len(input_champ)
    err = 0
    for x,y in zip(input_champ, correct_champ):
        result = subprocess.run(
        ["diff", x[:-1] + "cor", "r" + x[:-1] + "cor"], capture_output=True, text=True
        )
        if (int(result.returncode) != 0):
            print(x[:-1] + "cor" + " -> " + str(result.returncode))
            print("r" + x[:-1] + "cor" + " -> " + str(result.returncode))
            err += 1
        if (raw == 0 and logs[0].get() == "ON"):
            if (int(result.returncode) != 0):
                file.write("\t" + x[:-1] + "-> : Failed !\n")
            else:
                file.write("\t" + x[:-1] + "-> : Passed !\n")
        result = subprocess.run(
        ["rm", x[:-1] + "cor", "r" + x[:-1] + "cor"], capture_output=True, text=True
        )
    result = "Test Compilation: " + str(nbr_total - err) + " / " + str(nbr_total)
    if raw == 1:
        print(result)
    if (raw == 0 and logs[0].get() == "ON"):
        file.write("\n\n" + result + "\n")
    if err == 0 and raw == 1:
        print("Aucune difference entre la compilation de reference et la notre.\n\n")
    if (err == 0 and raw == 0 and logs[0].get() == "ON"):
        file.write("Aucune difference entre la compilation de reference et la notre.\n")
    return result

class App(object):
    """
        Application for graphical test
    """
    def __init__(self, master) -> None:
        self.master = master
        wrapper1 = []
        wrapper2 = []
        wrapper_logs1 = []
        wrapper_logs2 = []
        Label(self.master, text="Corewar", font=("Arial", 50)).place(x=335, y=35)
        btn = Button(self.master, text="Tests errors cases", fg="red" , font=("Arial", 15), command=lambda: launch_error_test(0, wrapper_logs1, wrapper1))
        btn.place(x=100, y=180)
        btn2 = Button(self.master, text="Tests Compilation", fg="green" , font=("Arial", 15), command=lambda: launch_compilation_test(0, wrapper_logs2, wrapper2))
        btn2.place(x=100, y=435)
        btn3 = Button(self.master, text="Logs : ", font=("Arial", 15), command=lambda: switch_logs(wrapper_logs1))
        btn3.place(x=100, y=230)
        btn4 = Button(self.master, text="Logs : ", font=("Arial", 15), command=lambda: switch_logs(wrapper_logs2))
        btn4.place(x=100, y=480)
        result_error = StringVar()
        result_compil = StringVar()
        logs1 = StringVar()
        logs2 = StringVar()
        logs1.set("OFF")
        logs2.set("OFF")
        result_error.set("")
        result_compil.set("")
        wrapper1.append(result_error)
        wrapper2.append(result_compil)
        wrapper_logs1.append(logs1)
        wrapper_logs2.append(logs2)
        self.logs1 = 0
        self.logs2 = 0
        label1 = Label(self.master, textvariable=logs1, font=("Arial", 25)).place(x=200, y=230)
        label2 = Label(self.master, textvariable=logs2, font=("Arial", 25)).place(x=200, y=480)
        label3 = Label(self.master, textvariable=wrapper1[0], font=("Arial", 15)).place(x=300, y=185)
        label4 = Label(self.master, textvariable=wrapper2[0], font=("Arial", 15)).place(x=300, y=440)

def main(argv):
    if (len(argv) == 2 and argv[1] == "-h"):
        helper()
        exit(0)
    if (len(argv) == 2 and argv[1] == "-r"):
        launch_error_test(1, 0, 0)
        launch_compilation_test(1, 0, 0)
        exit(0)
    window = Tk()
    window.geometry("800x600+550+200")
    App(window)
    window.mainloop()

try:
    sys.exit(main(sys.argv))
except Exception as e:
    print("Error:", e, file=sys.stderr)
    exit(84)