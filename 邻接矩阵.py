# -
import tkinter as tk
from tkinter import scrolledtext
import pyttsx3
window = tk.Tk()
window.title('School Guidance System')
window.geometry('910x715')
t = scrolledtext.ScrolledText(window,width=125,height=46,bg='white')
f= open("D:/Practice Week/Matrix.txt","r")
spots=['STA','LEC','AUD','LIB','LAB',
      'TEA','OCT','OFF',
      'FIR','TUN','SEC','CLI',
      'YOU','GOG','DOR']
a=0
t.insert('insert',"\tSTA\tLEC\tAUD\tLIB\tLAB\tTEA\tOCT\tOFF\tFIR\tTUN\tSEC\tCLI\tYOU\tGOG\tDOR\n")
for lines in f.readlines():
    t.insert('insert', spots[a])
    t.insert('insert', '\t')
    a+=1
    for line in lines:
        if line=='%':
            t.insert('insert','\t')
        else:
            t.insert('insert',line)
    t.insert('insert', '\n')
t.pack()

def STA():
    engine = pyttsx3.init()
    engine.say("广外体育场是同学们课后运动和打卡的地方，是同学们放松、挥洒汗水的地方")
    engine.runAndWait()

def LEC():
    engine = pyttsx3.init()
    engine.say("您已到达学术报告厅")
    engine.runAndWait()

def AUD():
    engine = pyttsx3.init()
    engine.say("您已到达广东外语外贸大学大会堂，此处是广外各学院开展讲座、颁奖典礼、学习分享等活动的地方，设施完善，环境严肃典雅")
    engine.runAndWait()

def LIB():
    engine = pyttsx3.init()
    engine.say("广东外语外贸大学图书馆,广外卷王的聚集地,还有,哥们，别卷了！")
    engine.runAndWait()

def LAB():
    engine = pyttsx3.init()
    engine.say("目的地实验楼，这是广外卷王们的实验聚集地，也是计算机专业同学学习技能的地方")
    engine.runAndWait()

def TEA():
    engine = pyttsx3.init()
    engine.say("好好学习，我爱华姐的课，更爱海涛哥的课,谢谢师座")
    engine.runAndWait()

def OCT():
    engine = pyttsx3.init()
    engine.say("您已到达八角楼，八角楼是广外开设讲座的地方，设施配套完善，紧靠着老师们的办公楼")
    engine.runAndWait()

def OFF():
    engine = pyttsx3.init()
    engine.say("老师办公的地方，啊！老师，您是辛勤的劳工")
    engine.runAndWait()

def FIR():
    engine = pyttsx3.init()
    engine.say(
        "第一食堂，也叫文采园,一饭一楼的湖南人家、小火锅、甜品都会开的比较晚，晚课结束之后就再也不用担心饿肚子啦！一饭二楼也有超级多好吃的！烧腊饭、肠粉、四川冒菜、麻辣烫、魔饭青年、石锅饭、蛋包饭、有营（饮品店）等等")
    engine.runAndWait()

def TUN():
    engine = pyttsx3.init()
    engine.say("隧道口是连接教学区和生活区的便捷之路")
    engine.runAndWait()


def SEC():
    engine = pyttsx3.init()
    engine.say("第二饭堂，也叫博雅园,一饭二楼也有超级多好吃的！烧腊饭、肠粉、四川冒菜、麻辣烫、魔饭青年、石锅饭、蛋包饭、有营（饮品店）等等,二饭二有韩式石锅饭、饭团焗饭、小炒、鸡公煲、烤鱼、花甲粉等等")
    engine.runAndWait()

def CLI():
    engine = pyttsx3.init()
    engine.say("目的地广外门诊楼")
    engine.runAndWait()

def YOU():
    engine = pyttsx3.init()
    engine.say("目的地又康超市")
    engine.runAndWait()

def GOG():
    engine = pyttsx3.init()
    engine.say("GoGo新天地是广外人校外休闲聚餐的好去处")
    engine.runAndWait()

def DOR():
    engine = pyttsx3.init()
    engine.say("目的地广东外语外贸大学学生宿舍")
    engine.runAndWait()


_0=tk.Button(window,fg='#4169E2',text='STA:体育场',width=15,height=1,command=STA)
_0.place(x=20,y=605)
_1=tk.Button(window,fg='#4169E2',text='LEC:学术报告厅',width=15,height=1,command=LEC)
_1.place(x=20,y=640)
_2=tk.Button(window,fg='#4169E2',text='AUD:大会堂',width=15,height=1,command=AUD)
_2.place(x=20,y=675)


_3=tk.Button(window,fg='#FFFFFF',bg='cornflowerblue',text='LIB:图书馆',width=15,height=1,command=LIB)
_3.place(x=160,y=605)
_4=tk.Button(window,fg='#FFFFFF',bg='cornflowerblue',text='LAB:实验楼',width=15,height=1,command=LAB)
_4.place(x=160,y=640)
_5=tk.Button(window,fg='#FFFFFF',bg='cornflowerblue',text='TEA:教学楼',width=15,height=1,command=TEA)
_5.place(x=160,y=675)

_6=tk.Button(window,fg='#4169E2',text='OCT:八角楼',width=15,height=1,command=OCT)
_6.place(x=300,y=605)
_7=tk.Button(window,fg='#4169E2',text='OFF:办公楼',width=15,height=1,command=OFF)
_7.place(x=300,y=640)
_8=tk.Button(window,fg='#4169E2',text='FIR:第一饭堂',width=15,height=1,command=FIR)
_8.place(x=300,y=675)

_9=tk.Button(window,fg='#FFFFFF',bg='cornflowerblue',text='TUN:隧道口',width=15,height=1,command=TUN)
_9.place(x=440,y=605)
_10=tk.Button(window,fg='#FFFFFF',bg='cornflowerblue',text='SEC:第二饭堂',width=15,height=1,command=SEC)
_10.place(x=440,y=640)
_11=tk.Button(window,fg='#FFFFFF',bg='cornflowerblue',text='CLI:门诊部',width=15,height=1,command=CLI)
_11.place(x=440,y=675)

_12=tk.Button(window,fg='#4169E2',text='YOU:又康超市',width=15,height=1,command=YOU)
_12.place(x=580,y=605)
_13=tk.Button(window,fg='#4169E2',text='GOG:GoGo新天地',width=15,height=1,command=GOG)
_13.place(x=580,y=640)
_14=tk.Button(window,fg='#4169E2',text='DOR:宿舍',width=15,height=1,command=DOR)
_14.place(x=580,y=675)

def quit():
    window.destroy()

_11=tk.Button(window,fg='#FFFFFF',bg='lightcoral',text='RETURN MENU',width=22,height=3,command=quit)
_11.place(x=720,y=640)
window.mainloop()
