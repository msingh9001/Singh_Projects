class FirstClass:
    def setdata(self, value1, value2):
        self.data1 = value1
        self.data2 = value2
    def display(self):
        print(self.data1, '\n', self.data2, '\n')

x = FirstClass()

x.setdata("King Arthur", -5)
x.display()

x.data1 = "QQ"
x.data2 = -3
x.display()

x.anothername = "spam"
x.display()
print(x.anothername)
