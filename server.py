import socket
import threading
import queue
#global variables
dict = {}

#entry argument: this function gets server_socket type socket and q which is enmpty for now
#closing argument: this function hundle the connection between the client said and the server side
def client_handler(server_socket, q):
    (client_socket, client_addres) = server_socket.accept()
    dict[client_socket] = client_addres
    q.put(client_socket)

#this function aims to run the client_handler function 5 times in 5 different threads
def connection_hendler():
    threads = []
    for _ in range(5):
        t = threading.Thread(target=client_handler)
        t.start()
        threads.append(t)
    for i in threads:
        i.join()

#main function axicute the code above
def main():
    q = queue.Queue()
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(("127.0.0.1", 50658))
    server_socket.listen()
    print("server in up and running")
    connection_hendler()


if __name__ == '__main__':
    main()







