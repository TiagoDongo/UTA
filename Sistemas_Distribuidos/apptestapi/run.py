import json
import subprocess
import sys
import os

# Carregar comandos do run.json
with open('run.json', 'r') as f:
    config = json.load(f)

commands = config['commands']

# Executar comandos em paralelo
processes = []
for cmd in commands:
    print(f"Starting: {cmd}")
    # No Windows, usar shell=True para comandos complexos
    proc = subprocess.Popen(cmd, shell=True, cwd=os.getcwd())
    processes.append(proc)

print("Both servers are running. Press Ctrl+C to stop.")

try:
    # Aguardar todos os processos
    for proc in processes:
        proc.wait()
except KeyboardInterrupt:
    print("\nStopping servers...")
    for proc in processes:
        proc.terminate()
    sys.exit(0)