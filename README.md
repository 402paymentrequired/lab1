# lab1
Lab 1: Secure HMAC Button

## Dependencies:
- Crypto Library at https://rweather.github.io/arduinolibs/crypto.html
- RF24

## Communication protocol:

### Client
1. Send request (0xF...F)
2. Listen for request (timeout = 250ms; goto 1)
3. Get challenge
4. Compute response = H(challenge XOR H(key))
5. Send response
6. Wait for response (timeout = 250ms; goto 1).
7. If response is pass (0xF...F), wait for 500ms. Else, goto 1 without waiting.
8. Goto 1

### Server
1. Listen for request (0xF...F)
2. Generate challenge on request receipt.
3. Send challenge.
4. Listen for response (timeout = 250ms; goto 1)
5. Check: response = H(challenge XOR H(password))?
	- If no, send (0x0...0); goto 1
6. Send pass (0xF...F)
7. Turn on the light if not already on; set the new expiration time to +1s
