import psutil

def is_process_interactive(pid):
    try:
        process = psutil.Process(pid)
        # Check if the process has any open file descriptors pointing to a terminal
        for fd in process.open_files() + process.connections():
            if fd.fd == '0':  # Filter out localhost connections
                return True
        return False
    except (psutil.NoSuchProcess, psutil.AccessDenied, psutil.ZombieProcess):
        return False

# Replace 'process_name' with the name of your process
process_name = "brave"  

for proc in psutil.process_iter(['pid', 'name']):
    if process_name.lower() in proc.info['name'].lower():
        pid = proc.info['pid']
        if is_process_interactive(pid):
            print(f"Process {process_name} with PID {pid} is interacting with a text interface.")

# Example usage
if __name__ == "__main__":
    # Example process ID (replace with your actual process ID)
    process_id = 2039

    # Check if the process is prompting for input
    if is_process_interactive(process_id):
        print("Process is prompting for input.")
    else:
        print("Process is not prompting for input.")
