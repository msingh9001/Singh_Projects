from PIL import Image #Import PIL library
import time
img = Image.new('RGB', (500, 500)) #Create back area box
pixels = img.load() #Load the pixels


def Midpoint(R):
    x = 0
    y = R
    h = 1.25 - R
    dE = 3
    dSE = -2 *(R) + 5

    while y > x:
        if h < 0:
            h += 2*x + 3
            dE = dE + 2
            dSE = dSE + 2
        else:
            h += 2*(x-y) + 5
            dE = dE + 2
            dSE = dSE + 4
            y = y - 1
        x = x + 1
        time.sleep(0.01)
        drawCircle(x,y)
        

def drawCircle(x,y):
    pixels[x+200,y+200] = (255,0,0)
    pixels[x+200,-y+200] = (255,0,0)
    pixels[-x+200,y+200] = (255,0,0)
    pixels[-x+200,-y+200] = (255,0,0)
    pixels[y+200,x+200] = (255,0,0)
    pixels[y+200,-x+200] = (255,0,0)
    pixels[-y+200,x+200] = (255,0,0)
    pixels[-y+200,-x+200] = (255,0,0)



def main():
    R = int(input("Enter Radius "))
    Midpoint(R)
    img.show()

if __name__ == "__main__":
    main()
