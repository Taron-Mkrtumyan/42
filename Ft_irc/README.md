_This project has been created as part of the 42 curriculum by gkankia, tmkrtumy._

> Powered by a deep appreciation for 1988.

# 🏛️ Description
This project is a custom Internet Relay Chat (IRC) server built in C++98 and tested with real IRC clients to make sure everything works just like the classics.

**IRC** is a protocol for real-time text messaging between computers, created in **1988**—back when 640K of memory seemed like plenty and "the cloud" was still just weather. It is mainly used for group chats in rooms called **channels**, while also supporting direct messages between two users and various client commands.

## 📐 Project Requirements
- Built strictly in **C++98**—no `auto`, no `nullptr`, just classic object-oriented design.
- Handles multiple clients at the same time using non-blocking I/O without ever freezing or blocking.
- Uses a single `poll()` to manage all network events: reading, writing, and accepting new connections.
- Connects smoothly with our reference IRC client (**Irssi**) without encountering errors.
- All communication runs over **TCP/IP**.
- Supports the core features of a standard IRC server:
  - Clients can authenticate, set a nickname, register a username, join channels, and send or receive private messages.
  - Any message sent to a channel is immediately forwarded to everyone else in that channel.
  - Supports both **channel operators** and **regular users**, along with all mandatory operator commands.

# 📜 IRC Commands
Here are the commands supported by the server:
- **PASS**: Sets the connection password required before the server lets you in.
- **NICK**: Gives you a nickname or updates your current one when you feel like a fresh start.
- **USER**: Sent at the start of a connection to set your username, hostname, and real name (fact-checking not included).
- **JOIN**: Requests to enter a specific channel and start reading its messages.
- **PRIVMSG**: Sends a private message to another user or posts a message to a channel.
- **KICK**: Ejects a user from a channel when they have overstayed their welcome *(operator only)*.
- **INVITE**: Invites a user into a channel *(operator only)*.
- **TOPIC**: Views or updates the current topic of a channel *(restricted to operators when `+t` is active)*.
- **MODE**: Changes channel modes *(operator only)*:
  - `i`: Set/remove invite-only channel
  - `t`: Set/remove topic restriction to channel operators
  - `k`: Set/remove the channel key (password)
  - `o`: Give/take channel operator privilege
  - `l`: Set/remove the user limit for the channel
- **QUIT**: Ends your session and leaves a farewell message behind.

# 🤖 HelperBot (Bonus)
The server comes with a resident bot named **HelperBot** (HelperBot!helper@127.0.0.1). You can message it directly with PRIVMSG HelperBot <command> or invite it into a channel (INVITE HelperBot #channel) so everyone can join in.

Available bot commands:
- **!help**: Lists all available bot commands.
- **!ping**: Checks if the bot is still awake.
- **!rand**: Generates a random number.
- **!date**: Prints the current server date and time, for terminal dwellers who haven't seen the sun today.
- **!coin**: Flips a coin to settle difficult engineering debates.
- **!8ball**: Consults the Magic 8-Ball for questionable life advice.
🤖 HelperBot (Bonus)
The server comes with a resident bot named HelperBot (HelperBot!helper@127.0.0.1). You can message it directly with PRIVMSG HelperBot <command> or invite it into a channel (INVITE HelperBot #channel) so everyone can join in.

Available bot commands:
!help: Lists all available bot commands.
!ping: Checks if the bot is still awake.
!rand: Generates a random number.
!date: Prints the current server date and time, for terminal dwellers who haven't seen the sun today.
!coin: Flips a coin to settle difficult engineering debates.
!8ball: Consults the Magic 8-Ball for questionable life advice.

# 🔌 Instructions
To compile the program:
```bash
make
```

To start the server:
```bash
./ircserv <port> <password>
```
- **port**: The port number the server will listen on for incoming connections.
- **password**: The connection password required from any client trying to join.

To connect using our reference client (**Irssi**):
```bash
irssi -c 127.0.0.1 -p <port> -w <password>
```

To connect directly from your terminal, you can also use `nc`:
```bash
nc -C <IP ADDRESS> <PORT>
```
- **IP ADDRESS**: The host's IP address.
- **PORT**: The port the server is listening on.

# 🧪 Testing with Netcat
Once connected via `nc` (use `nc -C 127.0.0.1 <port>` so pressing Enter sends the proper `\r\n` line endings), type these commands in order to register and start chatting:

```irc
PASS your_server_password
NICK neo
USER neo 0 * :Thomas Anderson
JOIN #matrix
PRIVMSG #matrix :Hello, world!
PRIVMSG trinity :Follow the white rabbit.
```

- **Authentication & Registration:** `PASS`, `NICK`, and `USER` must be sent first before the server welcomes you.
- **Channel Chat:** `JOIN #matrix` enters the channel, and `PRIVMSG #matrix :...` broadcasts your message to everyone inside.
- **Direct Message:** `PRIVMSG <nickname> :...` sends a private message directly to another online user.

# 📚 Resources
- [What is a Socket?](https://www.tutorialspoint.com/unix_sockets/what_is_socket.htm)
- [Unix Socket - Network Addresses](https://www.tutorialspoint.com/unix_sockets/network_addresses.htm)
- [Unix Socket - Core Functions](https://www.tutorialspoint.com/unix_sockets/socket_core_functions.htm)
- [Beej's Guide to Network Programming](https://beej.us/guide/bgnet/html/) *(a timeless classic)*
- [RFC 1459 — Internet Relay Chat Protocol](https://datatracker.ietf.org/doc/html/rfc1459)
- [RFC 2810 — Internet Relay Chat: Architecture](https://datatracker.ietf.org/doc/html/rfc2810)
- [RFC 2811 — Internet Relay Chat: Channel Management](https://datatracker.ietf.org/doc/html/rfc2811)
- [RFC 2812 — Internet Relay Chat: Client Protocol](https://datatracker.ietf.org/doc/html/rfc2812)
- [RFC 2813 — Internet Relay Chat: Server Protocol](https://datatracker.ietf.org/doc/html/rfc2813)

## 🤖 AI Usage
AI was used mostly as a rubber duck—helping make sense of 1988 RFC rules, write a Python script to open 10+ terminals at once for stress testing, and polish this README. All actual C++98 server code was still written the old-fashioned way: by humans.