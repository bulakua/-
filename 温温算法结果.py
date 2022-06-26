# -
import tkinter as tk
from tkinter import scrolledtext
window = tk.Tk()
window.title('School Guidance System')
window.geometry('910x715')
t = scrolledtext.ScrolledText(window,width=125,height=7,bg='white')
f= open("D:/Practice Week/FDfsFindans.txt","r")
# spots=['STA','LEC','AUD','LIB','LAB',
#       'TEA','OCT','OFF',
#       'FIR','TUN','SEC','CLI',
#       'YOU','GOG','DOR']
# t.insert('insert',"\tSTA\tLEC\tAUD\tLIB\tLAB\tTEA\tOCT\tOFF\tFIR\tTUN\tSEC\tCLI\tYOU\tGOG\tDOR\n")
# for lines in f.readlines():
#     t.insert('insert', spots[a])
#     t.insert('insert', '\t')
#     a+=1
#     for line in lines:
#         if line=='%':
#             t.insert('insert','\t')
#         else:
#             t.insert('insert',line)
#     t.insert('insert', '\n')
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
# spots=['STA','LEC','AUD','LIB','LAB',
#       'TEA','OCT','OFF',
#       'FIR','TUN','SEC','CLI',
#       'YOU','GOG','DOR']
# t.insert('insert',"\tSTA\tLEC\tAUD\tLIB\tLAB\tTEA\tOCT\tOFF\tFIR\tTUN\tSEC\tCLI\tYOU\tGOG\tDOR\n")
# for lines in f.readlines():
#     t.insert('insert', spots[a])
#     t.insert('insert', '\t')
#     a+=1
#     for line in lines:
#         if line=='%':
#             t.insert('insert','\t')
#         else:
#             t.insert('insert',line)
#     t.insert('insert', '\n')
Index=1
for lines in f:
    # t.insert('insert', spots[a])
    t.insert('insert', '')
    for line in lines:
        if line=='%':
            t.insert('insert','\t\t')
            t.insert('insert','->')
            t.insert('insert', '\t\t')
            Index+=1
            if Index % 4 == 0:
                t.insert('insert', '\n\n')
        elif line=='#':
            t.insert('insert','\n\n\n')
            t.insert('insert','\t\t\t\t')
            t.insert('insert','Finish This Clock In School Will Cost ')
        else:
            t.insert('insert',line)
        # if Index%5==0:
            # t.insert('insert', '\n\t')
    # print(lines)
    t.insert('insert', 'm')
    t.insert('insert', '\n')
t.pack()

_0=tk.Button(window,fg='#4169E2',text='STA:体育场',width=15,height=1)
_0.place(x=20,y=605)
_1=tk.Button(window,fg='#4169E2',text='LEC:学术报告厅',width=15,height=1)
_1.place(x=20,y=640)
_2=tk.Button(window,fg='#4169E2',text='AUD:大会堂',width=15,height=1)
_2.place(x=20,y=675)


_3=tk.Button(window,fg='#FFFFFF',bg='cornflowerblue',text='LIB:图书馆',width=15,height=1)
_3.place(x=160,y=605)
_4=tk.Button(window,fg='#FFFFFF',bg='cornflowerblue',text='LAB:实验楼',width=15,height=1)
_4.place(x=160,y=640)
_5=tk.Button(window,fg='#FFFFFF',bg='cornflowerblue',text='TEA:教学楼',width=15,height=1)
_5.place(x=160,y=675)

_6=tk.Button(window,fg='#4169E2',text='OCT:八角楼',width=15,height=1)
_6.place(x=300,y=605)
_7=tk.Button(window,fg='#4169E2',text='OFF:办公楼',width=15,height=1)
_7.place(x=300,y=640)
_8=tk.Button(window,fg='#4169E2',text='FIR:第一饭堂',width=15,height=1)
_8.place(x=300,y=675)

_9=tk.Button(window,fg='#FFFFFF',bg='cornflowerblue',text='TUN:隧道口',width=15,height=1)
_9.place(x=440,y=605)
_10=tk.Button(window,fg='#FFFFFF',bg='cornflowerblue',text='SEC:第二饭堂',width=15,height=1)
_10.place(x=440,y=640)
_11=tk.Button(window,fg='#FFFFFF',bg='cornflowerblue',text='CLI:门诊部',width=15,height=1)
_11.place(x=440,y=675)

_12=tk.Button(window,fg='#4169E2',text='YOU:又康超市',width=15,height=1)
_12.place(x=580,y=605)
_13=tk.Button(window,fg='#4169E2',text='GOG:GoGo新天地',width=15,height=1)
_13.place(x=580,y=640)
_14=tk.Button(window,fg='#4169E2',text='DOR:宿舍',width=15,height=1)
_14.place(x=580,y=675)

def quit():
    window.destroy()

_11=tk.Button(window,fg='#FFFFFF',bg='lightcoral',text='RETURN MENU',width=22,height=3,command=quit)
_11.place(x=720,y=640)
window.mainloop()
