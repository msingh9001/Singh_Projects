import tensorflow as tf
import numpy as np
import matplotlib.pyplot as plt
from tensorflow.keras import datasets, layers, models
from keras.utils import to_categorical
from sklearn.metrics import confusion_matrix

def part1():
    fashion_mnist = tf.keras.datasets.fashion_mnist
    (training_images, training_labels), (testing_images, testing_labels) = fashion_mnist.load_data()
    training_images = training_images.reshape((60000, 28, 28, 1))
    testing_images = testing_images.reshape((10000, 28, 28, 1))
    training_images, testing_images = training_images / 255.0, testing_images / 255.0
    training_labels = to_categorical(training_labels)
    testing_labels = to_categorical(testing_labels)
    myModel = models.Sequential()
    myModel.add(layers.Conv2D(32, (3, 3), activation='relu', input_shape=(28, 28, 1)))
    myModel.add(layers.MaxPooling2D((2, 2)))
    myModel.add(layers.Conv2D(64, (3, 3), activation='relu'))
    myModel.add(layers.MaxPooling2D((2, 2)))
    myModel.add(layers.Conv2D(64, (3, 3), activation='relu'))
    myModel.add(layers.Flatten())
    myModel.add(layers.Dense(64, activation='relu'))
    myModel.add(layers.Dense(10, activation='softmax'))
    myModel.summary()
    myModel.compile(optimizer='adam', loss='categorical_crossentropy', metrics=['accuracy'])
    myModel.fit(training_images, training_labels, epochs = 10, batch_size = 64)
    test_loss, test_acc = myModel.evaluate(testing_images, testing_labels)
    print(test_acc)
    testMatrix = myModel.predict(testing_images)
    testHat = np.argmax(testMatrix, axis=1)
    labels = np.argmax(testing_labels, axis=1)
    confusionMatrix = confusion_matrix(labels, testHat)
    print(confusionMatrix)

def part2():
    fashion_mnist = tf.keras.datasets.fashion_mnist
    (training_images, training_labels), (testing_images, testing_labels) = fashion_mnist.load_data()

    training_images, testing_images = training_images.astype('float32') / 255.0, testing_images.astype('float32') / 255.0
    P = [10, 50, 200]
    for p in P:
        myModel = models.Sequential()
        myModel.add(layers.Flatten(input_shape=(28,28)))
        myModel.add(layers.Dense(p))
        myModel.add(layers.Dense(1568, activation="relu"))
        myModel.add(layers.Dense(784))
        myModel.add(layers.Reshape((28,28), input_shape=(784,)))
        myModel.compile(optimizer='adam', loss='mse', metrics=['accuracy'])
        myModel.fit(training_images, training_images, epochs = 10, batch_size = 64, verbose = 0, shuffle = True, validation_data = (training_images, training_images))
        prediction = myModel.predict(testing_images)
        plt.figure(figsize=(40, 4))
        for x in range(10):
            if p is 10:
                z = plt.subplot(3, 20, x + 1)
                plt.imshow(testing_images[x].reshape(28, 28))
                plt.gray()
            z = plt.subplot(3, 20, 2*20+ x + 1)
            plt.imshow(prediction[x].reshape(28,28))
            plt.gray()
        plt.show()

        
part1()
part2()
