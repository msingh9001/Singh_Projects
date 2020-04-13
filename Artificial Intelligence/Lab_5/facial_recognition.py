#
#  facial_recognition.py
#  Lab_5
#
#  Created by Mandeep Singh on 11/8/19.
#  Copyright © 2019 Mandeep Singh. All rights reserved.
#
#cv2.imshow('img', training_set[2]); cv2.waitKey(0); cv2.destroyAllWindows()
import cv2
import numpy as np

K=[1,2,3,6,10,20,30,50]

folders = ['att_faces_10/s1',
           'att_faces_10/s2',
           'att_faces_10/s3',
           'att_faces_10/s4',
           'att_faces_10/s5',
           'att_faces_10/s6',
           'att_faces_10/s7',
           'att_faces_10/s8',
           'att_faces_10/s9',
           'att_faces_10/s10']

images = ['/1.pgm','/2.pgm','/3.pgm','/4.pgm','/5.pgm','/6.pgm','/7.pgm','/8.pgm','/9.pgm','/10.pgm']

read_images = []
folder_counter = 0
while folder_counter < 10:
    file_counter = 0
    while file_counter < 10:
        img = cv2.imread(folders[folder_counter] + images[file_counter])
        read_images.append(img)
        file_counter += 1
    folder_counter += 1

training_images = []
set_counter = 0
file_counter = 0
x = [1,3,4,5,7,9]
while file_counter < 10:
    count = 0
    while count < 6:
        training_images.append(read_images[x[count]-1])
        count += 1
    file_counter += 1
    if file_counter % 6 == 0:
        x[0]+=10
        x[1]+=10
        x[2]+=10
        x[3]+=10
        x[4]+=10
        x[5]+=10

training_images = np.array(training_images)
training_array = np.array(np.transpose([np.array(image).flatten() for image in training_images[:,:,:,0]]))
mean = np.mean(training_array, axis = 1)
mean = np.array(mean).reshape(10304, 1)
U, S, Vh = np.linalg.svd(training_array, full_matrices = True)
print("U Shape: ", U.shape)
percentageCorrect = {1:0,2:0,3:0,6:0,10:0,20:0,30:0,50:0}

testing_images = []
file_counter = 0
x = [2,6,8,10]
while file_counter < 10:
    count = 0
    while count < 4:
        testing_images.append(read_images[x[count]-1])
        count += 1
    file_counter += 1
    if file_counter % 4 == 0:
        x[0]+=10
        x[1]+=10
        x[2]+=10
        x[3]+=10

for num in range(1,10):
    testing_images = np.array(testing_images)
    testing_array = np.array([np.array(image).reshape(10304, 1) for image in testing_images[:,:,:,0]])
    testing_array = testing_array - mean
    for kval in K:
        sol = np.transpose(U[:,:kval])
        training_model = np.dot(sol, training_array)

        for test in testing_array:
            testing_projection = np.dot(sol, test)
            tile = np.tile(testing_projection,(1,60))

            dot = training_model - tile
            res = np.linalg.norm(dot, axis = 0)
            minimum = np.argmin(res,axis=0)
            k_nearest_neighbors = np.argsort(res)
            minimum_indices = k_nearest_neighbors.argsort()
            
            if (int(minimum/6)+1) == num:
                percentageCorrect[kval]+=1


for x in percentageCorrect:
    percentageCorrect[x] = percentageCorrect[x]/40
print("Percentage Correct (K-Rank,Percentage):", percentageCorrect)
