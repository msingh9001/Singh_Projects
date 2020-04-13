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
points = []

#read in face vertices
with open('face-vertices.data.txt', 'r') as f:
    reader = csv.reader(f, delimiter=',')
    vertices = list(reader)

#read index
with open('face-index.txt') as csv_file:
    reader = csv.reader(csv_file, delimiter=',')
    points = list(reader)

def projectX(x, z):
    locz = 1 - z
    return (1500 * x /locz) + 500

def projectY(y, z):
    locz = 1 - z
    return (1500 * y/locz) + 350

def draw_pixel(x,y, color):
    pixels[x,y] = (color,0,0)

draw = ImageDraw.Draw(img)

print(points)
for index in points:
    index0 = int(index[0])
    index1 = int(index[1])
    index2 = int(index[2])

    x0 = projectX(float(vertices[index0][0]), float(vertices[index0][2]))
    y0 = projectY(float(vertices[index0][1]), float(vertices[index0][2]))
    x1 = projectX(float(vertices[index1][0]), float(vertices[index1][2]))
    y1 = projectY(float(vertices[index1][1]), float(vertices[index1][2]))
    x2 = projectX(float(vertices[index2][0]), float(vertices[index2][2]))
    y2 = projectY(float(vertices[index2][1]), float(vertices[index2][2]))

    draw_pixel(x0, y0, 255)

img.show()

for index in points:
    index0 = int(index[0])
    index1 = int(index[1])
    index2 = int(index[2])
    
    x0 = projectX(float(vertices[index0][0]), float(vertices[index0][2]))
    y0 = projectY(float(vertices[index0][1]), float(vertices[index0][2]))
    x1 = projectX(float(vertices[index1][0]), float(vertices[index1][2]))
    y1 = projectY(float(vertices[index1][1]), float(vertices[index1][2]))
    x2 = projectX(float(vertices[index2][0]), float(vertices[index2][2]))
    y2 = projectY(float(vertices[index2][1]), float(vertices[index2][2]))
    
    draw.line((x0,y0,x1,y1), fill=255)
    draw.line((x1,y1,x2,y2), fill=255)
    draw.line((x0,y0,x2,y2), fill=255)


img.show()

##    for index in csv_reader:
##
##
##        #
