# lab1
Lab 1: Secure Button using challenge-response authentication and SHA-256 HMAC.

## Dependencies
- Crypto Library at https://rweather.github.io/arduinolibs/crypto.html
- RF24

## Communication protocol
The entire protocol restarts if any communication times out.

### Client
1. Send request (0xFF)
2. Listen for challenge (timeout = 250ms)
3. Get challenge (char[32] or byte[32]); reject if challenge == 0x0...0 or 0xF...F
4. Compute response = HMAC(challenge, password)
5. Send response
6. Wait for response (timeout = 250ms)
7. If response is pass (0xFF), wait for 500ms, then restart. If the response is fail (0x00), restart immediately.

### Server
1. Listen for request (0xFF)
2. Generate challenge (char[32]) on request receipt.
3. Send challenge.
4. Listen for response (timeout = 250ms)
5. Check: response = HMAC(challenge, password)?
	- If no, send fail (0x00); go back to beginning
6. Send pass (0xFF)
7. Turn on the light if not already on; set the new expiration time to +1s

### Implementation
server.cpp and client.cpp are written as finite state machines following the steps given above (i.e. step 1 is given by state 1).