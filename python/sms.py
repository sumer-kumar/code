from sms4 import send, nonblocking_send

# result is a json server response. see docs for details
result = send('+917530885187', 'The server is down!')
print(result)

# multiple numbers are supported and you can pass token via
# 3rd argument to send function
# result = send(['+123456798', '+123456799'], 'The server is down!', 'YOUR_TOKEN')
# print(result)

# Will be send in another thread, no result returned
# nonblocking_send('+123456798', 'The server is down!')