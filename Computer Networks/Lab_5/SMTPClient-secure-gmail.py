
# Behnam Dezfouli
#  CSEN, Santa Clara University

# This program implements a simple smtp mail client to send an email to a local smtp server
# the program runs the ping command, and emails the result using smtp.gmail.com

# NOTE: Do not forget to allow login from less secure apps in your gmail account. Otherwise gmail will complain about username and password.


import smtplib, ssl
import subprocess

port = 465  # For SSL
email_address = str(input("Please enter your email address: "))
password = str(input("Please enter your password: "))
receiver_email = str(input("Please enter receiver's email address: "))

# ping google.com and save the result
# STUDENT WORK
ping_response = subprocess.Popen(["ping", "-c", "3",
                                  "google.com"], stdout=subprocess.PIPE).stdout.read()
print(ping_response)

print( '\nNow contacting the mail server...')
# STUDENT WORK
server = smtplib.SMTP_SSL('smtp.gmail.com', 465)
server.ehlo()
server.login(email_address, password)

print( '\nSending email...')
# STUDENT WORK
message = 'Subject: Server ping result!\n\nI have pinged google.com and the result is attached to this email:\n\n' + str(ping_response)
print(message)

server.sendmail(email_address, receiver_email, message)

