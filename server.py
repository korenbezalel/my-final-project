import socket
import threading
import queue
from random import randint
#global variables
clients_dict = {}

#entry argument: this function gets server_socket type socket and q which is empty for now
#closing argument: this function handle the connection between the client said and the server side
def client_handler(server_socket, q):
    (client_socket, client_addres) = server_socket.accept()
    print('client made a connection')
    clients_dict[client_socket] = client_addres
    q.put(client_socket)

#this function aims to run the client_handler function 5 times in 5 different threads
def connection_handler(server_socket, q):
    threads = []
    for _ in range(5):
        t = threading.Thread(target=client_handler, args= (server_socket,q))
        t.start()
        threads.append(t)
    for i in threads:
        i.join()

def Random_divader(q):
    n = randint(0,5)
    i = 5
    groupI = []
    groupII = []
    for _ in range(n):
        proupII.append(q.get())
        i-=1
    proupI.append(q.get())
    for _ in range(i):
        groupII.append(q.get())
    return (groupI, groupII)



#main function exciute the code above
def main():

    q = queue.Queue()
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(("192.168.31.11", 50658))
    server_socket.listen()
    print("server in up and running")
    connection_handler(server_socket, q)
    (G1,G2) = Random_divader(q)


if __name__ == '__main__':
    main()







