# -
#include<Python.h>
#include<iostream>
using namespace std;
int main()
{
    int a;
    cin >> a;
    Py_SetPythonHome(L"D:/Anaconda");
    Py_Initialize();
    PyRun_SimpleString("b=int(input())");
    PyRun_SimpleString("print(b+1)");
    PyRun_SimpleString("import tkinter as tk");
    PyRun_SimpleString("window = tk.Tk()");
    PyRun_SimpleString("window.title('School Guidance System')");
    PyRun_SimpleString("window.geometry('750x700')");
    PyRun_SimpleString("canvas=tk.Canvas(window,bg='white',height=500,width=650)");
    PyRun_SimpleString("content_1 = 'Stadium'");
    PyRun_SimpleString("oval_1=canvas.create_oval(230,20,265,55,fill='#71ad91')");
    PyRun_SimpleString("canvas.create_text(230,30,text=content_1,font=('Arial',8,'bold'))");

    PyRun_SimpleString("canvas.create_line(247.5,55,287.5,115,fill='black',width=1)");
    PyRun_SimpleString("canvas.create_text(272,85,text='420',font=('Arial',7,'bold'))");

    PyRun_SimpleString("canvas.create_line(247.5,55,237.5,190,fill='black',width=1)");
    PyRun_SimpleString("canvas.create_text(236,125,text='400',font=('Arial',7,'bold'))");

    PyRun_SimpleString("canvas.create_line(265,37.5,387.5,150,fill='black',width=1)");
    PyRun_SimpleString("canvas.create_text(327,102,text='500',font=('Arial', 7, 'bold'))");

    PyRun_SimpleString("content_2='Auditorium'");
    PyRun_SimpleString("oval_2=canvas.create_oval(270,115,305,150,fill='#71ad91')");
    PyRun_SimpleString("canvas.create_text(280,125,text=content_2,font=('Arial',7,'bold'))");

    PyRun_SimpleString("content_3='Library'");
    PyRun_SimpleString("oval_3=canvas.create_oval(220,190,255,225,fill='#71ad91')");
    PyRun_SimpleString("canvas.create_text(220,200,text=content_3,font=('Arial',7,'bold'))");

    PyRun_SimpleString("content_4='Lecture Hall'");
    PyRun_SimpleString("oval_4=canvas.create_oval(370,150,405,185,fill='#71ad91')");
    PyRun_SimpleString("canvas.create_text(370,160,text=content_4,font=('Arial',7,'bold'))");

    PyRun_SimpleString("content_5='Clinic Building'");
    PyRun_SimpleString("oval_5=canvas.create_oval(70,230,105,265,fill='#71ad91')");
    PyRun_SimpleString("canvas.create_text(70,240,text=content_5,font=('Arial',7,'bold'))");

    PyRun_SimpleString("content_6='Laboratory Building'");
    PyRun_SimpleString("oval_6=canvas.create_oval(450,190,485,225,fill='#71ad91')");
    PyRun_SimpleString("canvas.create_text(450,200,text=content_6,font=('Arial',7,'bold'))");

    PyRun_SimpleString("content_7='First Dining Hall'");
    PyRun_SimpleString("oval_7=canvas.create_oval(150,290,185,325,fill='#71ad91')");
    PyRun_SimpleString("canvas.create_text(150,300,text=content_7,font=('Arial',7,'bold'))");

    PyRun_SimpleString("content_8='Teaching Building'");
    PyRun_SimpleString("oval_8=canvas.create_oval(300,245,335,280,fill='#71ad91')");
    PyRun_SimpleString("canvas.create_text(300,255,text=content_8,font=('Arial',7,'bold'))");

    PyRun_SimpleString("content_9='Office Building'");
    PyRun_SimpleString("oval_9=canvas.create_oval(530,250,565,285,fill='#71ad91')");
    PyRun_SimpleString("canvas.create_text(530,260,text=content_9,font=('Arial',7,'bold'))");

    PyRun_SimpleString("content_10='GoGo New World'");
    PyRun_SimpleString("oval_10=canvas.create_oval(10,280,45,315,fill='#71ad91')");
    PyRun_SimpleString("canvas.create_text(45,295,text=content_10,font=('Arial',7,'bold'))");

    PyRun_SimpleString("content_11='Octagon House'");
    PyRun_SimpleString("oval_11=canvas.create_oval(460,290,495,325,fill='#71ad91')");
    PyRun_SimpleString("canvas.create_text(460,300,text=content_11,font=('Arial',7,'bold'))");

    PyRun_SimpleString("content_12='Tunnel'");
    PyRun_SimpleString("oval_12=canvas.create_oval(210,335,245,370,fill='#71ad91')");
    PyRun_SimpleString("canvas.create_text(210,345,text=content_12,font=('Arial',7,'bold'))");

    PyRun_SimpleString("content_13='Second Dining Hall'");
    PyRun_SimpleString("oval_13=canvas.create_oval(280,350,315,385,fill='#71ad91')");
    PyRun_SimpleString("canvas.create_text(290,365,text=content_13,font=('Arial',7,'bold'))");

    PyRun_SimpleString("content_14='Youkang Market'");
    PyRun_SimpleString("oval_14=canvas.create_oval(140,370,175,405,fill='#71ad91')");
    PyRun_SimpleString("canvas.create_text(140,380,text=content_14,font=('Arial',7,'bold'))");

    PyRun_SimpleString("content_15='Dorm'");
    PyRun_SimpleString("oval_15=canvas.create_oval(50,410,85,445,fill='#71ad91')");
    PyRun_SimpleString("canvas.create_text(55,425,text=content_15,font=('Arial',7,'bold'))");

    
    PyRun_SimpleString("canvas.pack()");

    PyRun_SimpleString("label = tk.Label(window,text='Please input your start:')");
    PyRun_SimpleString("label.pack()");
    PyRun_SimpleString("entry = tk.Entry(window,show=None)");
    PyRun_SimpleString("entry.pack()");

    PyRun_SimpleString("label_1 = tk.Label(window,text='Please input your deatination:')");
    PyRun_SimpleString("label_1.pack()");
    PyRun_SimpleString("entry_1 = tk.Entry(window,show=None)");
    PyRun_SimpleString("entry_1.pack()");

    PyRun_SimpleString("window.mainloop()");
    Py_Finalize();
    cout << a << endl;

}
