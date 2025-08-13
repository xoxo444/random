import time
import keyboard  # pip install keyboard

print("Press 's' to start, 'p' to pause, 'r' to reset, 'q' to quit")

running = False
start_time = 0
elapsed_time = 0

while True:
    if keyboard.is_pressed('s') and not running:
        start_time = time.time() - elapsed_time
        running = True
        print("Stopwatch started...")
        time.sleep(0.2)  

    elif keyboard.is_pressed('p') and running:
        elapsed_time = time.time() - start_time
        running = False
        print(f"Paused at {elapsed_time:.2f} seconds")
        time.sleep(0.2)

    elif keyboard.is_pressed('r'):
        elapsed_time = 0
        start_time = time.time()
        print("Stopwatch reset to 0.00 seconds")
        time.sleep(0.2)

    elif keyboard.is_pressed('q'):
        print("Exiting stopwatch...")
        break

    if running:
        elapsed_time = time.time() - start_time
        print(f"\rTime: {elapsed_time:.2f} seconds", end="")

    time.sleep(0.05)
