import asyncio
import websockets
import socket


class Server:
    def __init__(self):
        self.ws_server = websockets.serve(self.handler, "127.0.0.1", 8180)
        

    async def handler(self, websocket):
        self.sock_server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock_server.bind(("127.0.0.1", 8181))
        self.sock_server.listen()

        received_data = await websocket.recv()
        print("[-] Client2's requenst recieved") 

        client, _ = self.sock_server.accept()
        request = client.recv(1024)
        print("[-]client1's requenst recieved")
        print(b"Sended: "+ request)
        await websocket.send(request.decode())

    def run(self):
        asyncio.get_event_loop().run_until_complete(self.ws_server)
        asyncio.get_event_loop().run_forever()


if __name__ == "__main__":
    server = Server()
    server.run()
