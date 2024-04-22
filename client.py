import socket
import time

def find_available_port():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind(('', 0))  # Bind to any available port on localhost
        _, port = s.getsockname()  # Get the port assigned by the OS
    return port


def P2P_execute(peer_ip, peer_port):
    print('executing peer to peer private connection')


def main():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect(('192.168.31.11', 50658))
    print('Connected')

    time.sleep(1)#add because of trys that indicate server over load without sleep
    # sending available port to server
    port = find_available_port()
    client_socket.sendall(port.encode())

    # Receive the rule from the server
    rule = client_socket.recv(1024).decode("UTF-8")
    print('Received rule:', rule)


if __name__ == "__main__":
    main()
