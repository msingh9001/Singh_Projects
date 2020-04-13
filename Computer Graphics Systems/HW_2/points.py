# object representation 

from PIL import Image, ImageDraw
import math
import csv
import array as arr



img = Image.new('RGB', (1000, 1000))
pixels = img.load()
# this list hold all vertices
# you can use append() to add all x, y, z
# into it. the format could be like this:
# [[x1, y1, z1], [x2, y2, z2],......]
vertices = []

#read in face vertices
with open('face-vertices.data.txt', 'r') as f:
    reader = csv.reader(f, delimiter=',')
    vertices = list(reader)
#print(vertices)

def projectX(x, z):
    locz = 1 - z
    return (1500 * x /locz) + 500

def projectY(y, z):
    locz = 1 - z
    return (1500 * y/locz)

def draw_pixel(x,y, color):
    pixels[x,y] = (color,0,0)
    

for index in vertices:
    print(float(index[0]), float(index[1]),float(index[2]))

    draw_pixel(projectX(float(index[0]), float(index[2])), projectY(float(index[1]), float(index[2])), 255)

img.show()
