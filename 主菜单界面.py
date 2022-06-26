# -
import tkinter as tk
from tkinter import scrolledtext
import pyttsx3
spots=['stadium','auditorium','library','lecture hall','clinic building',
      'laboratory building','first dining hall','teaching building',
      'office building','gogo new world','octagon','tunnel',
      'second dining hall','youkang market','dorm']
window = tk.Tk()
window.title('School Guidance System')
window.geometry('750x700')
canvas=tk.Canvas(window,bg='white',height=500,width=700)
content_1="Stadium"
oval_1=canvas.create_oval(230,20,265,55,fill='#71ad91')
canvas.create_text(230,30,text=content_1,font=("Arial",7,"bold"))

canvas.create_line(247.5,55,287.5,115,fill='black',width=1)# 体育场与大会堂的边
# canvas.create_text(272,85,text="420",font=("Arial",7,"bold"))

canvas.create_line(244.5,54,235.5,190,fill='black',width=1)# 体育场与图书馆的边
# canvas.create_text(236,125,text="400",font=("Arial",7,"bold"))

canvas.create_line(265,37.5,387.5,150,fill='black',width=1)# 体育场与学术报告厅的边
# canvas.create_text(327,102,text='500',font=('Arial', 7, 'bold'))

content_2="Auditorium"
oval_2=canvas.create_oval(270,115,305,150,fill='#71ad91')
canvas.create_text(270,125,text=content_2,font=("Arial",7,"bold"))

canvas.create_line(270,132.5,237.5,190,fill='black',width=1)# 大会堂与图书馆的边
canvas.create_line(305,132.5,373,157,fill='black',width=1)# 大会堂与学术报告厅的边

content_3="Library"
oval_3=canvas.create_oval(220,190,255,225,fill='#71ad91')
canvas.create_text(220,200,text=content_3,font=("Arial",7,"bold"))

canvas.create_line(255,207.5,370,166,fill='black',width=1)# 图书馆与学术报告厅的边
canvas.create_line(222,213,170,290,fill='black',width=1)# 图书馆与一饭的边
canvas.create_line(250,218,310,246,fill='black',width=1)# 图书馆与教学楼的边

content_4="Lecture Hall"
oval_4=canvas.create_oval(370,150,405,185,fill='#71ad91')
canvas.create_text(410,160,text=content_4,font=("Arial",7,"bold"))

canvas.create_line(405,167.5,455,197,fill='black',width=1)# 学术报告厅与实验楼的边

canvas.create_line(310,260,177,311,fill='black',width=1)# 教学楼与一饭的边
canvas.create_line(330,270,455,215,fill='black',width=1)# 教学楼与实验楼的边

content_5="Clinic Building"
oval_5=canvas.create_oval(70,230,105,265,fill='#71ad91')
canvas.create_text(70,240,text=content_5,font=("Arial",7,"bold"))

canvas.create_line(105,247.5,156,294,fill='black',width=1)# 门诊楼与一饭的边

content_6="Laboratory"
oval_6=canvas.create_oval(450,190,485,225,fill='#71ad91')
canvas.create_text(450,200,text=content_6,font=("Arial",7,"bold"))

content_7="First Dining Hall"
oval_7=canvas.create_oval(150,290,185,325,fill='#71ad91')
canvas.create_text(150,300,text=content_7,font=("Arial",7,"bold"))

canvas.create_line(178,321,215,341,fill='black',width=1)# 一饭与隧道口的边
canvas.create_line(219,343,310,277,fill='black',width=1)# 隧道口与教学楼的边

content_8="Teaching Building"
oval_8=canvas.create_oval(300,245,335,280,fill='#71ad91')
canvas.create_text(300,255,text=content_8,font=("Arial",7,"bold"))

canvas.create_line(313.5,279,298,357,fill='black',width=1)# 教学楼与二饭的边
canvas.create_line(327.5,278,463,308,fill='black',width=1)# 教学楼与八角楼的边

content_9="Office Building"
oval_9=canvas.create_oval(530,250,565,285,fill='#71ad91')
canvas.create_text(580,260,text=content_9,font=("Arial",7,"bold"))

canvas.create_line(539,253,479,218,fill='black',width=1)# 办公楼与实验楼德的边
canvas.create_line(543,284,480,319,fill='black',width=1)# 办公楼与八角楼的边

content_10="GoGo New World"
oval_10=canvas.create_oval(10,280,45,315,fill='#71ad91')
canvas.create_text(56,295,text=content_10,font=("Arial",7,"bold"))

canvas.create_line(45,297.5,143,378,fill='black',width=1)# GOGO与又康的边

content_11="Octagon"
oval_11=canvas.create_oval(460,290,495,325,fill='#71ad91')
canvas.create_text(460,292,text=content_11,font=("Arial",7,"bold"))

content_12="Tunnel"
oval_12=canvas.create_oval(210,335,245,370,fill='#71ad91')
canvas.create_text(210,345,text=content_12,font=("Arial",7,"bold"))

canvas.create_line(245,357,285,361,fill='black',width=1)# 隧道口与二饭的边
canvas.create_line(210,357,175,390,fill='black',width=1)# 隧道口与又康的边

content_13="Second Dining Hall"
oval_13=canvas.create_oval(280,350,315,385,fill='#71ad91')
canvas.create_text(340,360,text=content_13,font=("Arial",7,"bold"))

content_14="Youkang Market"
oval_14=canvas.create_oval(140,370,175,405,fill='#71ad91')
canvas.create_text(140,380,text=content_14,font=("Arial",7,"bold"))

canvas.create_line(142,400,85,430,fill='black',width=1)# 宿舍与又康的边

content_15="Dorm"
oval_15=canvas.create_oval(50,410,85,445,fill='#71ad91')
canvas.create_text(50,420,text=content_15,font=("Arial",7,"bold"))
canvas.pack()

canvas.create_arc(12,-200,600,430,style='arc',start=243,extent=85,width=1)# 又康与办公楼的弧


def Answer_1():
      file=open("D:/Practice Week/Function_Choose.txt",'a+',encoding='utf-8')
      file.write('1\n')
      file.close()
      window.destroy()
def Answer_2():
      file=open("D:/Practice Week/Function_Choose.txt",'a+',encoding='utf-8')
      file.write('2\n')
      file.close()
      window.destroy()
def Answer_3():
      file=open("D:/Practice Week/Function_Choose.txt",'a+',encoding='utf-8')
      file.write('3\n')
      file.close()
      window.destroy()
def Answer_4():
      file=open("D:/Practice Week/Function_Choose.txt",'a+',encoding='utf-8')
      file.write('4\n')
      file.close()
      window.destroy()
def Answer_5():
      file=open("D:/Practice Week/Function_Choose.txt",'a+',encoding='utf-8')
      file.write('5\n')
      file.close()
      window.destroy()
def Answer_6():
      file=open("D:/Practice Week/Function_Choose.txt",'a+',encoding='utf-8')
      file.write('6\n')
      file.close()
      window.destroy()
def Answer_7():
      file=open("D:/Practice Week/Function_Choose.txt",'a+',encoding='utf-8')
      file.write('7\n')
      file.close()
      engine = pyttsx3.init()
      engine.say("欢迎使用广东外语外贸大学校园导航系统!没想到吧，我会说话！")
      engine.runAndWait()
      window.destroy()
def Answer_8():
      file=open("D:/Practice Week/Function_Choose.txt",'a+',encoding='utf-8')
      file.write('8\n')
      file.close()
      engine = pyttsx3.init()
      engine.say("感谢您的使用，咱们有缘再见,最后特别祝林华老师身体健康，工作顺利")
      engine.runAndWait()
      window.destroy()
label_0 = tk.Label(window,text='Please Choose The Function You Want.',fg='#000000',font = ('bold',12),width=60,height=2)
label_0.pack()

Matrix=tk.Button(window,fg='#FFFFFF',bg='cornflowerblue',text='Adjacent Matrix',width=42,height=1,command=Answer_1)# 输出邻接矩阵
Matrix.place(x=50,y=540)
# all_path.pack()
List=tk.Button(window,fg='#FFFFFF',bg='cornflowerblue',text='Adjacency List',width=42,height=1,command=Answer_2)# 输出邻接表
List.place(x=400,y=540)
# single_path.pack()
all_path=tk.Button(window,fg='#4169E2',text='Clock In The Campus',width=42,height=1,command=Answer_3)
all_path.place(x=50,y=580)
# # check_neigh.pack()
Neigh=tk.Button(window,fg='#4169E2',text='Check The Nearby Places',width=42,height=1,command=Answer_4)
Neigh.place(x=400,y=580)

single_path_0=tk.Button(window,fg='#FFFFFF',bg='cornflowerblue',text='Single-Path ( Shortest First )',width=42,height=1,command=Answer_5)
single_path_0.place(x=50,y=620)
# all_path.pack()
single_path_1=tk.Button(window,fg='#FFFFFF',bg='cornflowerblue',text='Single-Path ( Passing Minimum First )',width=42,height=1,command=Answer_6)
single_path_1.place(x=400,y=620)
# single_path.pack()
Modify=tk.Button(window,fg='#4169E2',text='Modifying The Distance Of Map',width=42,height=1,command=Answer_7)
Modify.place(x=50,y=660)
# # check_neigh.pack()
engine = pyttsx3.init()
engine.say("正在启动广东外语外贸大学校园导航系统!请稍等！")
engine.runAndWait()

Exit=tk.Button(window,fg='#4169E2',text='Exit The System',width=42,height=1,command=Answer_8)
Exit.place(x=400,y=660)

# label = tk.Label(window,text='Please Input Your Start:')
# label.pack()
# entry = tk.Entry(window,show=None)
# entry.pack()
#
# label_1 = tk.Label(window,text='Please Input Your Destination:')
# label_1.pack()
# entry_1 = tk.Entry(window,show=None)
# entry_1.pack()
#
# path = "D:/Practice Week/Search Record"
# def save(filename,content):
#     fh = open(filename,'a+',encoding='utf-8')
#     fh.write(content)
#     fh.close()
# def Answer():
#     start=entry.get().lower()
#     destination=entry_1.get().lower()
#     line=start+"    "+destination+"\n"
#     filename="D:/Practice Week/Search Record.txt"
#     if (start in spots) and (destination in spots):# 检验输入
#         save(filename,line)
#         window.destroy()
#     else:
#         t.insert('insert',"ATTENTION !!!: The location you inputted don't exist\n")
# b=tk.Button(window,text='Search For',width=10,height=2,command=Answer)
# b.pack()
# t = scrolledtext.ScrolledText(window,height=3)
# t.insert('insert',"Welcome to GDUFS. Wash you have a good trip !!!\n")
# t.pack()
#
window.mainloop()
