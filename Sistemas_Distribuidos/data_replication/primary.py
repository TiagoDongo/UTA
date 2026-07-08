import json
import requests

REPLICA_IP = input("Enter your classmate's (Replica) IP address: ")
REPLICA_URL = f"http://{REPLICA_IP}:8080"

print("\n..... Primary Node Active ....")
while True:
  key = input("\nEnter data key (or 'exit' to quit()): ")
  if key.lower() == 'exit':
    break
  value = input("Enter data value: ")

  payload = {"key": key, "value": value}

  with open("primary_storage.txt", "a") as f:
    f.write(f"{key}: {value}\n")
  print("[LOCAL] Saved to primary_storage.txt")

  
  print(f"[REPLICATING] Sendig to {REPLICA_URL}...")
  try:
    response = requests.post(REPLICA_URL, json=payload, timeout=5)
    if response.status_code == 200:
      print(f"[SUCCESS] Replica acknowledged: {response.json()['msg']}")
    else:
      print(f"[FAILURE] Replica returned status code: {response.status_code}")
  except requests.exceptions.RequestException as e:
      print(f"[ERROR] Could not connect to Replica. Is the IP correct? Error: {e}")