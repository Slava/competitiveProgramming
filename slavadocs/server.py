import tornado.ioloop
import tornado.web
import tornado.websocket
import logging


class WSHandler(tornado.websocket.WebSocketHandler):
    connections = []
    def open(self):
        print "New connection opened."
        self.write_message(MainHandler.text)
        WSHandler.connections.append(self)

    def on_message(self, message):
        pass

    @staticmethod
    def send_to_clients(message):
        for connection in WSHandler.connections:
            connection.write_message(message)


    def on_close(self):
        print "Connection closed."
        WSHandler.connections.remove(self)



class MainHandler(tornado.web.RequestHandler):
    text = ''

    def get(self):
        self.write('''
<html>
<head>
<script type="text/javascript">
    var ws = new WebSocket("ws://localhost:8888/update");
    ws.onopen = function() {
       // ws.send("Hello, world");
    };
    ws.onmessage = function (evt) {
        document.getElementById('mainblock').innerHTML = evt.data;
    };
</script>
</head>
<body>
    <div id = "mainblock"></div>
</body>
</html>
''')

    def post(self):
        self.set_header("Content-Type", "MainHandler.text/plain")

        method = self.get_argument('method')
        message = self.get_argument('message')

        if method == 'command':
            if message == 'clear':
                MainHandler.text = ''
            else:
               raise Exception('Wrong command: ' + message)

        if method == 'type':
            MainHandler.text += message + '<br>'
        WSHandler.send_to_clients(MainHandler.text)

if __name__ == "__main__":
    logging.getLogger().setLevel('DEBUG')
    application = tornado.web.Application([
        (r"/", MainHandler), (r"/update", WSHandler),
    ], debug=True)
    application.listen(8888)
    tornado.ioloop.IOLoop.instance().start()




