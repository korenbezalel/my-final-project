import socket
import threading
import queue
from random import randint

# global variables
clients_dict = {}


# entry argument: this function rev server_socket type socket and q which is empty for now
# closing argument: this function handle the connection between the client said and the server side
def client_handler(server_socket, q):
    (client_socket, client_address) = server_socket.accept()
    print('client made a connection')
    clients_dict[client_socket] = {}
    clients_dict[client_socket]['address'] = client_address
    data = int(server_socket.recv(1024).decode())
    clients_dict[client_socket]['port'] = data
    print(clients_dict[client_socket]['port'])
    q.put(client_socket)


# this function aims to run the client_handler function 5 times in 5 different threads
# in the next iteration this function will run in different process depending on the number of rooms
def connection_handler(server_socket, q):
    threads = []
    for _ in range(5):
        t = threading.Thread(target=client_handler, args=(server_socket, q))
        t.start()
        threads.append(t)
    for i in threads:
        i.join()


def Random_divader(q):
    n = randint(0, 5)
    i = 5
    groupI = []
    groupII = []
    for _ in range(n):
        proupII.append(q.get())
        i -= 1
    proupI.append(q.get())
    for _ in range(i):
        groupII.append(q.get())
    return (groupI, groupII)


def rule_sender(rule, group):
    for i in range(len(group)):
        group[i].sendall(rule.encode("UTF-8"))


def P2P_handeler(client1, client2):
    ports = []
    ports.append(clients_dict[client1]['port'])
    ports.append(clients_dict[client2]['port'])
    C1_address, C1_port = clients_dict[client1]['address'], ports[0]
    C2_address, C2_port = clients_dict[client2]['address'], ports[1]

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client1_socket:
        client1_socket.connect((C1_address[0], int(C1_port)))
        client1_socket.sendall('{}:{} {}'.format(C1_address[0], C1_port, ports[1]).encode())

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client2_socket:
        client2_socket.connect((C2_address[0], int(C2_port)))
        client2_socket.sendall('{}:{} {}'.format(C2_address[0], C2_port, ports[0]).encode())


# main function execute the code above
def main():
    q = queue.Queue()
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(("192.168.31.11", 50658))
    server_socket.listen()
    print("server in up and running")
    connection_handler(server_socket, q)
    (G1, G2) = Random_divader(q)
    # multi-threading send to clients their rule
    t1 = threading.Thread(target=rule_sender, args=(G1, 1))
    t2 = threading.Thread(target=rule_sender, args=(G2, 2))
    t1.start()
    t2.start()
    t1.join()
    t2.join()


if __name__ == '__main__':
    main()
