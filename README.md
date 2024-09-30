# BGP Exploit

This exploit targets a BGP (Border Gateway Protocol) implementation that allows unauthenticated remote code execution. The attacker exploits a vulnerability in the BGP UPDATE message processing code to inject malicious payloads.

## Vulnerability

The BGP implementation is vulnerable to remote code execution because it does not properly validate the BGP UPDATE messages received from neighboring routers. An attacker can craft malicious BGP UPDATE messages that contain arbitrary payloads, which can be executed on the target system.

## Exploit Details

The exploit consists of two main components:

1. A Python script that constructs malicious BGP UPDATE messages and sends them to the target BGP router.

2. A C program that is injected into the BGP UPDATE messages and executes arbitrary commands on the target system.

### Python Script

The Python script `bgp_exploit.py` is responsible for constructing the malicious BGP UPDATE messages. It imports the necessary libraries, defines the necessary constants and functions, and then sends the BGP messages to the target router.

The script performs the following steps:

1. Compiles the C code into a binary executable.
2. Reads the binary data of the compiled program.
3. Generates a random 128-bit key for encryption.
4. Encrypts the binary data using AES encryption in Galois/Counter Mode (GCM).
5. Applies columnar transposition cipher to the encrypted payload.
6. Combines the nonce, ciphertext, and tag into a single payload.
7. Base64 encodes the payload.
8. Compresses the payload using zlib compression.
9. Sends the polymorphic payload in the BGP UPDATE message to the target router.

### C Program

The C program `wiper.c` is the payload that is injected into the BGP UPDATE messages. It performs the following actions:

1. Deletes the contents of target system directories and files.
2. Overwrites and deletes files in the target system directories.
3. Corrupts system partitions.
4. Forces a system reboot.

### Execution

To execute the exploit:

1. Install the necessary dependencies (`scapy`, `pycryptodome`, `zlib`).
2. Modify the `target_ip`, `target_asn`, `attacker_ip`, and `attacker_asn` variables in the Python script to match the target BGP router and attacker information.
3. Run the Python script to initiate the BGP hijacking attack.
4. The script will send BGP OPEN, UPDATE, and KEEPALIVE messages to the target router, injecting the malicious payload into the UPDATE messages.
5. The target router will execute the C code injected into the UPDATE messages, wiping out the target system and rebooting.

## Disclaimer

This exploit is for educational and ethical testing purposes only. The author is not responsible for any misuse or damage caused by the use of this script. Use responsibly and obtain proper authorization before performing any exploitation attempts.
