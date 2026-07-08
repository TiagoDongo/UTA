import json
from http.server import BaseHTTPRequestHandler, HTTPServer

PORT = 5000

class ReplicaHandler(BaseHTTPRequestHandler):
  def do_POST(self):
    content_length = int(self.headers['Content-Length'])
    post_data = self.rfile.read(content_length)

    data = json.loads(post_data.decode('utf-8'))
    print(f"\n[RECEIVER] Received data for replication: {data}")

    with open("replicated_storage.txt", "a") as f:
      f.write(f"{data['key']}: {data['value']}\n")

    self.send_response(200)
    self.send_header('Content-type', 'application/json')
    self.end_headers()
    self.wfile.write(b'{"status": "success", "msg": "Data replicated successfully"}')

def run():
  server_address = ('', PORT)
  httpd = HTTPServer(server_address, ReplicaHandler)
  print(f"Replica server is running on port {PORT}...")
  print("Waiting data from primary...")
  httpd.serve_forever()

if __name__ == '__main__':
  run()