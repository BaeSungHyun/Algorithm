from http.server import HTTPServer, BaseHTTPRequestHandler
import http.client


#  SERVER
class SimpleHTTPRequestHandler(BaseHTTPRequestHandler):
    def do_GET(self):
        self.send_response(200)
        self.send_header("connection", "close")
        self.end_headers()
        self.wfile.write(b"Hello world!")


httpd = HTTPServer(('localhost', 8000), SimpleHTTPRequestHandler)
httpd.serve_forever()


# #  CLIENT
# conn = http.client.HTTPConnection("google.com")
# conn.request("GET", "/")
# response = conn.getresponse()
# print(f"Status: {response.status}, Reason: {response.reason}")
# data = response.read()
# print(data.decode("utf-8"))
# conn.close()