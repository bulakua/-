# -
import tkinter as tk
window = tk.Tk()
window.title('校园导航系统')
window.geometry('750x700')
canvas=tk.Canvas(window,bg='white',height=500,width=680)
# window.mainloop()
# x0,y0,x1,y1=50,50,80,80
content_1="体育场"
oval_1=canvas.create_oval(230,20,265,55,fill='#71ad91')
canvas.create_text(230,30,text=content_1,font=("Arial",8,"bold"))

canvas.create_line(247.5,55,287.5,115,fill='black',width=1)# 体育场与大会堂的边
canvas.create_text(272,85,text="420",font=("Arial",7,"bold"))

canvas.create_line(247.5,55,237.5,190,fill='black',width=1)# 体育场与图书馆的边
canvas.create_text(236,125,text="400",font=("Arial",7,"bold"))

canvas.create_line(265,37.5,387.5,150,fill='black',width=1)# 体育场与学术报告厅的边


content_2="大会堂"
oval_2=canvas.create_oval(270,115,305,150,fill='#71ad91')
canvas.create_text(270,125,text=content_2,font=("Arial",8,"bold"))

content_3="图书馆"
oval_3=canvas.create_oval(220,190,255,225,fill='#71ad91')
canvas.create_text(220,200,text=content_3,font=("Arial",8,"bold"))

content_4="学术报告厅"
oval_4=canvas.create_oval(370,150,405,185,fill='#71ad91')
canvas.create_text(370,160,text=content_4,font=("Arial",8,"bold"))

content_5="门诊楼"
oval_5=canvas.create_oval(70,230,105,265,fill='#71ad91')
canvas.create_text(70,240,text=content_5,font=("Arial",8,"bold"))

content_6="实验楼"
oval_6=canvas.create_oval(450,190,485,225,fill='#71ad91')
canvas.create_text(450,200,text=content_6,font=("Arial",8,"bold"))

content_7="第一饭堂"
oval_7=canvas.create_oval(150,290,185,325,fill='#71ad91')
canvas.create_text(150,300,text=content_7,font=("Arial",8,"bold"))

content_8="教学楼"
oval_8=canvas.create_oval(300,245,335,280,fill='#71ad91')
canvas.create_text(300,255,text=content_8,font=("Arial",8,"bold"))

content_9="办公楼"
oval_9=canvas.create_oval(530,250,565,285,fill='#71ad91')
canvas.create_text(530,260,text=content_9,font=("Arial",8,"bold"))

content_10="GoGo新天地"
oval_10=canvas.create_oval(10,280,45,315,fill='#71ad91')
canvas.create_text(37,295,text=content_10,font=("Arial",8,"bold"))

content_11="八角楼"
oval_11=canvas.create_oval(460,290,495,325,fill='#71ad91')
canvas.create_text(460,300,text=content_11,font=("Arial",8,"bold"))

content_12="隧道口"
oval_12=canvas.create_oval(210,335,245,370,fill='#71ad91')
canvas.create_text(210,345,text=content_12,font=("Arial",8,"bold"))

content_13="第二饭堂"
oval_13=canvas.create_oval(280,350,315,385,fill='#71ad91')
canvas.create_text(280,360,text=content_13,font=("Arial",8,"bold"))

content_14="又康超市"
oval_14=canvas.create_oval(140,370,175,405,fill='#71ad91')
canvas.create_text(140,380,text=content_14,font=("Arial",8,"bold"))

content_15="宿舍"
oval_15=canvas.create_oval(50,410,85,445,fill='#71ad91')
canvas.create_text(50,420,text=content_15,font=("Arial",8,"bold"))
canvas.pack()

label = tk.Label(window,text='请选择您出发的地点:')
label.pack()
entry = tk.Entry(window,show=None)
entry.pack()

label_1 = tk.Label(window,text='请选择您到达的地点:')
label_1.pack()
entry_1 = tk.Entry(window,show=None)
entry_1.pack()
def Answer():
    start=entry.get()
    destination=entry_1.get()
    if start == '体育场' and destination == '大会堂':
        express = '最短路径为:体育场->大会堂'
        t.insert('insert', express)
b=tk.Button(window,text='Search For',width=10,height=2,command=Answer)
b.pack()
t = tk.Text(window,height=3)
t.pack()

window.mainloop()
