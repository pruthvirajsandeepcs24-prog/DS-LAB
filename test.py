class ABC():
    x=0
    def __init__(self,var):
        ABC.x +=1
        self.var=var
        print("the object values", var)
        print("class variables",ABC.x)


x1=ABC(10)
x2=ABC(20)
x3=ABC(30)
