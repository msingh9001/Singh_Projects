
# Behnam Dezfouli
#  CSEN, Santa Clara University

# This program implements a simple smtp mail client to send an email to a local smtp server

# Note:
# Run a local smtp mail server using the following command before running this code:
# python -m smtpd -c DebuggingServer -n localhost:6000


from socket import *
import ssl


# Choose a mail server
mailserver = 'localhost'


# Create socket called clientSocket and establish a TCP connection with mailserver
# STUDENT WORK
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect(('localhost', 6000))

# Port number may change according to the mail server
# STUDENT WORK
#clientPort = 9001
#clientSocket.bind(("", clientPort))

recv = clientSocket.recv(1024).decode()
print('..........0',recv)
if recv[:3] != '220':
    print('220 reply not received from server.')


# Send HELO command along with the server address
# STUDENT WORK
clientSocket.send('HELO <localhost>\r\n'.encode())
recv = clientSocket.recv(1024).decode()
print('........1',recv)
#if recv[:3] != '250':
#    print('250 reply not received from server.')

# Send MAIL FROM command and print server response
# STUDENT WORK
clientSocket.send('MAIL FROM:<reverse_path>\r\n'.encode())
recv = clientSocket.recv(1024).decode()
print('........1',recv)

# Send RCPT TO command and print server response
# STUDENT WORK
clientSocket.send('RCPT TO:<forward_path>\r\n'.encode())
recv = clientSocket.recv(1024).decode()
print('........1',recv)

# Send DATA command and print server response
# STUDENT WORK
clientSocket.send('DATA\r\n'.encode())
recv = clientSocket.recv(1024).decode()
print('........1',recv)

# Send message data.
# STUDENT WORK
clientSocket.send('SUBJECT: Greetings to you!'.encode())
#recv = clientSocket.recv(1024).decode()
#print('........1',recv)

# Message to send
# STUDENT WORK
clientSocket.send('\nThis is line 1.'.encode())
#recv = clientSocket.recv(1024).decode()
#print('........1',recv)

# Message ends with a single period
# STUDENT WORK
clientSocket.send('\nThis is line 2.\r\n.\r\n'.encode())
recv = clientSocket.recv(1024).decode()
print('........1',recv)

#clientSocket.send('\r\n.\r\n'.encode())
#recv = clientSocket.recv(1024).decode()
#print('........1',recv)

# Send QUIT command and get server response
# STUDENT WORK
clientSocket.send('QUIT\r\n'.encode())
recv = clientSocket.recv(1024).decode()
print(recv)
clientSocket.close()
