
# Behnam Dezfouli
# CSEN, Santa Clara University

# This program implements a simple web server that serves html and jpg files

# Input arguments:
# argv[1]: Sever's port number


from socket import *  # Import socket module
import datetime       # Import datetime module
import sys            # To terminate the program


if __name__ == "__main__":

    # check if port number is provided
#    if len(sys.argv) != 2:
#        print 'Usage: python %s <PortNumber>' % (sys.argv[0])
#        sys.exit()

    
    # STUDENT WORK
    serverSocket = socket(AF_INET, SOCK_STREAM)
    serverSocket.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
    serverPort = int(sys.argv[1])
    serverSocket.bind(("", serverPort))
    serverSocket.listen(1)

    # Server should be up and running and listening to the incoming connections
    while True:
        print('The server is ready to respond to incoming requests...')


        # STUDENT WORK
        connectionSocket, addr = serverSocket.accept()
        message = connectionSocket.recv(1024)
        print(message)
        
        try:
            # STUDENT WORK
            file_name = message.split('/')
            print(file_name)
            temp = file_name[1].split(' ')
            print(temp)
            file = str(temp[0])
            file_extension = temp[0].split('.')
            print(file_extension)
            if (file_extension[1] == 'html'):
                temp = 0
                response_headers = 'Content-Type: text/html; encoding=utf8'
            elif (file_extension[1] == 'jpg'):
                temp = 1
                response_headers =  'Content-Type: image/jpeg; encoding=utf8'
            else:
                print('Invalid file type, we only support html and jpg!')
                break


            # STUDENT WORK
            t = str(datetime.datetime.now())
            if(temp == 0):
                f =  open(file, 'rb')
                outputdata = f.read()
                header = 'HTTP/1.1 200 OK \nDate: ' + t + '\nServer: Shreks Dank Swamp\n' + response_headers + '\nContent Length: ' + str(len(outputdata)-1) +'\n\n'
                header += outputdata
            elif(temp == 1):
                f =  open(file, 'rb')
                outputdata = f.read()
                header = 'HTTP/1.1 200 OK \nDate: ' + t + '\nServer: Shreks Dank Swamp\n' + response_headers + '\nContent Length: ' + str(len(outputdata)-1) +'\n\n'
                header += outputdata
                    
            print(header)
            connectionSocket.send(header)
            connectionSocket.close()
        #Raised when an I/O operation (such as a print statement, the built-in open() function or a method of a file object) fails for an I/O-related reason, e.g., "file not found" or "disk full"
        except IOError:
            # STUDENT WORK
            print('404 NOT FOUND')
            header =  'HTTP/1.1 200 OK \nDate: ' + t + '\nServer: Shreks Dank Swamp\n' + 'Content-Type: text/plain; encoding=utf8' + '\nContent Length: ' + str(len(outputdata)-1) +'\n\n'
            errorMessage = '404 NOT FOUND'
            header += errorMessage
            connectionSocket.send(header)
            connectionSocket.close()
